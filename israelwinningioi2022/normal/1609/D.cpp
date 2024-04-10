#include <bits/stdc++.h>
using namespace std;
#define int int64_t
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);i++)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
#define all(x) x.begin(),x.end()
const int INF = 1e18, MOD = 1e9 + 7;

template <class A, class B> pair<A,B> operator+(pair<A,B>& a, pair<A,B>& b) {
    return {a.x+b.x, a.y+b.y}; }
template <class A, class B> pair<A,B> operator-(pair<A,B>& a, pair<A,B>& b) {
    return {a.x-b.x, a.y-b.y}; }
template <class A, class B> istream& operator>>(istream& is, pair<A,B>& a) {
    return is >> a.x >> a.y; }
template <class A, class B> ostream& operator << (ostream& os, const pair<A,B>& a) {
    return os << "< " << a.x << " , " << a.y << " >"; }

template<class T> ostream &operator<<(ostream &os, vector<T> v) { os << '['; if (!v.empty()) { os << v[0]; loop(i, 1, v.size()) os << ',' << v[i]; } return os << ']'; }
template<class T> ostream &operator<<(ostream &os, set<T> v) { os << '{'; if (!v.empty()) { os << *v.begin(); for(auto it = ++v.begin(); it != v.end(); ++it) os << ',' << *it; } return os << '}'; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto DIST = uniform_int_distribution<int>(0, INF);

struct DSU{
    vi p, sz;
    DSU(int n): p(n,-1), sz(n,1){}
    int find(int c){
        if (p[c]==-1) return c;
        return p[c] = find(p[c]);
    }
    int uni(int a, int b){
        a = find(a), b = find(b);
        if (a==b) return -1;
        if (sz[a]>sz[b]) swap(a,b);
        p[a] = b;
        sz[b] += sz[a];
        return sz[b];
    }
};
int solve(){
    int n,m; cin>>n>>m;
    DSU dsu(n);
    int ans = 0, s = 1;
    
    loop(i,0,m){
        int a,b; cin>>a>>b; a--, b--;
        int r = dsu.uni(a,b);
        if (r==-1) s++;
        else chkmax(ans, r-1);
        vi sz;
        loop(a,0,n) if(dsu.find(a)==a) sz.pb(dsu.sz[a]);
        sort(all(sz)), reverse(all(sz));
        int ans = 0;
        loop(j,0,s) ans+=sz[j];
        cout << ans-1 << endl;
    }
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1; //cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
10 8
1 2
2 3
3 4
1 4
6 7
8 9
8 10
1 4



*/