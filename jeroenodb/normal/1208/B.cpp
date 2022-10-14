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
    vi a(n); for(auto& i : a) cin >> i;
    set<int> have;
    int ans=n;
    for(int i=0;i<n;++i) {
        
        auto h = have;
        ans = min(ans,n-i);
        for(int j=n-1;j>=i;--j) {
            if(h.count(a[j])) break;
            h.insert(a[j]);
            ans = min(ans,j-i);
        }
        if(have.count(a[i])) break;   
        have.insert(a[i]);
    }
    cout << ans << '\n';
}