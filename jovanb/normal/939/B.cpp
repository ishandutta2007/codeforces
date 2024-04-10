#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll niz[1000000];
ll res[1000000];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    ll n, k, maxi=0;
    cin >> n >> k;
    for(int i=1; i<=k; i++){
        cin >> niz[i];
        ll x = n/niz[i];
        res[i] = x*niz[i];
        maxi = max(maxi, res[i]);
    }
    for(int i=1; i<=k; i++){
        if(res[i] == maxi) {cout << i << " " << res[i]/niz[i]; return 0;}
    }
    return 0;
}