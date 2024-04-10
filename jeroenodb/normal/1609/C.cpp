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
void makesieve() {
    for(int i = 2; i < store;++i) {
        if(!sieve[i]) {
            for(int j = i*2;j<store;j+=i) {
                if(!sieve[j]) {
                    factor[j] = i;
                    sieve[j] = true;
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    makesieve();
    int t; cin >> t;
    while(t--) {
        int n,e; cin >> n >> e;
        vi a(n); for(auto& i : a) cin >> i;
        ll ans=0;
        for(int i=0;i<e;++i) {
            int l=-e,ones=0;
            int lastp = -e;
            for(int j=i;j<n;j+=e) {
                if(a[j]==1) {
                    ones++;
                    ans+=(j-l)/e - ones;
                } else if(!sieve[a[j]]) {
                    ones=0;
                    l=lastp;
                    ans+=(j-l)/e - 1;
                    lastp = j;
                } else {
                    lastp = j;
                    ones=0;
                    l=j;
                }
            }
        }
        cout << ans << '\n';
    }
}