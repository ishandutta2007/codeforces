#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll niz[1000000];
int main(){
    ios_base::sync_with_stdio(false);

    ll x;
    ll n=0;
    cin >> x;
    ll d;
    cin >> d;
    ll pomoc = x;
    ll r=0;
    ll poslednji = -d+1;
    ll jos=0;
    while(pomoc){
        if(poslednji == 0) poslednji = -d+1;
        r++;
        if(pomoc & 1){
            jos++;
            ll staron = n;
            n += r-1;
            for(int i=staron+1; i<=n; i++) niz[i] = poslednji+d;
            poslednji = niz[n];
        }
        pomoc >>= 1;
    }
    while(jos--){
        niz[++n] = poslednji+d;
        poslednji = niz[n];
    }
    if(n > 10000){cout << -1; return 0;}
    if(poslednji >= 1000000000000000000) {cout << -1; return 0;}
    cout << n << "\n";
    for(int i=1; i<=n; i++) cout << niz[i] << " ";
    return 0;
}