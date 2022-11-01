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

template <class A, class B> pair<A,B> operator+(const pair<A,B>& a, const pair<A,B>& b) {
    return {a.x+b.x, a.y+b.y}; }
template <class A, class B> pair<A,B> operator-(const pair<A,B>& a, const pair<A,B>& b) {
    return {a.x-b.x, a.y-b.y}; }
template <class A, class B> istream& operator>>(istream& is, pair<A,B>& a) {
    return is >> a.x >> a.y; }
template <class A, class B> ostream& operator << (ostream& os, const pair<A,B>& a) {
    return os << "< " << a.x << " , " << a.y << " >"; }

template<class T> ostream &operator<<(ostream &os, vector<T> v) { os << '['; if (!v.empty()) { os << v[0]; loop(i, 1, v.size()) os << ',' << v[i]; } return os << ']'; }
template<class T> ostream &operator<<(ostream &os, set<T> v) { os << '{'; if (!v.empty()) { os << *v.begin(); for(auto it = ++v.begin(); it != v.end(); ++it) os << ',' << *it; } return os << '}'; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto DIST = uniform_int_distribution<int>(0, INF);

struct SEG{
    int n, sz;
    vi a, pref;
    SEG(int n): n(n){
        for(sz=1;sz<n;sz*=2);
        a.resize(2*sz);
        pref.resize(2*sz);
    }
    void update(int i, int x){
        i+=sz;
        a[i]+=x, pref[i] = a[i];
        for(i/=2;i;i/=2) {
            a[i] = a[2*i] + a[2*i+1];
            pref[i] = max(pref[2*i], pref[2*i+1]+a[2*i]);
        }
    }
    int query(){
        return pref[1];
    }
    /*int query(int l, int r){
        int res = 0;
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2) chkmax(res, a[l++]);
            if (r%2==0) chkmax(res, a[r--]);
        }
        return res;
    }*/
};
int solve(){
    int n,m; cin>>n>>m;
    vi a(n); loop(i,0,n) cin>>a[i];
    vvi b(m);
    vi sum(m), szs(m), avg(m);
    loop(i,0,m){
        int k; cin>>k; b[i].resize(k);
        szs[i] = k;
        loop(j,0,k) cin>>b[i][j], sum[i]+=b[i][j];
        avg[i] = (sum[i]+szs[i]-1)/szs[i];
    }
    vii v;
    loop(i,0,n) v.pb({a[i], INF});
    loop(i,0,m) v.pb({avg[i], i});
    sort(all(v));
    reverse(all(v));
    vi back(m);
    int sz = v.size();
    loop(i,0,sz) if(v[i].y!=INF) back[v[i].y] = i;
    //cout<<"V: "<<v<<endl;
    vi vals(sz);
    loop(i,0,sz) vals[i]= (v[i].y==INF?-1:1);
    //cout<<vals<<endl;
    SEG seg(sz);
    loop(i,0,sz) seg.update(i, vals[i]);
    string ans;
    loop(i,0,m){
        for(auto x:b[i]){
            int navg = (sum[i]-x+szs[i]-2)/(szs[i]-1);
            seg.update(back[i], -1);
            int ind = upper_bound(all(v), ii(navg, i), greater<ii>())-v.begin();
            ind--;
            //cout<<"NAVG: "<<navg<<" "<<ind<<endl;
            if (ind<0) ans+="0";
            else{
                seg.update(ind, 1);
                ans += (seg.query()<=0?"1":"0");
                seg.update(ind, -1);
            }
            seg.update(back[i], 1);
        }
    }
    cout<<ans<<endl;
    /*vi pref(sz+1);
    loop(i,0,sz) pref[i+1]=pref[i]+(v[i].y==INF?-1:1);
    vi maxi(sz+1); 
    loop(i,0,sz) maxi[i+1] = max(maxi[i], pref[i+1]);*/

    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ e.cpp -o a & a
2
1 1
30
3
25 16 37
4 2
9 12 12 6
2
4 5
3
111 11 11

*/