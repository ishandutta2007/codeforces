#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
map <ll, int> stepen;
map <ll, ll> tren;
map <ll, int> maxstep;
 
const ll INF = 100000000000000000LL;
 
ll pw(ll a, ll b, ll mod){
    if(b == 0) return 1;
    __int128 res = pw(a, b/2, mod);
    res = (res*res)%mod;
    if(b%2) res = (res*a)%mod;
    return res;
}
 
ll inv(ll x, ll mod){
    return pw(x, mod-2, mod);
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;
 
    ll x, y;
    cin >> x >> y;
    ll poc = __gcd(x, y);
    vector <ll> primes;
    ll d = x;
    for(ll i=2; i*i<=d; i++){
        if(d%i == 0){
            primes.push_back(i);
            while(d%i == 0){
                d /= i;
                maxstep[i]++;
            }
        }
    }
    if(d > 1){
        primes.push_back(d);
        maxstep[d]++;
    }
    ll gg = poc;
    for(ll c : primes){
        tren[c] = 1;
        while(gg%c == 0){
            tren[c] *= c;
            gg /= c;
            stepen[c]++;
        }
    }
    ll res = 0;
    //int iter = 100;
    while(y){
        ll steps = y/poc;
        //cout << y <<  " x " << poc << endl;
        //cout << steps << "prvo " << endl;
        for(ll c : primes){
            if(stepen[c] == maxstep[c]) continue;
            if(INF/c < tren[c]) continue;
            __int128 b = (y/tren[c])%c;
            __int128 a = (poc/tren[c])%c;
            //cout << (ll)b << " " << (ll)a << " " << c << " " << (ll)(b*inv(a, c)%c) << "\n";
            if(!a) continue;
            steps = min(steps, (ll)((b*inv(a, c))%c));
        }
        //iter--;
        //if(!iter) break;
        //cout << steps << endl;
        res += steps;
        y -= steps*poc;
        for(auto c : primes){
            for(;;){
                if(INF/c < poc) break;
                poc *= c;
                tren[c] *= c;
                stepen[c]++;
                if(y%poc || x%poc){
                    poc /= c;
                    tren[c] /= c;
                    stepen[c]--;
                    break;
                }
            }
        }
    }
    cout << res;
    return 0;
}