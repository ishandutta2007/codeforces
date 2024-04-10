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
void solve() {
    int n,m; cin >> n >> m;
    map<int,int> got;
    vi a(n*m); for(auto& i : a) cin >> i;
    vi order(n*m); iota(all(order),0);
    sort(all(order), [&](int c,int d) {return a[c]<a[d];});
    vvi mp(n*m);
    int rnk=0;
    for(int i=0;i<n*m;++i) {
        bool more=false;
        if(i<n*m-1 and a[order[i]]!=a[order[i+1]]) more=true;
        a[order[i]]=rnk;
        mp[rnk].push_back(i);
        rnk+=more;
        
    }
    for(auto& v : mp) {
        sort(all(v), [&](int c,int d) {return c/m>d/m or (c/m==d/m and c%m<d%m);});
    }
    vector<fenwick<int>> seats(n, fenwick<int>(m+1));
    ll ans=0;
    for(auto i=0;i<n*m;++i) {
        int j = mp[a[i]].back(); mp[a[i]].pop_back();
        int r=j/m, c = j%m;
        ans+=seats[r].query(0,c);
        seats[r].update(c,1);
    }
    cout << ans << '\n';

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}