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
const long long MOD = 998244353;
class mint {
public:
    int d;
    mint () {d=0;}
    mint (long long _d) : d(_d%MOD){};
    mint operator*(const mint& o) const {
        return ((ll)d*o.d)%MOD;
    }
    mint operator+(const mint& o) const {
        long long tmp = d+o.d;
        if(tmp>=MOD) tmp-=MOD;
        return tmp;
    }
    mint operator-(const mint& o) const {
        long long tmp = d-o.d;
        if(tmp<0) tmp+=MOD;
        return tmp;
    }
    mint operator^(long long b) const {
        mint tmp = 1;
        mint power = *this;
        while(b) {
            if(b&1) {
                tmp = tmp*power;
            }
            power = power*power;
            b/=2;
        }
        return tmp;
    }
    mint operator/(const mint& o) {
        return *this * (o^(MOD-2));
    }
    bool operator==(const mint& o) {
        return d==o.d;
    }
    friend mint& operator+=(mint& a, const mint& o) {
        a.d+=o.d;
        if(a.d>=MOD) a.d-=MOD;
        return a;
    }
};
vi adj[mxN];
int curdiv,have[mxN];
bool dfs(int at, int from) {
    have[at]=0;
    for(int to: adj[at])if(to!=from) {
        if(!dfs(to,at)) return false;
        if(have[to]%curdiv==0) {
            have[at]++;
        } else if(at) have[to]++;
        if(have[to]%curdiv!=0) return false;
    }
    return true;
}
void solve() {
    int n; cin >> n;
    for(int i=0;i<=n;++i) adj[i].clear();
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<mint> res(n+1);
    res[1] = mint(2)^(n-1);
    for(curdiv=2;curdiv<n;++curdiv) {
        if((n-1)%curdiv==0) {
            res[curdiv]=dfs(1,0) and have[1]%curdiv==0;
        }
    }
    for(int i=n;i>=1;--i) {
        for(int j=i*2;j<=n;j+=i) {
            res[i]=res[i]-res[j];
        }
    }
    for(int i=1;i<=n;++i) {
        cout << res[i].d << ' ';
    } cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}