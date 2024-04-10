/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option
 
#include<bits/stdc++.h>
using namespace std;
 
#define all(flg) flg.begin(), flg.end()
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const int mod = 1e9 + 7;
const int maxN = 1000005;
const int blk = 710;
int n, a[maxN];
int x, y, z, k;
 
vector<int> vc[maxN];
int arr[blk][blk];
int adder[maxN];
int m;
 
void adblock(int id, int val, int le, int ri){
    vc[id].clear();
    for1(i, le, ri) arr[id][i] += val;
    for1(i, 0, blk - 1){
        arr[id][i] += adder[id];
        arr[id][i] = min(arr[id][i], mod);
        vc[id].pb(arr[id][i]);
    }
    adder[id] = 0;
    sort(all(vc[id]));
}
 
signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> n >> o;
    for1(i, 0, n - 1) cin >> a[i];
    while(n % blk){
        a[n++] = mod;
    }
    m = n / blk;
    for1(i, 0, m - 1){
        for1(j, 0, blk - 1) arr[i][j] = a[i * blk + j];
        adblock(i, 0, 1, 0);
    }
 
    while(o--){
        cin >> z;
        int l = mod;
        int r = 0;
        if(z == 2){ cin >> y;
            for1(i, 0, m - 1){
                if(binary_search(all(vc[i]), y - adder[i])){
                    r = max(r, i);
                    l = min(l, i);
                }
            }
            if(r < l) cout << "-1\n";
            else{
                for1(i, 0, blk - 1){
                    if(arr[l][i] == y - adder[l]){
                        l = l * blk + i; break;
                    }
                }
                for2(i, blk - 1, 0){
                    if(arr[r][i] == y - adder[r]){
                        r = r * blk + i; break;
                    }
                }
                cout << r - l << endl;
            }
        }
        else{
            cin >> l >> r >> x; --l; --r;
            if(l / blk == r / blk) adblock(l / blk, x, l % blk, r % blk);
            else{
                adblock(l / blk, x, l % blk, blk - 1);
                l = (l / blk + 1);
                adblock(r / blk, x, 0, r % blk);
                r = (r / blk);
                while(l < r){
                    adder[l] += x;
                    adder[l] = min(adder[l], mod);
                    ++l;
                }
            }
        }
    }
}