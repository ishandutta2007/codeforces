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
    int n,m; cin >> n >> m;
    string s; cin >> s;
    ll num = count(all(s),'1');
    if( (num*m)%n!=0) {
        cout << "-1\n";
        return;
    }
    num = (num*m)/n;
    int need = num;
    for(int i=0;i<m-1;++i) need-=s[i]=='1';
    for(int i=m-1;i<n+m;++i) {
        need-=s[i%n]=='1';
        if(need==0) {
            vector<pi> ivs;
            if(i>=n) {
                ivs.push_back({0,i%n});
                ivs.push_back({i-m+1,n-1});
            } else {
                ivs.push_back({i-m+1,i});
            }
            cout << ivs.size() << '\n';
            for(auto [l,r] : ivs) cout << l+1 << ' ' << r+1 << '\n';
            return;
        }
        need+=s[i-m+1]=='1';
        
    }
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}