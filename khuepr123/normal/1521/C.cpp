#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
// #define endl "\n"
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

vector<int> vc;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        vc.clear();
        cin >> n;
        for(int i = 2; i <= n; i += 2){
            cout << "? ";
            cout << "2 " << i - 1 << " " << i << " " << 1 << endl;
            cin >> x;
            if(x <= 2){
                vc.pb(i);
                vc.pb(i - 1);
            }
        }
        if(n % 2) vc.pb(n);
        vc.pb(vc[0]);
        int bark = 0;
        for1(i, 0, vc.size() - 2){
            cout << "? ";
            cout << "2 " << vc[i] << " " << vc[i + 1] << " " << 1 << endl;
            cin >> x;
            if(x == 1){
                bark = vc[i]; break;
            }
        }
        a[bark] = 1;
        for1(i, 1, n){
            if(i == bark) continue;
            cout << "? ";
            cout << "1 " << bark << " " << i << " " << n - 1 << endl;
            cin >> a[i];
        }
        cout << "! ";
        for1(i, 1, n){
            cout << a[i] << " ";
        }
        cout << endl;
    }
}