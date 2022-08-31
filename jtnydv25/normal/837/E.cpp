#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 205;
vector<ll> divs;
ll f(ll a, ll b){
    for(ll i = 1; i * i <= a; i++)
        if(a % i == 0){
            divs.push_back(i);
            if(a != i * i) divs.push_back(a / i);
        }
    ll ans = 0;
    while(b != 0){
        ll g = __gcd(a, b);
        ll x = b / g;
        ll cnt = b / g;
        for(ll d : divs){
            if(d > g){
                ll k = x % (d / __gcd(d, g));
                if(k < cnt) cnt = k;
            }
        }
        b -= cnt * g;
        ans += cnt;
    }
    return ans;
}
int main(){
    ll a, b;
    cin >> a >> b;
    cout << (b / a) + f(a, b % a) ;
}