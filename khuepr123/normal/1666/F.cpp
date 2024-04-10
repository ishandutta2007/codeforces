/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define all(flg) flg.begin(), flg.end()
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
const ll mod = 998244353;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

// dp[i]: i crew left

int dp[5005];
int cop[5005];
int C[5005][5005];

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    for1(i, 0, 5000) for1(j, 0, 5000){
        if(!i || (!j)) C[i][j] = 1;
        else C[i][j] = (C[i - 1][j] + C[i][j - 1]) % mod;
    }
    while(o--){
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        cin >> n; map<int, int> mp;
        for1(i, 1, n){
            cin >> x; ++mp[x];
        }
        // goal: get 0 useless member left
        ii pr = *mp.rbegin();
        if(pr.se > 1){
            cout << "0\n"; continue;
        }
        mp.erase(pr.fi);
        int accu = 0;
        int ans = 0;
        n /= 2;
        for(auto itr = mp.rbegin(); itr != mp.rend(); ++itr){
            y = itr->se;
            int sumof = accu + y;
            memset(cop, 0, sizeof(cop));

            // sumof: all candidate
            // case 1: abandon all:
            // if(itr->fi == 1) cout << cop[n - 1] << endl;
            for1(i, 0, n){
                if(i * 2 >= sumof){
                    int godleft = i * 2 - accu;
                    if(i == n) --godleft;
                    if(godleft >= y){
                        cop[i] += dp[i] * C[y][godleft - y];
                        cop[i] %= mod;
                    }
                }
                if(i > n - 1) break;
            }
            // if(itr->fi == 1) cout << cop[n - 1] << endl;
            // case 2: hold 1:
            int crew = y - 1;
            for1(i, 0, n - 1){
                int godleft = i * 2 - accu;
                if(godleft >= crew){
                    cop[i + 1] += dp[i] * C[crew][godleft - crew];
                }
                cop[i + 1] %= mod;
            }
            // if(itr->fi == 1) cout << cop[n - 1] << endl;
            for1(i, 0, n) dp[i] = cop[i];
            // for1(i, 0, n) cout << dp[i] << " ";
            // cout << endl;
            accu += y;
        }
        cout << dp[n] << endl;
    }
}