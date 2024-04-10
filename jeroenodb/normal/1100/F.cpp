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
const int mxN = 5e5+1, oo = 1e9;
struct node {
    array<int,20> b = {};
    int sz=0;
    node() {
        *this = node(0);
    }
    node(int val) {
        b[0] = val;
        sz = val!=0;
    }
    void merge(int h) {
        if(sz==20) return;
        for(int i=0;i<sz;++i) {
            int k = __lg(b[i]);
            if(h&1<<k) h^=b[i];
        }
        if(h) 
            b[sz++]=h;
    }
    void merge(const node& o) {
        if(sz==0 or o.sz == 20) {
            b=o.b;
            sz=o.sz;
            return;
        } 
        if(sz==20) return;
        for(int j=0;j<o.sz and sz!=20;++j) {
            int h = o.b[j];
            for(int i=0;i<sz;++i) {
                int k = __lg(b[i]);
                if(h&1<<k) h^=b[i];
            }
            if(h) 
                b[sz++]=h;
        }
    }
    friend node merge(node a, const node& b) {
        a.merge(b);
        return a;
    }
};

const int B = 20;
node jmp[B][mxN/B];
node query(int l, int r) {
    int len = r-l+1;
    int lg = __lg(len);
    if(len==1<<lg) return jmp[lg][l];
    return merge(jmp[lg][l], jmp[lg][r-(1<<lg)+1]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vi b(n);
    for(int i=0;i<n;++i) {
        int a;cin >> a;
        b[i]=a;
        jmp[0][i/B].merge(node(a));
    }
    for(int j=1;j<=B;++j) {
        int len = 1<<j;
        for(int i=0;i+len<=n/B;++i) {
            jmp[j][i] = merge(jmp[j-1][i],jmp[j-1][i+len/2]);
        }
    }
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r,--l,--r;
        node nd;
        while(l<=r and l%B!=0) {
            nd.merge(b[l++]);
        }
        while(l<=r and r%B!=B-1) {
            nd.merge(b[r--]);
        }
        if(r-l>=B-1) nd.merge(query(l/B,r/B));
        unsigned res=0;
        for(int i=0;i<nd.sz;++i) {
            if((res^nd.b[i])>res) {
                res^=nd.b[i];
            }
        }
        cout << (-1U)-(-1U^res) << '\n';
    }
}