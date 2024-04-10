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
typedef complex<int> pt;
#define X real()
#define Y imag()
auto cross(pt u, pt v) {return (ll)u.X*v.Y-(ll)u.Y*v.X;}
auto sgn(ll a) {return a==0?0:(a>0?1:-1);}
auto ccw(pt p1, pt p2, pt p3) {auto u = p2-p1, v = p3-p2;return cross(u,v);}
auto in(pt p1, pt p2) {return (ll)p1.X*p2.X+(ll)p1.Y*p2.Y;}
auto norm(pt p) {return abs(p.X)+abs(p.Y);}
struct comp {
    bool operator()(const pt& a, const pt& b) const { return a.X<b.X or (a.X==b.X and a.Y < b.Y);}
    
};
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
void no() {
    cout << "NO\n";
}
void solve() {
        int n,m; cin >> n >> m;
        vector<string> g(n);
        for(auto& i : g) cin >> i;
        set<pt,comp> s[26];
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(g[i][j]!='.') {
                    s[g[i][j]-'a'].insert(pt{i,j});
                }
            }
        }
        auto good = [&](int i) {
            auto& ss = s[i];
            if(ss.size()<2) return true;
            auto st = *ss.begin();
            bool have=false, par = false;
            for(auto p: ss) {
                if(p!=st) {
                    auto v = (p-st);
                    if(v.X and v.Y) {
                        return false;
                    }
                    if(have) if((!!v.X)!=par) return false;
                    have = true;
                    par = !!(v.X);
                }
            }
            return true;
        };
        pair<pt,pt> ans[26];
        int sz=26;
        while(sz>0 and s[sz-1].empty()) sz--;
        for(int i=sz-1;i>=0;--i) {
            if(!good(i)) {
                cout << "NO\n";
                return;
            }
            if(s[i].size()<2) {
                if(s[i].size()==0) {
                    ans[i] = ans[i+1];
                    continue;
                }
                pt start = *s[i].begin();
                ans[i] = {start,start};
                g[start.X][start.Y]='?';
                continue;
            }
            pt start = *s[i].begin();
            pt en = *prev(s[i].end());
            ans[i] = {start,en};
            pt v = (en-start)/norm(en-start);
            int cnt=1;
            for(auto p = start;p!=en;p+=v) {
                if(g[p.X][p.Y]=='a'+i) {
                    cnt++;
                } else if(g[p.X][p.Y]!='?') {
                    cout << "NO\n";
                    return;
                }
                g[p.X][p.Y]='?';
            }
            if(cnt!=s[i].size()) {
                cout << "NO\n";
                return;
            }
            g[en.X][en.Y]='?';
        }
        cout << "YES\n";
        cout << sz << '\n';
        for(int i=0;i<sz;++i) {
            auto [start,en] = ans[i];
            start+= pt{1,1};
            en+= pt{1,1};
            cout << start.X << ' ' << start.Y << ' ' << en.X << ' ' << en.Y << '\n';
        }
}
int main() {

    int t; cin >> t;
    while(t--) {
        solve();
    }
}