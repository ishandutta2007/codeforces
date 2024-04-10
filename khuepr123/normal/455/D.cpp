
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

// lethal option

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pf push_front
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int blk = 317;
const int maxN = 317 * 317;
const ll oo = 1e18 + 7;
int n, a[maxN];
int ans = 0;
int theoldhag;

deque<int> dq[blk];
int cnt[blk][maxN];

void encode(int &num){
    num = (num + ans - 1); num %= theoldhag;
}

int fr(deque<int> &ss){
    int fk = ss.front(); ss.pop_front();
    return fk;
}

int bk(deque<int> &ss){
    int fk = ss.back(); ss.pop_back();
    return fk;
}

int tp(stack<int> &ss){
    int fk = ss.top(); ss.pop(); return fk;
}

int k;
int arr[blk];

void solveblk(int pos, int l, int r){
    for1(i, 0, blk - 1) arr[i] = fr(dq[pos]);
    for2(i, r - 1, l) swap(arr[i], arr[i + 1]);
    for1(i, 0, blk - 1) dq[pos].pb(arr[i]);
}

void solve(int pos, int l, int r){
    if(l == 0 && r == blk - 1){
        ans += cnt[pos][k]; return;
    }
    deque<int> dumb = dq[pos];
    for1(i, 0, blk - 1) arr[i] = fr(dumb);
    for1(i, l, r) ans += (arr[i] == k);
}

int l, r, z;
void prt(){
    // deque<int> dumb = dq[0]; for1(i, 0, 6) cout << fr(dumb) << " "; cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(cnt, 0, sizeof(cnt));
    memset(a, 0, sizeof(a));
    cin >> n; theoldhag = n;
    for1(i, 0, n - 1){
        cin >> a[i];
        --a[i];
    }
    n = maxN;
    for1(i, 0, n - 1){
        dq[i / blk].pb(a[i]);
        cnt[i / blk][a[i]]++;
    }
    prt();
    int o; cin >> o; while(o--){
        cin >> z >> l >> r; encode(l); encode(r);
        if(l > r) swap(l, r);
        if(z == 2){
            cin >> k; encode(k);
            ans = 0;
            int pos = l / blk; l %= blk;
            int targ = r / blk; r %= blk;
            while(pos != targ){
                solve(pos, l, blk - 1);
                ++pos; l = 0;
            }
            solve(targ, l, r);
            cout << ans << endl;
        }
        else{
            int pos = r / blk;
            int targ = l / blk;
            if(pos != targ){
                solveblk(pos, 0, r % blk);
                k = fr(dq[pos]);
                cnt[pos][k]--;
                while(pos != targ){
                    pos--;
                    int num = bk(dq[pos]);
                    dq[pos + 1].pf(num);
                    cnt[pos + 1][num]++;
                    cnt[pos][num]--;
                }
                dq[targ].pb(k);
                cnt[targ][k]++;
                solveblk(targ, l % blk, blk - 1);
            }
            else{
                solveblk(l / blk, l % blk, r % blk);
            }
        }
        prt();
    }
}