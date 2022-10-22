/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
const int lim = 1e6;

int dp[lim + 5];
map<int, int> prm;

bool falk = 0;

int solve(int i){
    if(i <= lim) return dp[i];
    bitset<32> cnt;
    for1(j, 1, 30){
        int nx = (i >> j) | (i & ((1 << j) - 1));
        if(nx == i) continue;
        cnt[solve(nx)] = 1;
    }
    for1(j, 0, 30){
        if(!cnt[j]) return j;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> x;
        for1(i, 2, maxN){
            y = 0;
            while((x % i) == 0){
                x /= i;
                ++y;
            }
            if(y) prm[i] |= (1 << y);
        }
        if(x > 1) prm[x] |= 2;
    }
    dp[1] = 0;
    dp[0] = 0;
    for1(i, 2, lim){
        bitset<22> cnt;
        for1(j, 1, 21){
            int nx = (i >> j) | (i & ((1 << j) - 1));
            if(nx == i) continue;
            cnt[dp[nx]] = 1;
        }
        for1(j, 0, 21){
            if(!cnt[j]){
                dp[i] = j; break;
            }
        }
    }
    falk = 1;
    int ans = 0;
    for(ii child : prm){
        ans ^= solve(child.se);
    }
    if(!ans) cout << "Arpa";
    else cout << "Mojtaba";
    cout << endl;
}