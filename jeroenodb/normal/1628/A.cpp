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
    vi a(n); for(auto& i : a) cin >> i;
    // pick first k numbers that have maximum mex
    vi cnt(n+2);
    for(auto& i : a) cnt[i]++;
    int mex=0;
    while(cnt[mex]) 
        mex++;
    vi res;
    int i=0;
    while(i<n) {
        int cur=0;
        int j = i;
        vector<bool> have(mex+2);
        do {
            if(a[j]<=mex)
                have[a[j]]=true;
            ++j;
            while(have[cur]) 
                cur++;
        } while(cur!=mex);
        for(int o=i;o<j;++o) {
            if(--cnt[a[o]] == 0) {
                mex = min(mex,a[o]);
            }
        }
        res.push_back(cur);
        i=j;
    }
    cout << res.size() << '\n' << res << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}