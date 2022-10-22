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
int n, a[maxN];
int b[maxN];
int c[maxN];
bool chk[maxN];
int cur; int ans;
bool lck;

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n; ans = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> b[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> c[i];
            if(b[i] > c[i]) swap(b[i], c[i]);
        }
        reverse(a + 1, a + n + 1);
        reverse(b + 1, b + n + 1);
        reverse(c + 1, c + n + 1);
        ans = 0;
        cur = a[1] - 1;
        // cout << cur << endl;
        for(int i = 1; i < n; i++){
            if(b[i] == c[i]){
                cur += 2;
                ans = max(ans, cur);
                cur = a[i + 1] - 1;
                lck = 0;
            }
            else{
                ans = max(ans, cur + 2 + c[i] - b[i]);
                cur = cur + 2 + (a[i + 1] - 1) - (c[i] - b[i]);
                if(cur <= a[i + 1] - 1) cur = a[i + 1] - 1;
                lck = 1;
                
            }
            // cout << cur << endl;
        }
        cout << ans << endl;
        // cout << a[n] - 1 << " " << c[n - 1] - b[n - 1];
        // cout  << endl;
    }
}