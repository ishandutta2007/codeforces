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
struct node {
    ll a=0,b=0;
    node *l=NULL,*r=NULL;
    int len=0;
    ll query(int x) {
        int mid = len/2;
        ll res = a*x+b;
        if(x<mid) {
            if(l) res+=l->query(x);
        } else {
            if(r) res+=r->query(x-mid);
        }
        return res;
    }
};
node *mem = new node[int(3e7)];

int pp=0;

node* newnode() {
    return mem+(pp++);
}

void update(node*& at, int a, ll b, int l, int r, bool nw = true) {
    if(r<0) return;
    if(l>=at->len) return;
    if(nw) {
        auto tmp = newnode();
        *tmp=*at;
        at=tmp;
    }
    if(l<=0 and r>=at->len) {
        at->a+=a;
        at->b+=b;
        return;
    }
    int mid = at->len/2;

    if(l<mid) {
        bool nwnw=true;
        if(!at->l) {
            nwnw=false;
            at->l = newnode();
            at->l->len = mid;
        }
        update(at->l,a,b,l,r,nwnw);
    }
    if(r>mid) {
        bool nwnw=true;
        if(!at->r) {
            nwnw=false;
            at->r = newnode();
            at->r->len = at->len- mid;
        }
        update(at->r,a,b+a*mid,l-mid,r-mid,nwnw);
    }
};
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
const int MX = 2.1e5+1;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<node*> roots = {newnode()};

    roots.back()->len=MX;
    int n=7.5e4; 
    cin >> n;
    node* rt = roots.back();
    while(n--) {
        int x[2] = {rnd(0,1345),rnd(4345,100000)},y[2] = {rnd(0,oo),rnd(0,oo)},a=rnd(0,int(1e4)),b=rnd(0,int(1e4));
        cin >> x[0] >> x[1] >> y[0] >> a >> b >> y[1];
        update(rt,0,y[0],0,x[0]+1);
        update(rt,a,b,x[0]+1,x[1]+1);
        update(rt,0,y[1],x[1]+1,oo*2);
        roots.push_back(rt);
    }
    // cout << "DONE" << endl;
    int m; cin >> m;
    ll ans=0;
    while(m--) {
        int l,r,x; cin >> l >> r >> x;
        x = (ans+x)%int(1e9);
        x = min(x,MX-1);
        --l;
        ans = roots[r]->query(x)-roots[l]->query(x);
        cout << ans << '\n';
    }
}