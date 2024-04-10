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
const int LG = 17, mxN = 1<<LG, oo = 1e9;
const long long MOD = 1e9+7;

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
    bool operator==(const mint& o) const {
        return d==o.d;
    }
    friend mint& operator+=(mint& a, const mint& o) {
        a.d+=o.d;
        if(a.d>=MOD) a.d-=MOD;
        return a;
    }

};
mint pw[LG+1], hpw[LG+1];
struct node;
node *zeros, *ones;
struct node {
    mint hash=0;
    node* l=NULL, *r=NULL;
    static mint H(node* nd) {
        return nd?nd->hash:0;
    }
    static void init() {
        ones = new node[LG+1], zeros = new node[LG+1];
        ones[0].hash=1,zeros[0].hash=0;
        pw[0] = 2, hpw[0] = 134567;
        for(int i=1;i<=LG;++i) {
            ones[i].l=ones[i].r = ones+i-1;
            zeros[i].l=zeros[i].r = zeros+i-1;
            pw[i]=pw[i-1]*pw[i-1], hpw[i]=hpw[i-1]*hpw[i-1];
            ones[i].recalc(i), zeros[i].recalc(i);

        }
    }
    void recalc(int i) {
        hash = H(l)+hpw[i-1]*H(r);
    }
    bool operator==(const node& o) {
        return hash==o.hash;
    }
    int findzero(int j, int i=LG) const {
        int len = 1<<i;
        if(zeros[i]==*this) return j;
        if(ones[i]==*this) return oo;
        if(j<len/2) {
            int tmp = l->findzero(j,i-1);
            if(tmp!=oo) return tmp;
            return min(oo,r->findzero(0, i-1)+len/2);
        }
        return min(oo,r->findzero(j-len/2,i-1)+len/2);
    }
    friend bool comp(const node* a, const node* b) {
        if(a->hash==b->hash) return false;
        int i=LG;
        while(i--) {
            if(a->r->hash==b->r->hash) a=a->l,b=b->l;
            else a=a->r, b=b->r;
        }
        return a->hash.d<b->hash.d;
    }
    friend node* make100(node* at, int l, int r, int i = LG) {
        int len = 1<<i;
        // base cases
        if(r<0 or l>=len) return at;
        if(l<=0 and len-1<r) return zeros+i;
        if(r==0 and len==1) return ones+i;
        node* res = new node;
        res->l = make100(at->l,l,r,i-1);
        res->r = make100(at->r,l-len/2,r-len/2,i-1);
        res->recalc(i);
        return res;
    }
    friend node* add(node* a, int b) {
        int j = a->findzero(b);
        // make j 1, and [j+1:a] 0
        assert(j!=oo);
        return make100(a,b,j);
    }
    mint mod(int i = LG) {
        int len = 1<<i;
        if(len==1) return hash;
        return l->mod(i-1)+pw[i-1]*r->mod(i-1);
    }
};


vector<pi> adj[mxN];
int main() {
    int n,m; cin >> n >> m;
    for(int i=0;i<m;++i) {
        int a,b,w; cin >> a >> b >> w,--a,--b;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    int s,t; cin >> s >> t,--s,--t;
    vi par(n,-1);
    node::init();
    vector<node*> dist(n,ones+LG);
    dist[s] = zeros+LG;
    struct el {
        int at;
        node* d;
        bool operator<(const el& o) const {return comp(o.d,d);}
    };
    priority_queue<el> pq;
    pq.push({s,dist[s]});
    while(!pq.empty()) {
        auto c = pq.top(); pq.pop();
        if(dist[c.at]!=c.d) continue;
        for(auto [to,w]: adj[c.at]) {
            auto tmp = add(c.d,w);
            // debug(c.at);
            // assert(comp(c.d,tmp));
            if(comp(tmp,dist[to])) {
                par[to]=c.at;
                dist[to]=tmp;
                pq.push(el{to,tmp});
            }
        }
    }
    if(dist[t]==ones+LG) {
        cout << "-1\n";
    } else {
        cout << dist[t]->mod().d << '\n';
        int at = t;
        vi ans;
        while(at!=-1) {
            ans.push_back(at+1);
            at = par[at];
        }
        reverse(all(ans));
        cout << ans.size() << '\n' << ans << '\n';
    }
}