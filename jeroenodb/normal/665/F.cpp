#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
const int store=6e6 + 1;
bitset<store> sieve={};
int primecnt[store];
vi ps;
void makesieve() {
    for(int i = 2; i < store;++i) {
        primecnt[i]+=primecnt[i-1];
        if(!sieve[i]) {
            primecnt[i]++;
            ps.push_back(i);
            for(int j = i;j<store;j+=i) {
                sieve[j]=true;
            }
        }
    }
}

ll solve(ll n) {
    if(n<=store) {
        return primecnt[n];
    }
    vector<ll> v;
    for (ll k = 1; k * k <= n; ++k) {
        v.push_back(n / k);
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    // return i such that v[i] = x
    // since v[i] = i + 1 for i <= sqrt(n) and v[v.size() - i] = n / i for i <= sqrt(n),
    // we can calculate index in O(1)
    ll sq = sqrt(n);
    auto geti = [&](ll x) {
        if (x <= sq) return (int)x - 1;
        else         return (int)(v.size() - (n / x));
    };

    vector<ll> dp(v.size());

    // S(n, 0) = n
    for (int i = 0; i < v.size(); ++i)
        dp[i] = v[i];

    int a = 0;
    for (ll p = 2; p * p <= n; ++p) {
        // this condition is true for primes
        if (dp[geti(p)] != dp[geti(p - 1)]) {
            ++a;
            for (int i = (int)v.size() - 1; i >= 0; --i) {
                if (v[i] < p * p) break;
                dp[i] -= dp[geti(v[i] / p)] - a;
            }
        }
    }

    return dp[geti(n)] - 1;
}
int main() {
    // p^3, or p*q
    // p*q is hard!
    makesieve();
    ll n; cin >> n;
    ll ans=0;
    for(auto i : ps) {
        if(ll(i)*i*i>n) break;
        ans++;
    }
    int cnt=1;
    for(auto i : ps) {
        if(ll(i)*i>=n) break;
        ans+=solve(n/i);
        ans-=cnt;
        cnt++;
    }
    cout << ans;
}