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
const int mxN = 2e5+1;
const ll oo = 1e15;
template<class T> struct splaytree {
    // flip
    #define L c[0]
    #define R c[1]
    struct node {
        T val;
        node *c[2] = {NULL,NULL}, *par =NULL;
        bool flip=false,pathtop=true;
        node(const T& v) : val(v) {}
        node() {}
    };
    static void doFlip(node* at) {
        if(!at) return;
        at->flip^=1, swap(at->c[0],at->c[1]);
    }
    static void push(node* at) {
        if(at->flip) {
            doFlip(at->L),doFlip(at->R);
            at->flip=0;
        }
        if(at->L) at->L->val.puttag(at->val.lazy);
        if(at->R) at->R->val.puttag(at->val.lazy);
        at->val.lazy=-oo;
    }
    static void recalc(node* at) {
        at->val.recalc();
        if(at->L) at->val.recalc(at->L->val);
        if(at->R) at->val.recalc(at->R->val);
    }
    static void print(node* n) {
        if(n==NULL) return;
        print(n->L);
        cout << n->val << ' ';
        print(n->R);
    }
    static void rotate(node* n) {
        // Precondition: n is not the root, Postcondition: rotates n to the place of its parent
        assert(n and !n->pathtop and n->par);
        node* par = n->par;
        push(par),push(n);
        if(!par->pathtop) {
            auto gp = par->par;
            if(gp->L==par) gp->L=n;
            else if(gp->R==par) gp->R=n;
        }
        n->par = par->par;
        bool b= n!=par->L;
        #define l c[b]
        #define r c[b^1]
        par->l = n->r; // Fix right child of current node
        if(n->r) n->r->par = par;
        n->r = par; // Put parent under current node
        #undef l
        #undef r
        par->par = n;
        swap(par->pathtop, n->pathtop);
        recalc(par),recalc(n);
    }
    static void splay(node* n) {
        while(!n->pathtop) {
            if(n->par->pathtop) {
                rotate(n);
            } else {
                auto p = n->par, gp = p->par;
                // Double rotations
                if((p->L==n) == (gp->L==p)) rotate(p);
                else rotate(n);
                rotate(n);
            }
        }
        push(n);
    }
    #undef L
    #undef R
};

struct vertex{
    ll lazy=-oo, val = -oo;
    vertex(){}
    void puttag(ll l) {
        lazy = max(lazy,l);
        // mx = max(lazy,mx);
        val = max(lazy,val);
    }
    void recalc(const vertex& o) {
        // mx = max(mx,o.mx);
    }
    void recalc() {
        // mx=val;
    }
}; 

struct iv {
    ll l,r; 
    bool operator<(const iv& o) {
        return l<o.l or (l==o.l and r<o.r);
    }
};
struct linkcut {
    // initially the linkcut tree consists of n disconnected size 1 trees.
    typedef splaytree<vertex> bst;
    typedef bst::node node;
    int n=0;
    node* t=NULL;
    linkcut() {}
    linkcut(int nn) {
        n=nn;
        t = new node[n+1];
        for(int i=0;i<=n;++i) {
            t[i] = node();
        }
    }
    node* linkback=NULL;
    vi change;
    node* expose(int u, bool special=false) {
        if(special) change.clear();
        node *at = NULL, *par = t+u;
        for(;par; at=par,par = par->par) {
            bst::splay(par);
            if(!at and special) linkback = par->c[1]?par->c[1]:par;
            if(par->c[1]) {
                par->c[1]->pathtop = true;
                par->c[1] = NULL;
            }
            if(at and special) {
                change.push_back(par-t);
            }
            if(at) at->pathtop = false;
            par->c[1] = at;
            bst::recalc(par);
        }
        bst::splay(t+u);
        return t+u;
    }
    void fix() {
        if(!linkback) return;
        bst::splay(linkback);
        while(linkback->c[1]) {
            linkback=linkback->c[1];
        }
        expose(linkback-t);
    }
    void link(int u, int v) {
        t[u].par = t+v; // connect with unmarked edge
    }
};

vector<pi> adj[mxN];
int par[mxN];
linkcut lc;

ll pref[mxN];
void dfs(int at) {
    for(auto [to,d]: adj[at]) {
        pref[to]=pref[at]+d;
        par[to]=at;
        lc.link(to,at);
        lc.expose(to);
        dfs(to);
    }
}
int main() {
    int n,m; cin >> n >> m;
    lc = linkcut(n);
    for(int i=0;i<n-1;++i) {
        int u,v,d; cin >> u >> v >> d,--u,--v;
        adj[u].emplace_back(v,d);
    }
    dfs(0);
    vector<iv> ivs;
    for(int j=0;j<m;++j) {
        int s,t; cin >> s >> t,--s;
        if(s==0) continue;
        lc.expose(s,true);

        for(auto& i : lc.change) {
            ll delta=pref[i], prev = lc.t[i].val.val;;
            ivs.push_back({max(0LL,prev+delta),t+delta});
        }
        auto path = lc.expose(par[s]);
        path->val.puttag(t);
        lc.fix();
    }
    sort(all(ivs));

    priority_queue<ll,vector<ll>,greater<ll>> pq;
    ivs.push_back(iv{oo-1,oo});
    ll t=1, limit=oo;
    for(auto& i : ivs) {
        while(!pq.empty() and t<=i.l) {
            if(t>pq.top()) {
                limit = min(limit,pq.top());
            } else t++;
             pq.pop();
        }
        t = max(i.l+1,t);
        pq.push(i.r);
    }
    int ans = ivs.size();
    for(auto& i : ivs) if(i.r>=limit) ans--;
    cout << (limit==oo?-1:limit) << ' ' << ans <<  '\n';
}