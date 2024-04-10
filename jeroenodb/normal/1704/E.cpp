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
const long long MD = 998244353;
template<long long MOD=MD> struct mdint {
    int d=0;
    mdint () {d=0;}
    mdint (long long _d) : d(_d%MOD){
        if(d<0) d+=MOD;
    };
    friend mdint& operator+=(mdint& a, const mdint& o) {
        a.d+=o.d; if(a.d>=MOD) a.d-=MOD;
        return a;
    }
    friend mdint& operator-=(mdint& a, const mdint& o) {
        a.d-=o.d; if(a.d<0) a.d+=MOD;
        return a;
    }
    friend mdint& operator*=(mdint& a, const mdint& o) {
        return a = mdint((ll)a.d*o.d);
    }
    mdint operator*(const mdint& o) const {
        mdint res = *this;
        res*=o;
        return res;
    }
    mdint operator+(const mdint& o) const {
        mdint res = *this;
        res+=o;
        return res;
    }
    mdint operator-(const mdint& o) const {
        mdint res = *this;
        res-=o;
        return res;
    }
    mdint operator^(long long b) const {
        mdint tmp = 1;
        mdint power = *this;
        while(b) {
            if(b&1) {
                tmp = tmp*power;
            }
            power = power*power;
            b/=2;
        }
        return tmp;
    }
    friend mdint operator/=(mdint& a, const mdint& o) {
        a *= (o^(MOD-2));
        return a;
    }
    mdint operator/(const mdint& o) {
        mdint res = *this;
        res/=o;
        return res;
    }
    bool operator==(const mdint& o) { return d==o.d;}
    bool operator!=(const mdint& o) { return d!=o.d;}
    friend istream& operator>>(istream& c, mdint& a) {return c >> a.d;}
    friend ostream& operator<<(ostream& c, const mdint& a) {return c << a.d;}
};
using  mint = mdint<MD>;
void solve() {
    int n,m; cin >> n >> m;
    vi a(n); for(auto& i : a) cin >> i;
    vvi adj(n);
    for(int i=0;i<m;++i) {
        int u,v; cin >> u >> v;
        --u,--v;
        adj[u].push_back(v);
    }
    int sink=0;
    while(adj[sink].size()) ++sink;
    for(int i=0;i<n+4;++i) {
        if(*max_element(all(a))==0) {
            cout << i << '\n';
            return;
        }
        vector<bool> pos(n);
        for(int i=0;i<n;++i) pos[i]=a[i]>0;
        for(int at=0;at<n;++at) if(pos[at]) {
            for(int to : adj[at]) {
                a[to]++;
            }
            a[at]--;
        }
    }
    vector<mint> dp(n);
    vector<bool> vis(n);
    dp[sink]=1;
    vis[sink]=1;
    auto solve = [&](auto self, int at) {
        if(vis[at]) return dp[at];
        vis[at]=true;
        for(auto to : adj[at]) {
            dp[at]+=self(self,to);
        }
        return dp[at];
    };
    mint ans=n+4;
    for(int i=0;i<n;++i) {
        ans+=solve(solve,i)*a[i];
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}