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
    int n; cin >> n;
    vi a(n);
    for(auto& i : a) cin >> i;
    vi la(n); for(int i=0;i<n;++i) la[i] = __lg(a[i]);
    ll ans = 0;
    for(int rep=0;rep<2;++rep) {
        for(int i=0;i+2<n;++i) {
            int want = 2<<la[i];
            int sm=a[i+1];
            for(int j=i+2;j<n and sm<want;++j) {
                if((a[i]^a[j]) == sm) {
                    if(sm>=2<<la[j]) ans++;
                    else ans+=!rep;
                }
                sm+=a[j];
            }
        }
        reverse(all(a));
        reverse(all(la));
    }
    cout << ans << '\n';
}