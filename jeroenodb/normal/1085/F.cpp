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
const string names = "RPS";
#define rep(i,n) for(int i=0;i<n;++i)
struct node {
    int cnt[3][3][3] = {};
    bool have[3] = {};
    node() {
        
    }
    node(char c) {
        int id = names.find(c);
        have[id]=true;
        cnt[id][0][0]=1;
    }
    int ans() {
        int res=0;
        rep(k,3) for(int i : {0,2}) for(int j : {0,2}) {
            res+=cnt[k][i][j];
        }
        return res;
    }
    friend node merge(const node& a, const node& b) {
        node r;
        rep(i,3) r.have[i] = a.have[i] or b.have[i];
        rep(i,3) rep(j,3) rep(k,3) {
            int tmp = a.cnt[i][j][k];
            if(b.have[(i+2)%3]) r.cnt[i][j][2]+=tmp;
            else if(b.have[(i+1)%3]) r.cnt[i][j][max(k,1)]+=tmp;
            else r.cnt[i][j][k]+=tmp;

            tmp = b.cnt[i][k][j];
            if(a.have[(i+2)%3]) r.cnt[i][2][j]+=tmp;
            else if(a.have[(i+1)%3]) r.cnt[i][max(k,1)][j]+=tmp;
            else r.cnt[i][k][j]+=tmp;
        }
        return r;
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
        ptwo=1;
        while(ptwo<nn) ptwo*=2;
        seg.assign(ptwo*2,{});
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
    void update(int i, char val) {
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
    segtree seg(n);
    for(int i=0;i<n;++i) {
        char a; cin >> a;
        seg[i] = node(a);
    }
    seg.build();
    cout << seg.seg[1].ans() << '\n';
    while(q--) {
        int i; char c; cin >> i >> c;
        seg.update(i-1,c);
        cout << seg.seg[1].ans() << '\n';
    }
}