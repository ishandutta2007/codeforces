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
        vector<ll> a(n); for(auto& i : a) cin >> i;
        int ptwos=0,sm=0;;
        for(int i=0;i<n;++i) {
            int b = a[i];
            while(b%2==0) ptwos++,b/=2;
            sm+=b;
        }
        ll ans = 0;
        for(int i=0;i<n;++i) {
            int b = a[i],tmp=0;
            while(b%2==0) tmp++,b/=2;
            tmp = ptwos-tmp;
            ans = max(ans,(a[i]<<tmp) - b + sm);
        }
        cout << ans << '\n';
    }
}