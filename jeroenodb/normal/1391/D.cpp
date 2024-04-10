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
    int n,m; cin >> n >> m;
    if(n>=4) {
        cout << "-1\n";
        exit(0);
    } else if(n==1) {
        cout << "0\n";
        exit(0);
    }
    vector<string> g(n);
    for(auto& i : g) cin >> i;

    int msk = 1<<n;
    vi dp(msk,0);
    vector<pi> trans;
    for(int i=0;i<msk;++i) for(int j=0;j<msk;++j) {
        bitset<3> a  = i^j;
        bool bad=false;
        for(int o=0;o+1<n;++o) {
            if(a[o]==a[o+1]) bad=true;
        }
        if(!bad) trans.push_back({i,j});
    }
    for(int i=0;i<m;++i) {
        vi ndp(msk,oo);
        int cur=0;
        for(int j=0;j<n;++j) cur=cur*2 + (g[j][i]=='1');
        for(auto [at,to] : trans) {
            ndp[to] = min(ndp[to], dp[at]+(int)bitset<3>(to^cur).count());
        }
        swap(ndp,dp);
    }
    cout << *min_element(all(dp));
    
}