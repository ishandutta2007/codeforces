// https://www.hackerearth.com/problem/approximate/lots-of-lines-75430c59/
#include <bits/stdc++.h>
using namespace std;
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void pre(){
}
#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
	  	  tree_order_statistics_node_update>;
template <class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	ld dist() const { return sqrt(x*x+y*y); }
	// angle to x-axis in interval [-pi, pi]
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
};
vector<Point<ld>> v;
vector<pair<Point<ld>,int>> cur,cur2;
Point<ld> P;
template <class P>
pair<P,P> circleTangents(const P &p, const P &c, ld r) {
	P a = p-c;
	ld x = r*r/a.dist2(), y = sqrt(x-x*x);
	return make_pair(c+a*x+a.perp()*y, c+a*x-a.perp()*y);
}
const int N = 100005;
int vis[N];
long long solve(ld x,bool dbg = 0){
	cur.clear();cur2.clear();
	memset(vis,0,sizeof(vis));
	rep(ii,sz(v)){
		Point<ld> i = v[ii];
		if((i-P).dist()<=x) continue;
		pair<Point<ld>,Point<ld>> u = circleTangents(i,P,x);
		u.fst=u.fst-P,u.snd=u.snd-P;
		if(u.fst.y>0) u.fst.x = -u.fst.x,cur.pb(mp(u.fst,ii));
		else cur2.pb(mp(u.fst,ii));
		if(u.snd.y>0) u.snd.x = -u.snd.x,cur.pb(mp(u.snd,ii));
		else cur2.pb(mp(u.snd,ii));
	}
	sort(all(cur));sort(all(cur2));
	trav(i,cur2) cur.pb(i);
	long long cnt  = 0,ans = 0,cnt2=0;
	Tree<int> S;
	trav(i,cur){
		if(!vis[i.snd]) {
			cnt2++;
			ans-=cnt2;
			cnt++;
			vis[i.snd]=cnt;
			S.insert(cnt);
		}
		else ans+=cnt2,ans-=S.order_of_key(vis[i.snd]),S.erase(vis[i.snd]);
	}
	return ans;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;
	ll k;

	cin>>n>>k;
	k = 1ll*n*(n-1)/2-k;
	v.resize(n);
	{
		int x,y;
		// cin>>x>>y;
		x = y = 0;
		P.x = x,P.y = y;
	}
	rep(i,n) {
		int x,y;
		cin>>x>>y;
		v[i].x= x , v[i].y= y;
	}
	ld lo = 0,hi = 1e8;
	rep(ii,60){
		ld  m =(lo+hi)/2;
		if(solve(m)>k) lo =m;
		else hi = m;
	}
	cout<<setprecision(20)<<hi;	
	
	
	
	
	return 0;
}