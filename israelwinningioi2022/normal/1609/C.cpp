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

const int M = 1e6+10;
vb isp;
int solve(){
    int n, e; cin>>n>>e;
    vi a(n);
    loop(i,0,n){
        cin>>a[i];
        if (a[i]==1) a[i] = 0;
        else if (isp[a[i]]) a[i] = 1;
        else a[i] = -1;
    }
    int ans = 0;
    auto solveV = [&ans](vi& a)->int{ // just 0,1
        if (!a.size()) return 0;
        int n = a.size();
        vi pos; pos.pb(-1);
        loop(i,0,n) if(a[i]==1) pos.pb(i);
        pos.pb(n);
        loop(ind,1,pos.size()-1){
            ans += (pos[ind]-pos[ind-1]) * (pos[ind+1]-pos[ind]) - 1;
        }
        return 0;
    };
    loop(off,0,e){
        vi vec;
        for(int i=off; i<n; i+=e) {
            if (a[i]==-1) solveV(vec), vec.clear();
            else vec.pb(a[i]);
        }
        solveV(vec);
    }
    cout << ans << endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    isp.resize(M, 1);
    loop(p,2,M){
        if (isp[p]) for(int j = p*p; j<M; j+=p) isp[j]=0;
    }
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
6
7 3
10 2 1 3 1 19 3
3 2
1 13 1
9 3
2 4 2 1 1 1 1 4 2
3 1
1 1 1
4 1
1 2 1 1
2 2
1 2


*/