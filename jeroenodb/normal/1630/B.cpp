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
void solve() {
    int n,k; cin >> n >> k;
    vi a(n); for(auto& i : a) cin >> i;
    auto b = a;
    sort(all(b)); 
    int need = (n+k+1)/2;
    array<int,3> best  = {oo+1,oo,oo};
    for(int i=0;i+need<=n;++i) {
        best = min(best, {b[i+need-1]-b[i], b[i], b[i+need-1]});
    }
    cout << best[1] << ' ' << best[2] << '\n';
    int prev = 0;
    int pref=0;
    for(int i=0;i<n;++i) {
        if(best[1]<=a[i] and a[i]<=best[2]) {
            pref++;
        } else pref--;
        if(pref>0 and k>1) {
            cout << prev+1 << ' ' << i+1 << '\n';
            prev = i+1,pref=0;
            k--;
        }
    }
    cout << prev+1 << ' ' << n << '\n';

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}