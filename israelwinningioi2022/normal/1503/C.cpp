#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD = 1e9+7;

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


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vii vals(n);
    loop(i,0,n) cin>>vals[i].x>>vals[i].y;
    sort(all(vals));
    vi dp(n, INF);
    dp[0] = 0;
    int best = INF;
    set<ii> eve;
    set<ii> s;
    loop(i,0,n){
        while(eve.size() && eve.begin()->x < vals[i].x){
            int ind = eve.begin()->y;
            chkmin(best, dp[ind] - eve.begin()->x);
            s.erase({dp[ind], ind});
            eve.erase(eve.begin());
        }
        if (i){
            dp[i] = best + vals[i].x;
            if (s.size()) chkmin(dp[i], s.begin()->x);
        }
        s.insert({dp[i], i});
        int til = vals[i].x + vals[i].y;
        eve.insert({til, i});
    }
    //loop(i,0,n) cout<<dp[i]<<" "; cout<<endl;
    int ans = 0;
    loop(i,0,n) ans+=vals[i].y;
    ans += dp[n-1];
    cout << ans << endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -D_GLIBCXX_DEBUG -o a & a
6
4 2
8 4
3 0
2 3
7 1
0 1



*/