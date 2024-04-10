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
    int t; cin >> t;
    while(t--) {
        int n,k; cin >> n >> k;
        vi a(2*n,-1);
        for(int i=0;i<k;++i) {
            int x,y; cin >> x >> y;
            a[x-1]=y-1, a[y-1]=x-1;
        }
        int o=-1;
        for(int i=0;i<n-k;++i) {
            ++o;
            while(o<2*n and a[o]!=-1) {
                ++o;
            }
        }
        ++o;
        for(int i=0;i<2*n;++i) {
            while(o<2*n and a[o]!=-1) {
                ++o;
            }
            if(a[i]==-1) {
                a[i]=o;
                a[o]=i;

            }
        }
        // count intersections
        fenwick<int> fen(2*n);
        ll ans = 0;
        for(int i=0;i<2*n;++i) {
            if(a[i]<i) {
                fen.update(a[i],-1);
                ans+=fen.query(a[i],i);
            } else {
                fen.update(i,1);
            }
        }
        cout << ans << '\n';
    }
}