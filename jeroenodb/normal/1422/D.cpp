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
bool comp(const pt& a, const pt& b) { return a.X<b.X or (a.X==b.X and a.Y < b.Y);}
bool comp2(const pt& a, const pt& b) { return a.Y<b.Y or (a.Y==b.Y and a.X < b.X);}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
auto manh(pt p) {
    return abs(p.X)+abs(p.Y);
}
auto toline(pt p) {
    return min(abs(p.X),abs(p.Y));
}
int main() {
    int MX,n; cin >> MX >> n;
    pt s,e; read(s), read(e);
    vector<pt> pts(n);
    for(auto& i : pts) read(i);
    vi orx(n); iota(all(orx),0);
    auto ory = orx;
    sort(all(orx), [&](int i,int j) {return comp(pts[i],pts[j]);});
    sort(all(ory), [&](int i,int j) {return comp2(pts[i],pts[j]);});
    vi rnkx(n),rnky(n);
    for(int i=0;i<n;++i) rnkx[orx[i]]=i,rnky[ory[i]]=i;
    vector<unsigned> dist(n, 2*oo);
    vector<unsigned> toend(n,2*oo);
    for(int i=0;i<n;++i) {
        dist[i] = toline(pts[i]-s);
        toend[i] = manh(pts[i]-e);
    }
    struct el {
        unsigned d;
        int at;
        bool operator<(const el& o) const {return d>o.d;}
    };
    priority_queue<el> pq;

    for(int i=0;i<n;++i) pq.push({dist[i],i});
    unsigned ans = manh(e-s);
    while(!pq.empty()) {
        auto c = pq.top(); pq.pop();
        if(c.d!=dist[c.at]) continue;
        ans = min(ans,toend[c.at]+c.d);
        // find edges
        auto relax = [&](int to) {
            unsigned d = toline(pts[c.at]-pts[to])+c.d;
            if(d<dist[to]) {
                dist[to]=d;
                pq.push(el{d,to});
            }
        };
        if(rnkx[c.at]!=0) {
            int to = orx[rnkx[c.at]-1];
            relax(to);
        }
        if(rnkx[c.at]!=n-1) {
            int to = orx[rnkx[c.at]+1];
            relax(to);
        }
        if(rnky[c.at]!=0) {
            int to = ory[rnky[c.at]-1];
            relax(to);
        }
        if(rnky[c.at]!=n-1) {
            int to = ory[rnky[c.at]+1];
            relax(to);
        }
    }
    cout << ans << '\n';

}