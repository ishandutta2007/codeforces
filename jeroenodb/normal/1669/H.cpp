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
    int need[31] = {};
    vi a(n); for(auto& i : a) {
        cin >> i;
        for(int j=0;j<31;++j) if(!(1<<j & i)) {
            need[j]++;
        }
    }
    int ans=0;
    for(int i=30;i>=0;--i) {
        if(need[i]<=k) {
            ans|=1<<i;
            k-=need[i];
        }
    }
    cout << ans << '\n';
    
    

}
int main() {
    int t; cin >> t;
    while(t--) solve();
}