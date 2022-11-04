#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using ull = unsigned long long;

ll mod = 1000000007;

ll fact[1000100];
ll revv[1000100];
ll revfact[1000100];
bool comp[1000100];
ll lpr[1000100];
vector<ll> primes;

ll rev(ll p){
    ll a = mod;
    ll b = p;
    vector<ll> q;
    while(a % b) {
        q.push_back(a / b);
        a = a % b;
        swap(a, b);
    }
    ll w, e;
    w = 0;
    e = 1;
    while(!q.empty()){
        w -= q.back() * e;
        w %= mod;
        w += mod;
        w %= mod;
        swap(w, e);
        q.pop_back();
    }
    return e;
}

ll expr(ll r, ll alpha) {

    ll ans = 1;
    ans *= fact[alpha + r - 1];
    ans *= revfact[alpha];
    ans %= mod;
    ans *= revfact[r];
    ans %= mod;
    ans *= (2 * alpha + r);
    ans %= mod;
    return ans;
}

ll res(ll r, ll n){
    ll ans = 1;
    ll m = n;
    ll alpha;
    int i = 0;
    map<ll, int> mp;
    while(m > 1) {
        mp[lpr[m]]++;
        m /= lpr[m];
    }
    for(auto p: mp){
        ans *= expr(r, p.second);
        ans %= mod;
    }
    return ans;
}


int main(){
//    srand(time(NULL));
//    ios_base::sync_with_stdio(false);
    ll q;
    scanf("%lld", &q);
//    q = 1000000;
    ll r, n;
    fact[0] = 1;
    revfact[0] = 1;
    for(ll i = 2; i < 1000100; i++){
        if(!comp[i]){
            primes.push_back(i);
            lpr[i] = i;
        }
        for(int j = 0; j < primes.size() && primes[j] <= lpr[i] && i * primes[j] < 1000100; j++){
            comp[i * primes[j]] = true;
            lpr[i * primes[j]] = primes[j];
        }
    }
//    for(int i = 2; i < 50; i++){
//        cout << i << "\t" << lpr[i] << endl;
//    }
    for(ll i = 1; i < 1000100; i++){
        revv[i] = rev(i);
    }
    for(ll i = 1; i < 1000100; i++){
        fact[i] = (fact[i - 1] * i) % mod;
        revfact[i] = (revfact[i - 1] * revv[i]) % mod;
    }

    for(ll i = 0; i < q; i++){
        scanf("%lld%lld", &r, &n);
       // r = rand() % 1000001;
        //n = rand() % 1000001;
//        cout << i << "\t(" << r << ", " << n << ")" << endl;
        printf("%lld\n", res(r, n));
    }
}