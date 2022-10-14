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
struct segt {
    segt *l = NULL, * r = NULL;
    int sm, sz;
    segt(int _sz) {
        sm=_sz,sz=_sz;
    }
    int query(int x) {
        if(sz==1) return sm;
        if(!l) return x+1;
        auto mid = sz/2;
        if(x<mid) {
            return l->query(x);
        } else return r->query(x-mid)+l->sm;
    }
    void add(int i, int v) {
        if(sz==1) {
            sm+=v;
            return;
        }
        int mid = sz/2;
        if(!l) {
            l = new segt(mid);
            r = new segt(sz-mid);
        }
        if(i<mid) l->add(i,v);
        else r->add(i-mid,v);
        sm = l->sm+ r->sm;
    }
    int lb(int t) {
        if(sz==1) return 0;
        if(!l) return t-1;
        if(l->sm>=t) {
            return l->lb(t);
        } else return sz/2 + r->lb(t-l->sm);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    segt root(oo+4);
    root.add(0,-1);
    int n; cin >> n;
    int lastans=0;
    while(n--) {
        int t; cin >> t;
        // do some range updates + binary searches
        int firstsame = root.lb(t), firstbig = root.lb(t+1);
        root.add(0,1);
        root.add(firstsame,-1);
        root.add(firstbig,-1);
        int k; cin >> k;
        while(k--) {
            int x; cin >> x;
            const int MOD = 1e9+1;
            x = (x+lastans)%MOD;
            lastans = root.query(x);
            cout << lastans << '\n';

        }
    }
}