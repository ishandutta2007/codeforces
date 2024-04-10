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
template<typename T> struct fenwick {
    int n;
    vector<T> fen;
    fenwick(){}
    fenwick(int nn) {
        fen.resize(nn+1);
        n = nn;
    }
    auto sum(int i) {
        T ans = 0;
        while(i) {
            ans+=fen[i];
            i&=i-1;
        }
        return ans;
    }
    auto query(int l, int r) {
        return sum(r+1)-sum(l);
    }
    int firstbad(T i) {
        // find first prefix sum < i
        int jmp = 1<<__lg(n), at = 0;
        while(jmp>0) {
            if(at+jmp<=n and fen[at+jmp]>=i) {
                i-=fen[at+jmp];
                at+=jmp;
            }
            jmp/=2;
        }
        return at;
    }
    void update(int i, T val) {
        ++i;
        while(i<=n) {
            fen[i]+=val;
            i+= i&(-i);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    vi nxt(q,-1), head(n,-1), l(q);
    vi a(n); for(auto& i : a) cin >> i;
    for(int i=0;i<q;++i) {
        int r; cin >> l[i] >> r;
        r=n-r-1;
        nxt[i] = head[r];
        head[r]=i;
    }
    vi ans(q);
    fenwick<int> fen(n+1);
    for(int i=0;i<n;++i) {
        a[i] = i+1-a[i];
        if(a[i]<0) a[i]=oo;
        int toadd = fen.firstbad(a[i]);
        toadd = min(toadd,i+1);
        fen.update(0,1);
        fen.update(toadd,-1);
        for(auto j =head[i];j!=-1;j=nxt[j]) {
            ans[j] = fen.query(0,l[j]);

        }
    }
    for(auto i : ans) cout << i << '\n';
}