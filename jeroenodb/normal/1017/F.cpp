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
const int B = 2e4, N = 3e8+1;
bitset<B> sieve;
unsigned int cs[4];

unsigned f(unsigned p) {
    unsigned res=0;
    for(int i=0;i<4;++i) {
        res = res*p+cs[i];
    }
    return res;
}
void segsieve(int n) {
    unsigned res=0;
    auto calc = [&](int p) {
        if(p>n) return;
        int k = n;
        unsigned coef = 0;
        while(k) {
            k/=p;
            coef+=k;
        }
        res+=f(p)*coef;
    };
    vi ps;
    for(int i=2;i<B;++i) {
        if(!sieve[i]) {
            ps.push_back(i);
            calc(i);
            for(int j=i*i;j<B;j+=i) {
                sieve[j]=true;
            }
        }
    }
    for(int lo=B;lo<=n;lo+=B) {
        sieve.reset();
        for(auto p : ps) {
            ll start = ((ll)(lo-1)/p + 1)*p;
            for(ll i=start;i<lo+B;i+=p) {
                sieve[i-lo]=true;
            }
        }
        for(int i=0;i<B;++i) {
            if(!sieve[i]) calc(i+lo);
        }
    }
    cout << res << '\n';
}
int main() {
    int n; cin >> n;
    for(int i=0;i<4;++i) cin >> cs[i];
    segsieve(n);
}