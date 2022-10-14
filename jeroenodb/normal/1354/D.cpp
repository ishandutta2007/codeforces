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
    int kth(int k) {
        int at=0;
        for(int i=1<<__lg(n);i>=1;i/=2) {
            if(at+i <= n and fen[at+i]<k) {
                k-=fen[at+i];
                at+=i;
            }
        }
        return at;
    }
    auto query(int l, int r) {
        return sum(r+1)-sum(l);
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
    fenwick<int> fen(n+1);
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        fen.update(a,1);
    }
    while(q--) {
        int k; cin >> k;
        if(k>0) {
            fen.update(k,1);
        } else {
            k=-k;
            int at = fen.kth(k);
            fen.update(at,-1);
        }
    }
    if(fen.query(0,n)==0) {
        cout << "0\n";
    } else cout << fen.kth(1) << '\n';
}