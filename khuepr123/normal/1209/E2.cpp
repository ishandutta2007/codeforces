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
int n, m, a[14][2005];
int x, y, z, k;
ii mxer[maxN];
int dp[8092];
int arr[12];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        vector<int> vc;
        cin >> n >> m;
        memset(mxer, 0, sizeof(mxer));
        memset(dp, 0, sizeof(dp));
        for1(i, 1, n){
            for1(j, 1, m){
                cin >> a[i][j];
                mxer[j].fi = max(mxer[j].fi, a[i][j]);
            }
        }
        for1(j, 1, m){
            mxer[j].se = j;
        }
        sort(mxer + 1, mxer + m + 1);
        reverse(mxer + 1, mxer + m + 1);
        for1(j, 1, min(n, m)){
            vc.pb(mxer[j].se);
        }
        for(auto child : vc){
            for1(i, 0, n - 1){
                arr[i] = a[i + 1][child];
            }
            for1(i, 0, n - 1){
                for1(j, 0, (1 << n) - 1){
                    if(j & (1 << i)){
                        dp[j] = max(dp[j], dp[j ^ (1 << i)] + arr[i]);
                    }
                }
            }
            for1(j, 0, (1 << n) - 1){
                int mx = dp[j];
                int cop = (j >> 1) + ((j & 1) << (n - 1));
                while(cop != j){
                    mx = max(mx, dp[cop]);
                    cop = (cop >> 1) + ((cop & 1) << (n - 1));
                }
                dp[j] = mx;
            }
            // for1(j, 0, (1 << n) - 1){
            //     cout << dp[j] << " ";
            // }
            // cout << endl;
        }
        cout << dp[(1 << n) - 1] << endl;
    }
}