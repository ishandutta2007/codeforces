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
const int LG=20, mxN = 1<<LG, oo = 1e9;
struct  __attribute__ ((packed)) segtree {
    segtree *l=NULL, *r = NULL;
    int len=1, lsb=0,msb=0;
    bool allones=true, allzeros=true;
    
    static void precomp();
    int firston(int i);
    segtree* set(int a,int b, bool v);
    void pull();
};
segtree zeros[LG],ones[LG];
segtree* unity;
segtree* mem = new segtree[mxN*18];
int pp=0;
segtree* newseg() {
    auto* tmp = mem + (pp++);
    *tmp = segtree();
    return tmp;
}
void segtree::precomp() {
    zeros[0].allones=false;
    zeros[0].lsb=oo;
    zeros[0].msb=-oo;
    ones[0].allzeros=false;
    for(int i=1;i<LG;++i) {
        zeros[i].l=zeros[i].r=&zeros[i-1];
        ones[i].l=ones[i].r=&ones[i-1];
        zeros[i].pull(),ones[i].pull();
    }
    unity = &ones[0];
    for(int i=1;i<LG-1;++i) {
        auto tmp = newseg();
        tmp->l = unity, tmp->r = &zeros[i-1];
        tmp->pull();
        unity = tmp;
    }
    auto tmp = newseg();
    tmp->l = &zeros[LG-2], tmp->r = unity;
    unity = tmp;
    unity->pull();
}


int segtree::firston(int i) {
    if(len==1) return 0;
    if(l->msb<i) {
        return r->firston(i-len/2)+len/2;
    } else return l->firston(i);
}
segtree* segtree::set(int a,int b, bool v) { // range set
    if(a>=len or b<0) 
        return this;
    if(a<=0 and len-1<=b) 
        return v?&ones[__lg(len)]:&zeros[__lg(len)];
    auto nw = newseg();
    nw->l = l->set(a,b,v), nw->r = r->set(a-len/2,b-len/2,v);
    nw->pull();
    return nw;
}
void segtree::pull() {
    allones = l->allones and r->allones;
    allzeros = l->allzeros and r->allzeros;
    lsb = oo;
    len = l->len+r->len;
    if(!l->allzeros) lsb = l->lsb;
    else if(!r->allzeros) lsb = min(oo,len/2+r->lsb);
    msb = -oo;
    if(!r->allzeros) msb = r->msb+len/2;
    else if(!l->allzeros) msb = l->msb; 
}


int t=-1;
struct creature {
    int exp[2] = {0,-(1<<(LG-2))};
    int dead=-1;
    segtree* sg = NULL;
    creature() {
        sizeof(mem);
        sg=unity;
    }
    void sub(int pw) {
        pw-=exp[1];
        // check if pw > biggest one
        int b = sg->msb;
        if(b<pw) {
            sg = &zeros[LG-1];
        } else {

            // find first one bigger than it
            // change:  000000001 to
            //          111111110
            int i = sg->firston(pw);
            sg = sg->set(i,i,0);
            sg = sg->set(pw,i-1,1);
        }
        if(sg->allzeros) {
            dead = t;
        }
    }
    creature(const creature& o) {
        exp[0]=o.exp[0],exp[1]=o.exp[1];
        dead = o.dead;
        sg = o.sg;
    }
};
int main() {
    segtree::precomp();
    int n; cin >> n;
    vector<creature> cs;
    for(t=1;t<=n;++t) {
        int tp; cin >> tp;
        if(tp==1) {
            cs.push_back(creature());
        } else {
            int i; cin >> i,--i;
            if(tp==5) {
                int j; cin >> j,--j;
                if(cs[i].dead==-1 and cs[j].dead==-1) {
                    cs[i].sub(cs[j].exp[0]);
                    cs[j].sub(cs[i].exp[0]);
                }
            } else {
                if(tp==2 and cs[i].dead==-1) cs[i].exp[0]++;
                if(tp==3 and cs[i].dead==-1) cs[i].exp[1]++;
                if(tp==4) { 
                    cs.emplace_back(cs[i]);
                    if(cs.back().dead!=-1) cs.back().dead=t;
                }
            }
        }
    }
    cout << cs.size() << '\n';
    for(auto i : cs) {
        cout << i.dead << ' ';
    } cout << '\n';
}