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
    vi a(n);
    vi b;
    {
    map<int,int> cnt;
     for(auto& i : a) cin >> i, cnt[i]++;
    
        vector<pi> ps;
        for(auto [i,c] : cnt) {
            ps.push_back({c,i});
        }
        sort(ps.rbegin(),ps.rend());
        for(auto [c,i] : ps) {
            for(int j=0;j<c;++j) b.push_back(i);
        }
    }
    map<int,vi> to;
    int j = 1;
    while(j<n and b[j]==b[j-1]) ++j;
    int k=0;
    for(int i=0;i<n;++i) {
        if(j==n) {
            to[b[i]].push_back(b[k++]);
        } else {
            to[b[i]].push_back(b[j++]);
        }
    }
    vi res(n);
    for(int i=0;i<n;++i) {
        auto& v = to[a[i]];
        res[i] = v.back();
        v.pop_back();
    }
    cout << res << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}