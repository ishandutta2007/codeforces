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
    int n,k; cin >> n >> k;
    string s; cin >> s;
    vi l(n),r(n);
    for(int i=0;i<n;++i) cin >> l[i] >> r[i],--l[i],--r[i];
    
    vector<bool> good(n);
    char c[2] = {'a'-1,'a'-1};
    auto dfs = [&](auto self, int at) -> void {
        if(r[at]!=-1) self(self,r[at]); 
        if(s[at]==c[0]) 
            good[at] = s[at]<c[1];
        else {
            good[at]=s[at]<c[0];
            c[1]=c[0];
            c[0]=s[at];
        }
        if(l[at]!=-1) self(self,l[at]);
    };
    dfs(dfs,0);
    string ans;
    int depth=0;
    auto dfs2 = [&](auto self, int at, bool still=true) -> void {
        depth++;
        if(l[at]!=-1) self(self,l[at],still);
        ans.push_back(s[at]);
        if((depth==0 or (good[at] and depth<=k)) and still) {
            k-=depth;
            depth=0;
            ans.push_back(s[at]);
        } else still=false;
        if(r[at]!=-1) self(self,r[at],still); 
        if(depth>0) depth--;
    };
    dfs2(dfs2,0);
    cout << ans << '\n';
}