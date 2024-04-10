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
struct counter {
    int cnt[26] = {};
    void add(char c, int sgn=1) {
        cnt[c-'a']+=sgn;
    }
    bool have(char c) {
        return cnt[c-'a']>0;
    }
    bool empty() {
        return count(cnt,cnt+26,0)==26;
    }
};
void cmin(int& a, int b) {a=min(a,b);}
void solve() {
    int n; cin >> n;
    string s,t; cin >> s >> t;
    counter cnt;
    for(auto c : s) cnt.add(c);
    for(auto c: t) cnt.add(c,-1);
    if(!cnt.empty()) {
        cout << "-1\n";
        return;
    }
    vi dp(n+1);
    vi ndp(n+1);
    for(int i=0;i<n;++i) {
        cnt.add(s[i],-1);
        auto cnt2 = cnt;
        fill(all(ndp),oo);
        ndp[0]=0;
        for(int j=0;j<n;++j) {
            cnt2.add(t[j]);
            if(s[i]==t[j]) {
                // match the characters
                cmin(ndp[j+1],dp[j]);
            }
            if(cnt2.have(t[j])) {
                // use a spare character in suffix
                cmin(ndp[j+1],ndp[j]);
            }
            // pick s[i] up -> dp[i][j+1]+1
            cmin(ndp[j+1],dp[j+1]+1);
            
        }
        swap(dp,ndp);
    }
    cout << dp[n] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}