#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;
ll N;
vector<ll> a;

vector<ll> primes;

bool IsPrime[2000010];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    for(ll i = 2; i <= 2e6; i++) {
        IsPrime[i] = true;
    }
    for(ll i = 2; i <= 2e6; i++) {
        if(IsPrime[i]) {
            primes.push_back(i);
            for(ll j = i * 2; j <= 2e6; j += i) {
                IsPrime[j] = false;
            }
        }
    }
    cin >> N;
    a.resize(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> divisors;
    //for(ll i = a[0] - N; i <= a[0] + N; i++) {
    for(ll i = a[0] - 2e5; i <= a[0] + 2e5; i++) {
        if(i < 1) continue;
        ll copy = i;
        for(auto p : primes) {
            if(p * p * p > copy) break;
            if(copy % p == 0) {
                divisors.push_back(p);
                while(copy % p == 0) copy /= p;
            }
        }
        if(copy != 1) {
            ll k = sqrt(copy);
            if(k * k == copy) {
                divisors.push_back(k);
            } else {
                divisors.push_back(copy);
            }
        }
    }
    for(auto p : primes) {
        divisors.push_back(p);
    }
    sort(divisors.begin(), divisors.end());
    divisors.erase(unique(divisors.begin(), divisors.end()), divisors.end());
    //cerr << divisors.size() << endl;
    ll ans = N;
    for(auto val : divisors) {
        ll now = 0;
        for(int i = 0; i < N; i++) {
            if(a[i] >= val) now += min(a[i] % val, val - (a[i] % val));
            else now += val - a[i];
            //if(val == 3) {
                //cerr << "t: " << i << " " << a[i] << " " << now << endl;
                //cerr << a[i] % val << " " << val - (a[i] % val) << endl;
            //}
            if(now >= ans) break;
        }
        chmin(ans, now);
    }
    cout << ans << endl;
    return 0;
}