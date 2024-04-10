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
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vvi uni(n);
        {
            vi myuni(n);
            for(int& i:myuni) {
                cin >> i,--i;
            }
            for(int i=0;i<n;++i) {
                int a; cin >> a;
                uni[myuni[i]].push_back(a);
            }
            for(int i=0;i<n;++i) {
                sort(uni[i].rbegin(),uni[i].rend());
            }
        }
        vector<ll> ans(n);
        for(int u=0;u<n;++u) {
            auto& v = uni[u];
            int k = v.size();

            vector<ll> pref(k+1);
            for(int i=1;i<=k;++i) pref[i] = pref[i-1]+v[i-1];
            for(int i=1;i<=k;++i) {
                int got = (k/i)*i;
                ans[i-1]+=pref[got];
            }
        }
        cout << ans << '\n';
    }
}