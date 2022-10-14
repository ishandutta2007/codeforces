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
    vi a(n); for(auto& i: a) cin >> i;
    
    vi last(n+1,-1);
    for(int i=n-1;i>=0;--i) {
        if(last[a[i]]==-1) last[a[i]]=i;
    }
    int lazy=0;
    multiset<int> best;
    typedef multiset<int>::iterator IT;
    vector<vector<IT>> gone(n);
    int ans=0;
    for(int i=0;i<n;++i) {
        int curdp = 0;
        if(!best.empty()) curdp = max(curdp,*best.rbegin()+lazy);
        ans = max(curdp,ans);
        if(last[a[i]]>i) {
            // transition to dp[j], j<last[a[i]]
            auto it = best.insert(-lazy-1+ans);
            gone[last[a[i]]].push_back(it);
        }
        for(auto it : gone[i]) {
            best.erase(it);
        }
        lazy++;
    }
    cout << ans << '\n';
}