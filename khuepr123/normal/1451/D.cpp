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
ll n, k;

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o; ll x, y;
    while(o--){
        cin >> n >> k;
        x = sqrt(n * n / 2);
        x = x / k; x = x * k;
        if(x * x + (x + k) * (x + k) <= n * n) cout << "Ashish\n";
        else cout << "Utkarsh\n";
    }
}