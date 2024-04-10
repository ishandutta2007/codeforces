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
#define vi vector<int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define ld long double
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int fib[65];
int sum[65];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    fib[0] = 1;
    fib[1] = 1;
    for1(i, 2, 64) fib[i] = fib[i - 1] + fib[i - 2];
    sum[0] = fib[0];
    for1(i, 1, 64) sum[i] = sum[i - 1] + fib[i];
    // for1(i, 0, 5) cout << fib[i] << " " << sum[i] << endl;
    while(o--){
        map<int, int> mp;
        cin >> n;
        z = 0;
        for1(i, 1, n){
            cin >> a[i]; ++mp[a[i]]; z += a[i];
        }
        bool killed = 1;
        for1(eno, 0, 64) if(sum[eno] == z){
            // cout << eno << endl;
            int pvi = -1;
            for2(i, eno, 0){
                // for(ii pr : mp){
                //     while(pr.se--) cout << pr.fi << " ";
                // }
                // cout << endl;
                auto itr = mp.end(); itr = prev(itr);
                if(itr->fi < fib[i]) break;
                if(itr->se == 1 && pvi == itr->fi) break;
                --itr->se;
                pvi = itr->fi - fib[i];
                mp[pvi]++;
                if(itr->se == 0) mp.erase(itr);
            }
            mp.erase(0);
            if(mp.empty()) killed = 0;
        }
        cout << (killed ? "NO" : "YES") << endl;
    }
}