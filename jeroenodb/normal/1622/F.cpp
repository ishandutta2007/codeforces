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
const int store=1e6 + 1;
bitset<store> sieve={};
int factor[store] = {};
uint64_t h[store];
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
void makesieve() {
    for(int i = 2; i < store;++i) {
        if(!sieve[i]) {
            h[i] = rnd(1ULL,-1ULL);
            for(int j = i;j<store;j+=i) {
                if(!sieve[j]) {
                    factor[j] = i;
                    sieve[j] = true;
                }
            }
        }
    }
}
uint64_t myh(int n) {
    uint64_t res=0;
    while(n>1) {
        int f = factor[n];
        n/=f;
        res^=h[f];
    }
    return res;
}
int main() {
    makesieve();
    int n; cin >> n;
    vector<uint64_t> hs(n+1);
    // 3*2 * 7*6
    // 
    for(int i=2;i<=n;++i) {
        hs[i] = hs[i-1]^myh(i);
    }
    uint64_t total=0;
    for(int i=1;i<=n;++i) total^=hs[i];
    if(total==0) {
        cout << n << "\n";
        for(int i=1;i<=n;++i) cout << i << ' ';
        exit(0);
    } 
    for(int i=1;i<=n;++i) {
        if(hs[i]==total) {
            cout << n-1 << '\n';
            for(int j=1;j<=n;++j) if(i!=j) cout << j << ' ';
            exit(0);
        }
    }
    while(true) {
        unordered_map<uint64_t,int> s;
        for(int i=1;i<=n;++i) {
            if(s.count(total^hs[i])) {
                cout << n-2 << '\n';
                int j = s[total^hs[i]];
                for(int o=1;o<=n;++o) if(o!=j and o!=i) cout << o << ' ';
                exit(0);
            }
            s[hs[i]]=i;
        }
        total^=hs[n--];
    }
    // can always be done with 3 things?
    // 1 3 5 7
}