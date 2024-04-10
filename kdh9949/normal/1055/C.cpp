#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = ll(2e9);

ll a, b, c, x, y, z;

ll f(ll a, ll b, ll x, ll y, ll g){
    ll q=(a-x)/g-100;
    x+=g*q; y+=g*q;
    ll r=0;
    for(int i=0; i<=10000; i++){
        r=max(r, min(b,y)-max(a,x));
        x+=g; y+=g;
    }
    return r;
}

int main(){
    cin >>a>>b>>c>>x>>y>>z;
    if(c<z){ swap(a,x); swap(b,y); swap(c,z); }
    ll g = __gcd(c,z);
    b++; y++;
    cout << f(a+c*INF,b+c*INF,x,y,g) <<endl;
}