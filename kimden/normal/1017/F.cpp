#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const ll mod = (1LL << 32LL);
int n;
ll a, b, c, d;

ll ans = 0;

ll get(ll x){
    ll cnt = 0;
    for(ll o = x; o <= n; o *= x){
        cnt = (cnt + n / o) % mod;
    }
    ll val = a;
    val = (val * x) % mod;
    val = (val + b) % mod;
    val = (val * x) % mod;
    val = (val + c) % mod;
    val = (val * x) % mod;
    val = (val + d) % mod;
    return (cnt * val) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b >> c >> d;
    const int N = 20000;
    vector<int> v(N), primes;
    for(int i = 0; i <= n; i += N){
        fill(all(v), 1);
        if(i){
            for(auto p: primes){
                for(int j = (i % p ? p - i % p : 0); j < N; j += p){
                    v[j] = 0;
                }
            }
        }else{
            v[0] = v[1] = 0;
            for(int p = 2; p < N; ++p){
                if(v[p]){
                    primes.push_back(p);
                }
                for(int j = p + p; j < N; j += p){
                    v[j] = 0;
                }
            }
        }
        for(int j = 0; j < N; ++j){
            if(i + j > n){
                break;
            }
            if(v[j]){
                ans = (ans + get(i + j)) % mod;
            }
        }
    }
    cout << ans << endl;



    return 0;
}