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
    vi a(n); for(auto& i: a) cin >> i;
    vector<pi> ops;
    
    vi t;
    int i=0;
    while(i!=a.size()) {
        int j= i+1;
        while(j<(int)a.size() and a[j]!=a[i]) ++j;
        if(j==(int)a.size()) {
            cout << "-1\n";
            return;
        }
        t.push_back((j-i)*2);
        for(int k=i+1;k<j;++k) {
            ops.push_back({j+k-i,a[k]});
        }
        auto v = vi(a.begin()+i+1,a.begin()+j);
        reverse(all(v));
        a.insert(a.begin()+j+1,all(v));
        reverse(all(v));
        a.insert(a.begin()+j+1,all(v));
        i+=t.back();
    }
    cout << ops.size() << '\n';
    for(auto [p,c] : ops) cout << p << ' ' << c << '\n';
    cout << t.size() << '\n';
    for(auto tt : t) cout << tt << '\n';
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >>t;
    while(t--) solve();
}