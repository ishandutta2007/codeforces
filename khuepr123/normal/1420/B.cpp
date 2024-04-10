#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
ll n; ll temp; ll num[45]; ll ans; ll total;

int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        total = 0;
        for(ll i = 0; i <= 44; i++){
            num[i] = 0;
        }
        cin >> n;
        for(ll i = 1; i <= n; i++){
            cin >> ans; temp = 0;
            while(ans){
                temp++; ans/=2;
            }
            num[temp]++;
        }
        for(ll i = 0; i <= 44; i++){
            total = total + (num[i] * (num[i] - 1)) / 2;
        }
        cout << total << "\n";
    }
}