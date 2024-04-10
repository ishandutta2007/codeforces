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
const int mxN = 5000+1, oo = 1e9;
short lcp[mxN][mxN];
string s;
int n;
struct subs {
    int i,len;
    bool operator<(const subs& o) const {
        if(lcp[i][o.i]>=min(len,o.len)) {
            return len<o.len;
        }
        if(max(i,o.i)+lcp[i][o.i]==n) return false;
        return s[i+lcp[i][o.i]]<s[o.i+lcp[i][o.i]];
    }
};
void solve() {
    cin >> n >> s;
    for(int i=0;i<=n;++i) lcp[i][n]=0, lcp[n][i]=0;
    for(int i=n-1;i>=0;--i) {
        for(int j=n-1;j>=0;--j) {
            if(s[i]==s[j]) {
                lcp[i][j] = lcp[i+1][j+1]+1;
            } else lcp[i][j]=0;
        }
    }
    vector<subs> dp;
    for(int i=0;i<n;++i) {
        for(int len=1;len+i<=n;++len) {
            subs cur = {i,len};
            auto it = lower_bound(all(dp),cur);
            if(it==dp.end()) dp.push_back(cur);
            else *it=cur;
        }
    }
    cout << dp.size() << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}