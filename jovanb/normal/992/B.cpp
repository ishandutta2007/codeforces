#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map <int, int> bio;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    ll l, r;
    cin >> l >> r;
    ll x, y;
    ll br=0;
    cin >> x >> y;
    for(ll i=1; i*i<=y; i++){
        if(y%i == 0){
            ll d = (y/i)*x;
            if(d >= l && d <= r && i >= l && i <= r && __gcd(d, i) == x) {
                if(!bio[d]){br++; bio[d] = 1;}
                if(!bio[i]){br++; bio[i] = 1;}
            }
            ll drugi = y/i;
            d = (y/drugi)*x;
            if(d >= l && d <= r && drugi >= l && drugi <= r && __gcd(d, drugi) == x) {
                if(!bio[d]){br++; bio[d] = 1;}
                if(!bio[drugi]){br++; bio[drugi] = 1;}
            }
        }
    }
    cout << br;
    return 0;
}