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
ll n; ll total; ll temp;
ll pw;

int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        pw = 1;
        cin >> n; n = n * 2; total = 0;
        for(ll i = 1; i <= 31; i++){
            pw = pw * 2;
            temp = pw * (pw - 1);
            if(n < temp){ break;}
            n = n - temp; total++;
        }
        cout << total << "\n";
    }
}