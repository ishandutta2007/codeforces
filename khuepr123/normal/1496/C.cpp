#include<bits/stdc++.h>
using namespace std;

#define int long long
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
int n;
int x, y;

double ans;


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int o; cin >> o;
    // ans = 0;
    while(o--){
        ans = 0;
        cin >> n;
        vector<int> a, b;
        for(int i = 1; i <= n * 2; i++){
            cin >> x >> y;
            if(x == 0){
                a.pb(abs(y));
            }
            else{
                b.pb(abs(x));
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(int i = 0; i < n; i++){
            ans += sqrt(a[i] * a[i] + b[i] * b[i]);
            // cout << sqrt(k) << endl;
        }
        cout << fixed << setprecision(9) << ans << endl;
    }
}