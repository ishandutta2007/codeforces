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
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
vector<int> vc;
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        vc.clear();
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            a[i] = i;
        }
        if(n <= 63 && pow(2, n - 1) < k){
            cout << -1 << endl;
            continue;
        }
        k--;
        if(n < 63){
            for(int i = n - 1; i > -1; i--){
                vc.pb(k & (1ll << i));
            }
        }
        else{
            for(int i = n - 1; i >= 63; i--){
                vc.pb(0);
            }
            for(int i = 62; i > -1; i--){
                vc.pb(k & (1ll << i));
            }
        }
        vc.pb(0);
        int l = 0;
        for(int i = 1; i <= n; i++){
            if(vc[i] == 0){
                reverse(a + l + 1, a + i + 1);
                l = i;
            }
        }
        for(int i = 1; i <= n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
}