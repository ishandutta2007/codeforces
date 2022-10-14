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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int q; cin >> q;
        vi a(n); for(auto& i : a) cin >> i;
        sort(all(a));
        vector<ll> pref(n+1);
        for(int i=0;i<n;++i) {
            pref[i+1]=pref[i]+a[n-1-i];
        }
        while(q--) {
            int x; cin >> x;
            auto it = lower_bound(all(pref),x);
            if(it==pref.end()) cout << "-1\n";
            else cout << it-pref.begin() << '\n';
        }
    }
}