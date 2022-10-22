#include<bits/stdc++.h>
using namespace std;

#define sadasdads long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, a[maxN],k;
vector<int> ans;

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n >> k;
        ans.clear();
        for(int i = (k + 1) / 2; i <= n; i++){
            ans.pb(i);
        }
        cout << ans.size() - 1 << endl;
        for(int i = 0; i < ans.size(); i++) if(ans[i] != k) cout << ans[i] << " ";
        cout << endl;
    }
}