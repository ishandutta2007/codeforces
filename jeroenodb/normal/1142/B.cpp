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
const int mxN = 2e5+1, oo = 1e9;
struct RMQ {
    int mn[19][mxN*2]={};
    int sz=0;
    void build() {
        for(int i=1;(1<<i)<=sz;++i) {
            int len = 1<<i, len2 = len/2;
            for(int j=0;j+len-1<sz;++j) {
                mn[i][j] = min(mn[i-1][j], mn[i-1][j+ len2]);
            }
        }
    }
    int query(int a, int b) {
        if(a>b) swap(a,b);
        int dif = b-a+1;
        int i = __lg(dif);
        return min(mn[i][a],mn[i][b-(1<<i)+1]);
    }
} rmq;

int jump[20][mxN];
int go(int at, int delta) {
    for(int i=0;1<<i <= delta;++i) {
        if(1<<i & delta) {
            at = jump[i][at];
        }
    }
    return at;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,q; cin >> n >> m >> q;
    rmq.sz = m;
    vi rank(n);
    for(int i=0;i<n;++i) {
        int j; cin >> j;--j;
        rank[j] = i;
    }
    vi a(m);
    for(auto& i: a) {
        cin >> i; 
        i = rank[i-1];
    }
    // calculate all jumps of length 1
    fill(all(rank),m);
    jump[0][m] = m;
    for(int i=m-1;i>=0;--i) {
        int nxt = a[i]+1;
        if(nxt==n) nxt=0;
        jump[0][i] = rank[nxt];
        rank[a[i]] = i;
    }
    for(int i= 1;(1<<i)<n;++i) {
        for(int j=0;j<=m;++j) {
            jump[i][j] = jump[i-1][jump[i-1][j]];
        }
    }
    for(int i=0;i<m;++i) {
        rmq.mn[0][i] = go(i,n-1);
    }
    rmq.build();
    string ans(q,'?');
    for(int i=0;i<q;++i) {
        int l,r; cin >> l >> r;--l,--r;
        ans[i] = '0'+(rmq.query(l,r)<=r);
    } cout << ans << '\n';

}