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
#define int long long
const ll mod = 1e9 + 7;
const int maxN = 200005;
const ll oo = 1e18 + 7;
int n, a[maxN];
bool chk[maxN];
int cnt[maxN];
vector<int> vc;
int x, y;
int ans;

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n; ans = 0; vc.clear();
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            cnt[i] = 0;
            ans += a[i];
        }
        for(int i = 1; i < n; i++){
            cin >> x >> y;
            cnt[x]++;
            cnt[y]++;
        }
        for(int i = 1; i <= n; i++){
            cnt[i]--;
            while(cnt[i]--) vc.pb(a[i]);
        }
        sort(vc.begin(), vc.end());
        cout << ans << " ";
        for(int i = 2; i < n; i++){
            ans += vc.back();
            vc.pop_back();
            cout << ans << " ";
        }
        cout << endl;
    }
}