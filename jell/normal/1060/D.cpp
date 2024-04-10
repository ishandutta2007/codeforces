#include <bits/stdc++.h>

#define debug 0
#define esc(ret) cout << (ret) << endl,exit(0)
#define fcout(d) cout << fixed << setprecision(d)
#define urep(i,s,t) for(int i = (int)(s); i <= (int)(t); ++i)
#define drep(i,s,t) for(int i = (int)(s); i >= (int)(t); --i)
#define rep(i,n) urep(i,0,(n) - 1)
#define rep1(i,n) urep(i,1,(n))
#define rrep(i,n) drep(i,(n) - 1,0)
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define vct vector
#define prique priority_queue
#define l_bnd lower_bound
#define u_bnd upper_bound
#define rsz resize
#define era erase
#define emp emplace
#define emf emplace_front
#define emb emplace_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define fir first
#define sec second
#define odd(x) ((x) & 1)
#define even(x) (~(x) & 1)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vct<vct<ll>> mat;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
typedef map<int,int> mpii;
typedef unordered_map<int,int> umpii;

const int dir[8][2] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1} };
const ll inf32 = (1 << 30) - 1;
const ll inf64 = (1LL << 62) - 1;
const ll mod = 1e9 + 7;
const db eps = 1e-9;

template <class T, class U> T qceil(T x, U y) { return x > 0 ? (x - 1) / y + 1 : x / y; }
template <class T, class U> bool parity(T x, U y) { return odd(x) ^ even(y); }
template <class T, class U> bool chmax(T &m, U x) { if(m < x) { m = x; return 1; } return 0; }
template <class T, class U> bool chmin(T &m, U x) { if(m > x) { m = x; return 1; } return 0; }
template <class T> bool cmprs(T &v) {
    T tmp = v;
    sort(all(tmp));
    tmp.erase(unique(all(tmp)),end(tmp));
    for(auto it = begin(v); it != end(v); ++it) *it = l_bnd(all(tmp),*it) - begin(tmp) + 1;
    return v.size() > tmp.size();
}
mat mulmat(mat &x, mat &y, ll md = mod) {
    int xrow = x.size();
    int xcol = x[0].size();
    int ycol = y[0].size();
    mat ret(xrow,vct<ll>(ycol));
    rep(i,xrow)rep(j,ycol)rep(k,xcol) ret[i][j] += x[i][k] * y[k][j] % md,ret[i][j] %= md;
    return ret;
}

template<class T> T gcd(T a, T b){ if(a % b) return gcd(b, a % b); return b; }

ll modpow(ll n, ull e, ll md = mod) {
    n %= md;
    if(!e) return 0;
    return modpow(n * n % md,e / 2,md) * (e & 1 ? n : 1) % md;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

   int n;
   cin>>n;
   set<pii> lv,rv;
   vct<int> vl(n),vr(n);
   ll ans=n;
   rep(i,n){
   		int l,r;
		cin>>l>>r;
		ans+=l+r;
		vl[i]=l;
		vr[i]=r;
		lv.emp(l,i);
		rv.emp(r,i);
   }
   while(!lv.empty()){
   		auto l=lv.rbegin();
		auto r=rv.rbegin();
		pii p1=*l;
		pii p2=*r;
		lv.era(p1);
		rv.era(p2);
		if(p1.sec==p2.sec){
			ans-=min(p1.fir,p2.fir);
		}else{
			ans-=min(p1.fir,p2.fir);
			int nl=vl[p2.sec];
			vl[p1.sec]=nl;
			lv.era({nl,p2.sec});
			lv.emp(nl,p1.sec);
		}
   }
   esc(ans);
}