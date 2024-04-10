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
bool solve() {
    ll n,m,k; cin >> n >> m >> k;
    vi a(k);
    for(auto& i : a) cin >> i;
    for(int rep=0;rep<2;++rep) {
        bool par=false;
        ll total=0;
        for(auto& i : a) {
            if(i>=2*n) total+=i/n;
            if(i>=3*n) par=true; // can take out 1*n
        }
        if(total>=m) {
            if(total%2==m%2 or par) {
                return true;
            }
        }
        swap(n,m);
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        auto tmp = solve();
        if(tmp) cout << "Yes\n";
        else cout << "No\n";
    } 
}