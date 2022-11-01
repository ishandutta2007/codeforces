#include <bits/stdc++.h>
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
const int INF = 1e9, MOD = 1e9+7;

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

vb sd;
vvi g;
vb check;

ii dfs(int cur, bool s=1){
    if (check[cur]) return {0,0};
    ii v = {1,(s ^ sd[cur])};
    check[cur] = 1;
    for(auto nei:g[cur]){
        ii vv = dfs(nei, !s);
        v.x += vv.x, v.y += vv.y;
    }
    return v;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vii a(n); loop(i,0,n) cin>>a[i].x>>a[i].y;
    // if (n==1) return cout<<0<<endl,0;
    sort(all(a), [](ii x, ii y){
        return min(x.x, x.y) > min(y.x, y.y);
    });
    sd.resize(n);
    int mini = INF, maxi = -INF;
    loop(i,0,n){
        if (a[i].x>a[i].y){
            swap(a[i].x, a[i].y);
            sd[i] = 1;
        }
        chkmin(mini, a[i].y);
        chkmax(maxi, a[i].x);
    }
    if (maxi > mini) return cout<<-1<<endl,0; // have intersection
    int maxW = -INF;
    g.resize(n);
    set<ii> s;
    auto addEdge = [](int i, int j){
        g[i].pb(j);
        g[j].pb(i);
        return ;
    };
    loop(i,0,n){
        //cout<< "HI: "<<i<<endl;
        if (a[i].y < maxW) return cout<<-1<<endl,0;
        auto it = s.lower_bound({a[i].y,-1});
        if (it!=s.end()){
            while(1){
                auto cur = *it; 
                addEdge(i, cur.y);
                it++;
                if (it == s.end()) break;
                s.erase(cur);
            }
            chkmax(maxW, a[i].y);
        }
        s.insert({a[i].y, i});
    }
    //cout<<"BI: "<<endl;
    check.resize(n);
    int ans = 0;
    loop(i,0,n) if(!check[i]) {
        auto vv = dfs(i);
        int sz = vv.x, v = vv.y;
        ans += min(v, sz-v);
    }
    cout << ans << endl;
    return 0;
}
/*
color a
cls
g++ d.cpp -D_GLIBCXX_DEBUG -o a & a
5
3 10
6 4
1 9
5 8
2 7


*/