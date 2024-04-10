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
int n, p, a, b, c;
int mn;
int temp;

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        mn = oo * 3;
        cin >> p >> a >> b >> c;
        temp = ((p - 1) / a + 1) * a;
        mn = min(mn, temp);
        temp = ((p - 1) / b + 1) * b;
        mn = min(mn, temp);
        temp = ((p - 1) / c + 1) * c;
        mn = min(mn, temp);
        cout << mn - p << endl;
    }
}