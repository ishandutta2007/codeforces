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
int a, b, c, d;

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> a >> b >> c >> d;
        if(a == c && b == d){
            cout << 0 << endl;
            continue;
        }
        if(a == c){
            cout << abs(b - d) << endl;
            continue;
        }
        if(b == d){
            cout << abs(a - c) << endl;
            continue;
        }
        cout << abs(a - c) + abs(b - d) + 2 << endl;
        
        
        
    }
}