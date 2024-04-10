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
int par(int x) {
    int lg = __lg(x);
    if(1<<lg < x) ++lg;
    return (1<<lg) - x;
}
int main() {
    map<int,pi> longest;
    int n; cin >> n;
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        longest[a]={0,i+1};
    }
    array<int,3> ans={};
    while(!longest.empty()) {
        auto it = prev(longest.end());;
        auto [at,d] = *it;
        longest.erase(it);
        if(at) {
            d.first++;
            int p = par(at);
            if(longest.count(p)) {
                auto& [dd,o] = longest[p];
                ans = max(ans,{dd+d.first,o,d.second});
            }
            longest[p]=max(longest[p],d);
        }
    }
    cout << ans[1] << ' ' << ans[2] << ' ' << ans[0] << '\n';
}