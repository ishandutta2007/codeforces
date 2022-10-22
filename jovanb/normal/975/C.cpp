#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll niz[300000];

int main(){

    int n, q;
    cin >> n >> q;
    for(int i=1; i<=n; i++){cin >> niz[i]; niz[i] += niz[i-1];}
    ll ukup = 0;
    ll a1;
    while(q--){
        cin >> a1;
        ukup += a1;
        if(ukup >= niz[n]){cout << n << "\n"; ukup = 0; continue;}
        if(ukup < niz[1]){cout << n << "\n"; continue;}
        ll l=1, r=n, mid=0;
        ll najres = 0;
        while(l <= r){
            mid = (l+r)/2;
            if(ukup >= niz[mid]){najres = max(najres, mid); l = mid+1;}
            else r = mid-1;
        }
        cout << n-najres << "\n";
    }
    return 0;
}