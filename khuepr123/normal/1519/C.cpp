#include<bits/stdc++.h>
using namespace std;

#define int long long
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
const int maxN = 200005;
const ll oo = 1e18 + 7;
int n, m;
vector<int> vc[maxN];
int ans[maxN];
int x[maxN], y[maxN], z, k;
int pre[maxN];


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for1(i, 1, n){
            ans[i] = 0;
            vc[i].clear();
        }
        for1(i, 1, n){
            cin >> x[i];
        }
        for1(i, 1, n){
            cin >> y[i];
            vc[x[i]].pb(y[i]);
        }
        
        for1(i, 1, n){
            sort(vc[i].begin(), vc[i].end(), greater<int>());
            m = vc[i].size();
            for1(j, 1, m){
                pre[j] = vc[i][j - 1];
            }
            pre[0] = 0;
            for1(j, 1, m){
                pre[j] = pre[j - 1] + pre[j];
            }
            for1(j, 1, m){
                int num = (m / j);
                num *= j;
                ans[j] += pre[num];
            }
        }
        for1(i, 1, n){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}