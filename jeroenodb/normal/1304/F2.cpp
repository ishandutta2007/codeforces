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
void cmax(int& a, int b) { a= max(a,b);}
struct segtree {
    int ptwo;
    vector<int> seg;
    segtree(){}
    int& operator[](int i) {
        return seg[i+ptwo];
    }
    segtree(int nn) {
        ptwo=nn;
        seg.assign(ptwo*2,0);
    }
    auto query(int l, int r) {
        if(l>r) return -oo;
        l = max(l,0), r = min(r,ptwo-1);
        l+=ptwo; r+=ptwo;
        int res = -oo;
        while(l and l<=r) {
            if(l%2==1) res = max(res,seg[l++]);
            if(r%2==0) res = max(res,seg[r--]);
            l/=2; r/=2;
        }
        return res;
    }
    void build() {
        for(int i=ptwo-1;i>0;--i) {
            seg[i] = max(seg[i*2],seg[i*2+1]);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k; cin >> n >> m >> k;
    // initial dp
    int P = m-k+1;
    vi dp(P);
    {
        vi p(m+1);
        for(int i=1;i<=m;++i) {
            cin >> p[i],p[i]+=p[i-1];
            if(i-k>=0) dp[i-k]=p[i]-p[i-k];
        }
    }
    for(int rep=0;rep<n-1;++rep) {
        vi ndp(P);
        vi p(m+1);
        for(int i=1;i<=m;++i) {
            cin >> p[i],p[i]+=p[i-1];
        }
        segtree top(P),bot(P),disj(P);
        for(int i=0;i<P;++i) {
            top[i] = p[i+k]+dp[i], bot[i] = dp[i]-p[i], disj[i] = dp[i]+p[i+k]-p[i];
        }
        top.build(),bot.build(),disj.build();
        for(int i=0;i<P;++i) {
            cmax(ndp[i],disj.query(0,i-k));
            cmax(ndp[i],disj.query(i+k,P-1));
            ndp[i]+=p[i+k]-p[i];
            cmax(ndp[i], bot.query(i-k,i)+p[i+k]);
            cmax(ndp[i], top.query(i,i+k)-p[i]);
        }
        swap(dp,ndp);
    }
    cout << *max_element(all(dp)) << '\n';
}