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
    int n; cin >> n;
    vi a(n); for(auto& i : a) cin >> i;
    vi order(n); iota(all(order),0);
    stable_sort(all(order), [&](int c,int d){return a[c]<a[d];});
    vi rank(n); 
    vector<pi> ans;
    for(int i=0;i<n;++i) rank[order[i]]=i;
    for(int i=0;i<n;++i) {
        for(int j=rank[i]-1;j>=0;--j) {
            ans.emplace_back(i,order[j]);
        }
        for(int j=i+1;j<n;++j) {
            if(rank[j]>rank[i]) rank[j]--;
        }
        order.erase(order.begin()+rank[i]);
    }
    cout << ans.size() << '\n';
    for(auto [c,d] : ans) {
        cout << c+1 << ' ' << d+1 << '\n';
    }
}