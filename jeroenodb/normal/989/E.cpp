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
const int CONV = 31;
#define rep(i,n) for(int i=0;i<n;++i)
struct mat {
    double m[200][200] = {};
    void eye() {
        rep(i,200) m[i][i]=1;
    }
    mat operator*(const mat& o) {
        mat res;
        rep(i,200) rep(j,200) rep(k,200) {
            res.m[i][k]+=m[i][j]*o.m[j][k];
        }
        return res;
    }
} probs[CONV];
typedef complex<int> pt;
#define X real()
#define Y imag()
auto cross(pt u, pt v) {return (ll)u.X*v.Y-(ll)u.Y*v.X;}
auto sgn(ll a) {return a==0?0:(a>0?1:-1);}
auto ccw(pt p1, pt p2, pt p3) {auto u = p2-p1, v = p3-p1;return cross(u,v);}
auto in(pt p1, pt p2) {return (ll)p1.X*p2.X+(ll)p1.Y*p2.Y;}
auto norm(pt p) {return (ll)p.X*p.X+(ll)p.Y*p.Y;}
bool comp(const pt& a, const pt& b) { return a.X<b.X or (a.X==b.X and a.Y < b.Y);}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
int main() {
    int n; cin >> n;
    probs[0].eye();
    vector<pt> pts(n);
    for(auto& i : pts) read(i);
    vvi init;
    for(int i=0;i<n;++i) {
        
        map<pi, vi> mp;
        for(int j=0;j<n;++j) if(i!=j) {
            auto v = pts[j]-pts[i];
            v/=gcd(v.X,v.Y);
            if(comp(v,pt{0,0})) v*=-1;
            mp[{v.X,v.Y}].push_back(j);
        }
        double lines = mp.size();
        for(auto& [vec,v] : mp) {
            v.push_back(i);
            double num = v.size(), prob = 1/(lines*num);
            for(auto j : v) probs[1].m[i][j] += prob;
            init.push_back(v);
        }
    }
    for(int i=1;i<CONV;++i) {
        probs[i] = probs[i-1]*probs[1];
    }
    // precompute of marcov chain done
    // compute initial vectors (not needed). Pick 
    int q; cin >> q;
    while(q--) {
        int t,m; cin >> t >> m;
        m = min(m-1,CONV-1), --t;
        vector<double> prob(n);
        for(int i=0;i<n;++i) {
            prob[i] = probs[m].m[i][t];
        }
        // for each of O(n^2) initial vectors
        // how many nonzeros? O(n^2)
        double best = 0;
        for(auto candidate : init) {
            double cur=0;
            for(auto& i : candidate) {
                cur+=prob[i];
            }
            cur/=candidate.size();
            best = max(cur,best);
        }
        cout << setprecision(10) << best << '\n';
    }
}