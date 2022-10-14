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
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
const int MX = 1e6+2;
struct info{
    int a=0,sz=1,mn=oo,mx=-oo;
    info(){}
    bool operator<(const info& o) const {return a<o.a;}
    bool operator>(const info& o) const {return a>o.a;}
    info(int v) : a(v) {
        recalc();
    }
    void recalc(const info& o, bool l=true) {
        if(l) {
            mn = min(mn-o.sz,o.mn);
        } else mn = min(mn,o.mn-sz);
        mx = max(mx,o.mx);
        sz+=o.sz;

    }
    void recalc() {
        mx = a,sz=1;
        mn = a-1;
    }
}; 
struct splaytree {
    // flip
    #define l c[b]
    #define r c[b^1]
    #define L c[0]
    #define R c[1]
    struct node {
        info val;
        node *c[2] = {NULL,NULL}, *par =NULL;
        node(const info& v) : val(v) {}
        node() {}
        bool isroot() {return par==NULL;}
    };
    node* root = NULL;
    node* insert(const info& val) {
        // insertion
        auto nw = new node(val);
        if(!root) {
            return root=nw;
        }
        node* cur = root;
        while(true) {
            if(val < cur->val) {
                if(cur->L) cur = cur->L;
                else {
                    cur->L = nw;
                    nw->par = cur;
                    break;
                }
            } else {
                if(cur->R) cur = cur->R;
                else {
                    cur->R = nw;
                    nw->par = cur;
                    break;
                }
            }
        }
        splay(nw);
        return nw;
    }
    int sz(node* at) {
        return at?at->val.sz:0;
    }
    bool good() {
        auto at = root;
        assert(at!=NULL);
        int num=0;
        while(at) {
            num-=sz(at->L);
            if(at->L and at->L->val.mx>=num) {
                num+=sz(at->L);
                at = at->L;
            } else {
                num--;
                if(at->val.a >= num) {
                    splay(at);
                    return true;
                } else {
                    if(!at->R) splay(at);
                    at = at->R;
                }
            }
        }
        return false;

    }
    static void recalc(node* at) {
        at->val.recalc();
        if(at->L) at->val.recalc(at->L->val); 
        if(at->R) at->val.recalc(at->R->val,false);
    }
    // static void print(node* n) {
    //     if(n==NULL) return;
    //     print(n->L);
    //     cout << n->val << ' ';
    //     print(n->R);
    // }
    static void rotate(node* n) {
        // Precondition: n is not the root, Postcondition: rotates n to the place of its parent
        // assert(n and !n->isroot() and n->par);
        node* par = n->par;
        if(!par->isroot()) {
            auto gp = par->par;
            if(gp->L==par) gp->L=n;
            else if(gp->R==par) gp->R=n;
        }
        n->par = par->par;
        bool b= n!=par->L;
        par->l = n->r; // Fix right child of current node
        if(n->r) n->r->par = par;
        n->r = par; // Put parent under current node
        par->par = n;
        recalc(par);
        recalc(n);
    }
    void splay(node* n) {
        while(!n->isroot()) {
            if(n->par->isroot()) {
                rotate(n);
            } else {
                auto p = n->par, gp = p->par;
                // Double rotations
                if((p->L==n) == (gp->L==p)) {
                    rotate(p);
                } else {
                    rotate(n);
                }
                rotate(n);
            }
        }
        // assert(n->isroot());
        root = n;
    }
    #undef l
    #undef r
    // #undef L
    // #undef R
};


int main() {
    // add it, then simulate?
    // do it with segment trees that say where values go to.
    // and then some searches and range updates
    // still nope
    // analyze process
    // binary search where a_i's meet.
    // then do something
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    splaytree tree;
    int n; cin >> n;
    while(n--) {
        int a; cin >> a;
        tree.insert({a});
        // now do the whole thing
        
        if(tree.good()) {
            auto rt = tree.root;
            auto l = rt->L;
            rt->L = NULL;
            tree.recalc(rt);
            int start = -tree.sz(l);
            cout << min(start,rt->val.mn) + rt->val.sz << '\n';
            rt->L = l;
            tree.recalc(rt); 
        } else {
            auto rt = tree.root;
            cout << -tree.sz(rt) << '\n';
        }
    }

}