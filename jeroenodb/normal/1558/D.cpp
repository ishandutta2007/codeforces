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
const long long MOD = 998244353;
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
    bool operator==(const mint& o) {
        return d==o.d;
    }
    friend mint& operator+=(mint& a, const mint& o) {
        a.d+=o.d;
        if(a.d>=MOD) a.d-=MOD;
        return a;
    }
};
const int mxN = 1e5+1, oo = 1e9;
const int mxF=1e6;
mint fact[mxF], ifact[mxF];
mint c(int a, int b) {
    if(b>a or a<0) return 0;
    return fact[a]*ifact[b]*ifact[a-b];
}
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
struct Node{
    Node* kids[2] = {};
    int priority,v,lazy=0;
    Node(int vv) {
        v=vv;
        priority = rnd(0,oo);
    }
    void prop() {
        if(!lazy) return;
        if(kids[0]) {
            kids[0]->lazy+=lazy;
        }
        if(kids[1]) {
            kids[1]->lazy+=lazy;
        }
        v+=lazy;
        lazy=0;
    }
    static int val(Node* nd) {
        return nd?nd->v+nd->lazy:-oo;
    }
    array<Node*,2> split(int x) { // < v | >=v
        prop();
        if(val(this)>=x) {
            if(kids[0]==NULL) {
                return {NULL,this};
            }
            auto ans = kids[0]->split(x);
            kids[0]=ans[1];
            return {ans[0],this};
        } else {
            if(kids[1]==NULL) {
                return {this,NULL};
            }
            auto ans = kids[1]->split(x);
            kids[1]=ans[0];
            return {this,ans[1]};
        }
    }
    int size() {
        int res=1;
        if(kids[0]) res+=kids[0]->size();
        if(kids[1]) res+=kids[1]->size();
        return res;
    }
};

Node* merge(Node* a, Node* b) {
    if(a==NULL) return b;
    if(b==NULL) return a;
    a->prop();
    b->prop();
    if(a->priority<b->priority) {
        a->kids[1] = merge(a->kids[1],b);
        return a;
    } else {
        b->kids[0] = merge(a,b->kids[0]);
        return b;
    }
}

void precomp() {
    fact[0]=1;
    for(int i=1;i<mxF;++i) {
        fact[i]=fact[i-1]*i;
    }
    ifact[mxF-1] = mint(1)/fact[mxF-1];
    for(int i=mxF-2;i>=0;--i) {
        ifact[i]=ifact[i+1]*(i+1);
    }
}
int main() {
    precomp();
    int t; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        vector<pi> x(m);
        Node* rt = NULL;
        for(auto& [a,b] : x) {
            cin >> a >> b;
            if(rt) {
                auto p = rt->split(b);
                if(p[1]) {
                    auto p2 = p[1]->split(b+1);
                    if(p2[0]) {
                        p2[0] = merge(p2[0],p2[1]);
                        p2[0]->lazy++;
                        rt = merge(p[0],p2[0]);
                    } else {
                        p2[1] = merge(new Node(b), p2[1]);
                        p2[1]->lazy+=1;
                        rt = merge(p[0], p2[1]);
                    }
                } else rt = merge(p[0], new Node(b+1));
            } else rt = new Node(b+1);
        }
        int k = n;
        if(rt) k= n-rt->size();
        mint res = c(k+n-1,k)*k/mint(n);
        cout << res.d << '\n';
    }
}