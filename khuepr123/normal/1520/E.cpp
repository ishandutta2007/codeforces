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
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        char c;
        vector<int> vc;
        for1(i, 1, n){
            cin >> c;
            if(c == '*') vc.pb(i);
        }
        int ans = 0;
        int sav = 0;
        int fff = vc.size();
        for1(i, 0, fff - 1){
            if((i + 1) * 2 > fff){
                sav = vc[i] - i; break;
            }
        }
        for1(i, 0, fff - 1){
            ans += abs(vc[i] - i - sav);
            // cout << vc[i] + i << " " << sav << endl;
        }
        // cout << endl;
        cout << ans << endl;
        // cout << sav << endl << endl;
    }
}