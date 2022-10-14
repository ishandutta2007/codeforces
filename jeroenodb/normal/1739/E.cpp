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
void cmax(int& a, int b) {a=max(a,b);}
int main() {
    int n; cin >> n;
    string g[2] = {};
    cin >> g[0] >> g[1];
    array<array<int,3>,2> dp;
    for(auto& i : dp) fill(all(i),-oo);
    dp[0][0]=0;
    for(int i=0;i<n;++i) {
        array<array<int,3>,2> ndp;
        for(auto& i : ndp) fill(all(i),-oo);
        for(int pos=0;pos<2;++pos) for(int r=0;r<3;++r) {
            char c[2] = {g[0][i],g[1][i]};
            if(r==1) c[0]='0';
            else if(r==2) c[1]='0';
            auto cur = dp[pos][r];
            if(cur==-oo) continue;
            if(c[pos]=='1') cur++;
            if(c[!pos]=='1') {
                // don't take it
                cmax(ndp[pos][0],cur);
                // take it
                if(i+1<n and g[pos][i+1]=='1') {
                    cmax(ndp[!pos][1+pos],cur+1);
                } else cmax(ndp[!pos][0],cur+1);
            } else {
                cmax(ndp[pos][0],cur);
            }
        }
        dp=ndp;
    }
    int ans=0;
    for(int i=0;i<2;++i) for(int j=0;j<3;++j) ans=max(ans,dp[i][j]);
    cout << ans << '\n';
}