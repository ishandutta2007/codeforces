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
    int n; cin >> n;
    vi b(n); for(auto& i : b) cin >> i;
    if(b[0]==0) {
        cout << "0\n";
        for(int i=1;i<=n;++i) cout << i << ' ';
        cout << '\n';
        return;
    }
    if(b[n-1]==n+1) {
        cout << n << "\n";
        for(int i=1;i<=n;++i) cout << i << ' ';
        cout << '\n';
        return;
    }
    int k=0;
    while(k<n and b[k]-1>k) ++k;
    vvi want(n+2);
    for(int i=0;i<n;++i) {
        want[b[i]].push_back(i);
    }

    vi last = want[0];
    last.insert(last.end(),all(want[n+1]));
    vi res;
    while(true) {
        vi cur;
        for(int i : last) {
            if(!want[i+1].empty()) {
                cur = want[i+1];
                for(auto& j : last) if(j!=i) res.push_back(j);
                res.push_back(i);
                break;
            }
        }
        if(cur.empty()){
            res.insert(res.end(),all(last));
            break;
        }
        last=cur;
    }
    for(auto& i : res) ++i;
    cout << k << '\n' << res << '\n';

    
    
    
    

    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}