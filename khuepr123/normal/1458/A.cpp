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
#define int long long
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 200005;
const ll oo = 1e18 + 7;
int n; int a[maxN], b[maxN], m;
int gd;


signed main(){
    ios_base::sync_with_stdio(0);
    
        cin >> n >> m; gd = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= m; i++) cin >> b[i];
        for(int i = 2; i <= n; i++){
            gd = __gcd(gd, a[1] - a[i]);
        }
        for(int i = 1; i <= m; i++){
            cout << abs(__gcd(a[1] + b[i], gd)) << " ";
        }
    
}