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
void cmin(int& a, int b) {a=min(a,b);}
const int LEN = 5;
struct node {
    int a[LEN][LEN] = {};
    node() {}
    node(int val) {
        for(int i=0;i<LEN;++i) {
            fill(a[i],a[i]+LEN,oo);
            a[i][i]=0;
        }
        if(val==2) a[0][1]=0,a[0][0]=1;
        else if(val==0) a[1][2]=0,a[1][1]=1;
        else if(val==1) a[2][3]=0,a[2][2]=1;
        else if(val==7) a[3][4]=0,a[3][3]=1;
        if(val==6) a[4][4]=1,a[3][3]=1;
    }
    friend node merge(const node& a, const node& b) {
        if(a.a[1][0]==0) return b;
        if(b.a[1][0]==0) return a;
        node res;
        for(int i=0;i<LEN;++i) {
            fill(res.a[i],res.a[i]+LEN,oo);
        }
        for(int i=0;i<LEN;++i) for(int j=i;j<LEN;++j) for(int k=j;k<LEN;++k) {
            cmin(res.a[i][k], a.a[i][j] + b.a[j][k]);
        }
        return res;
    }
};
struct segtree {
    int ptwo;
    vector<node> seg;
    segtree(){}
    node& operator[](int i) {
        return seg[i+ptwo];
    }
    segtree(int nn) {
        ptwo=nn;
        seg.assign(ptwo*2,0);
    }
    auto query(int l, int r) {
        assert(l>=0 and l<ptwo and r >=0 and r<ptwo);
        l+=ptwo; r+=ptwo;
        node resl, resr;
        while(l and l<=r) {
            if(l%2==1) resl = merge(resl,seg[l++]);
            if(r%2==0) resr = merge(seg[r--],resr);
            l/=2; r/=2;
        }
        return merge(resl,resr);
    }
    void update(int i, int val) {
        assert(i>=0 and i<ptwo);
        i+=ptwo;
        seg[i] = node(val);
        for(i/=2;i>=1;i/=2) {
            seg[i] = merge(seg[2*i],seg[2*i+1]);
        }
    }
    void build() {
        for(int i=ptwo-1;i>=1;--i) {
            seg[i] = merge(seg[2*i],seg[2*i+1]);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    string s; cin >> s;
    segtree seg(n);
    for(int i=0;i<n;++i) seg[i] = s[i]-'0';
    seg.build();
    while(q--) {
        int a,b; cin >> a >> b;
        auto tmp = seg.query(a-1,b-1).a[0][4];
        cout << (tmp==oo?-1:tmp) << '\n';
    }
}