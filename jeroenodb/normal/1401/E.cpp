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
const int mxN = 1e6, oo = 1e9;
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
struct event {
    int x,y,y2;
    bool operator<(const event& o) {
        if(x!=o.x) return x<o.x;
        return y2<o.y2;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vector<event> es; es.reserve(n*2+m+6);
    for(int i=0;i<n;++i) {
        int y,x1,x2; cin >> y >> x1 >> x2;
        es.push_back({x1,y,-oo});
        es.push_back({x2,y,oo});
    }
    for(int i=0;i<m;++i) {
        int x,y,y2; cin >> x >> y >> y2;
        es.push_back({x,y,y2});
    }
    es.push_back({0,0,-oo});
    es.push_back({0,mxN,-oo});
    es.push_back({mxN,0,oo});
    es.push_back({mxN,mxN,oo});
    es.push_back({0,0,mxN});
    es.push_back({mxN,0,mxN});
    sort(all(es));
    fenwick<int> fen(mxN+3);
    ll ans = 1-n-m-4;
    for(auto e : es) {
        if(abs(e.y2)==oo) {
            if(e.y2>0) fen.update(e.y,-1);
            else fen.update(e.y,1);
        } else {
            ans+=fen.query(e.y,e.y2);
        }
    }
    cout << ans << '\n';
}