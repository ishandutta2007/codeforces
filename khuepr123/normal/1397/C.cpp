#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
const ll mod = 1000000007;
ll a[1000005]; ll temp;

int main(){
    ios_base::sync_with_stdio(0);
    ll n; cin >> n;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n == 1){
        a[1] = 0 - a[1];
        cout << "1 1\n" << a[1] << "\n" << "1 1\n0\n1 1\n0"; return 0;
    }
    cout << "1 " << n - 1 << "\n";
    for(ll i = 1; i < n; i++){
        temp = (n - 1) * a[i]; cout << temp << " ";
    }
    cout << "\n";
    cout << "1 " << n << "\n";
    for(ll i = 1; i < n; i++){
        temp = n * a[i];
        temp = 0 - temp;
        cout << temp << " ";
    }
    cout << 0 << " ";
    cout << "\n";
    a[n] = 0 - a[n];
    cout << n << " " << n << "\n" << a[n] << " ";
}