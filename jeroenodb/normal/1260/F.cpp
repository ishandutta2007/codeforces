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

#ifndef LOCAL
const int mxN = 1e5+1, oo = 1e9;
#else
const int mxN = 3e3+1, oo = 1e9;
#endif
int n;
template<typename Edge>
class GraphIterator {
public:
    class OutgoingEdges {
    public:
        OutgoingEdges(const GraphIterator *g, int l, int r): g(g), l(l), r(r) {
        }

        const Edge* begin() const {
            if (l == r) {
                return 0;
            }
            return &g->prepared_edges[l];
        }

        const Edge* end() const {
            if (l == r) {
                return 0;
            }
            return &g->prepared_edges[r];
        }

    private:
        int l, r;
        const GraphIterator *g;
    };

    void add_edge(int from, const Edge &e) {
        edges.push_back({from, e});
    }

    void prepare() {
        int n = 0;
        for (const auto &e : edges) {
            n = max(n, e.first);
        }
        n += 2;
        start.resize(n);
        for (const auto &e : edges) {
            ++start[e.first + 1];
        }
        for (int i = 1; i < n; ++i) {
            start[i] += start[i - 1];
        }
        prepared_edges.resize(edges.size() + 1);
        auto counter = start;
        for (const auto &e : edges) {
            prepared_edges[counter[e.first]++] = e.second;
        }
    }

    OutgoingEdges operator [] (int from) const {
        if (from < 0 || from + 1 >= start.size()) {
            return {this, 0, 0};
        }
        return {this, start[from], start[from + 1]};
    }

private:
    vector<Edge> prepared_edges;
    vector<pair<int, Edge>> edges;
    vector<int> start;
};
GraphIterator<int> adj;
struct myQ {
    int q[mxN];
    int sz=0;
    int size(){return sz;}
    void clear() {
        sz=0;
    }
    void push_back(int a) {
        q[sz++]=a;
    }
    int* begin() {
        return q;
    }
    int* end() {
        return q+sz;
    }
    int& operator[](int i) {
        return q[i];
    }
};
const long long MD = 1e9+7;
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
namespace CD {
    bitset<mxN> mark;
    int par[mxN],sz[mxN], cs[mxN], dist[mxN][20];
    struct DS {
        mint sumd = {}, occ = {};
        void add(int d,mint a) {
            sumd+=a*d;
            occ+=a;
        }
        mint query(int d) {
            return sumd+occ*d;
        }
    };
    DS ds1[mxN],ds2[mxN];
    myQ q;
    void dfsz(int s) {
        auto process = [&](int to) {
            if(mark[to]) return;
            mark[to]=true;
            q.push_back(to);
        };
        process(s);
        for(int i=0;i<(int)q.size();++i) {
            auto at = q[i];
            for(auto to : adj[at]) process(to);
        }
        for(int i=q.size()-1;i>=0;--i) {
            auto at = q[i];
            mark[at]=false;
            sz[at]=1;
            for(auto to : adj[at]) if(!mark[to]) sz[at]+=sz[to];
        }
        q.clear();
    }
    int dep=0;
    void dfsD(int s) {
        auto process = [&](int to, int d) {
            if(mark[to]) return;
            dist[to][cs[to]++]=d+1;
            mark[to]=true;
            q.push_back(to);
        };
        process(s,-1);
        for(int i=0;i<(int)q.size();++i) {
            auto at = q[i], d = dist[at][cs[at]-1];
            for(auto to : adj[at]) process(to,d);
        }
        for(auto i : q) mark[i]=false;
        q.clear();
    }
    int centroid(int at) {
        bool done=false;
        int total=sz[at],from=at;
        while(!done) {
            done=true;
            for(int to: adj[at]) if(to!=from and !mark[to]) {
                if(sz[to]*2>total) {
                    done=false;
                    from = at;
                    at = to;
                    break;
                }
            }
        }
        return at;
    }
    void decomp(int at, int from=-1) {
        dfsz(at);
        int c = centroid(at);
        par[c] = from;
        mark[c] = true;
        for(int to: adj[c]) if(!mark[to]) 
            decomp(to,c);
        mark[c]=false;
        dfsD(c);
    }

    void update(int at, mint a) {
        int c = at, dd = 0;
        int num=0;
        while(c!=-1) {
            ds1[c].add(dd,a);
            int nd = dist[at][++num];
            if(par[c]!=-1) ds2[c].add(nd,a);
            dd=nd;
            c = par[c];
        }
    }

    mint query(int at) {
        mint ans = 0;
        int c = at, dd = 0,num=0;
        while(c!=-1) {
            ans+=ds1[c].query(dd);
            int nd = dist[at][++num];
            if(par[c]!=-1) ans-=ds2[c].query(nd);
            dd=nd;
            c = par[c];
        }
        return ans;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<pi> updates;
    updates.reserve(2*n);
    vector<mint> inv(n+1);
    mint total=1;
    for(int i=1;i<=n;++i) {
        int a,b; cin >> a >> b;
        inv[i] = mint(1)/(b-a+1);
        total*=(b-a+1);
        updates.push_back({a,i});
        updates.push_back({b+1,-i-1});
    }
    sort(all(updates));
    for(int i=0;i<n-1;++i) {
        int a,b; cin >> a >> b;
        adj.add_edge(a,b);
        adj.add_edge(b,a);
    }
    adj.prepare();
    CD::decomp(1);
    mint ans=0,cur=0;
    auto it = updates.begin();
    for(int i=1;i<=int(1e5);++i) {
        while(it!=updates.end() and it->first<=i) {
            auto [val,at] = *it;
            mint sgn=1;
            if(at<0) {
                at = -(at+1);
                sgn=-1;
            }
            cur+=CD::query(at)*inv[at]*sgn;
            CD::update(at,inv[at]*sgn);
            ++it;
        }
        ans+=cur;
    }
    ans*=total;
    cout << ans.d << '\n';

}