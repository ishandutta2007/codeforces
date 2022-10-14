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
const int mxN = 6e6+1, oo = 1e9;
const long long MD = 1e9+7;
template<long long MOD=MD> struct mdint {
    int d=0;
    mdint () {d=0;}
    mdint (long long _d) : d(_d%MOD){};
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vector<vector<pair<int,char>>> adj(n);
    for(int i=1;i<=m;++i) {
        int x,y; cin >> x >> y,--x,--y;
        string s = to_string(i);
        int prv=x, prv2=y;
        auto addE = [&](int i, int j, char c) {
            while(adj.size()<=max(i,j)) adj.push_back({});
            adj[i].push_back({j,c});
        };
        auto lastc = s.back(); s.pop_back();
        for(auto c : s) {
            int tmp = adj.size();
            addE(prv,tmp,c);
            prv=tmp;
            tmp = adj.size();
            addE(prv2,tmp,c);
            prv2=tmp;
        }
        addE(prv,y,lastc);
        addE(prv2,x,lastc);
    }
    int orin = n;
    n = adj.size();
    vector<bool> vis(n);
    vis[0]=true;
    vector<mint> res(n);
    string from(n,'9'+1);
    vi lab(n);
    vi q = {0,-1};
    map<char,vector<pi>> mp;
    while(!q.empty()) {
        vi nq;
        for(auto at : q) {
            if(at==-1) {
                for(auto& [c,v] : mp) {
                    for(auto [to,f] : v) {
                        if(vis[to]) continue;
                        res[to]=res[f]*10+from[to]-'0';
                        vis[to]=true;
                        nq.push_back(to);
                    }
                    nq.push_back(-1);
                }
                mp.clear();
            } else {
                for(auto [to,w] : adj[at]) if(!vis[to]) {
                    mp[w].push_back({to,at});
                    from[to] = min(from[to],w);
                }
            }
        }
        swap(q,nq);
    }
    for(int i=1;i<orin;++i) cout << res[i] << '\n';
}