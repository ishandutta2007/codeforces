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
void solve() {
    int n; cin >> n;
    int sm= 0;
    vi a(n); for(auto& i : a) cin >> i,sm+=i;
    vi ans(n);
    iota(all(ans),1);
    if(!sieve[sm]) {
        for(int i=0;i<n;++i) if(a[i]%2==1) {
            ans.erase(ans.begin()+i);
            break;
        }
    }
    cout << ans.size() << '\n';
    cout << ans << '\n';
}
int main() {
    makesieve();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}