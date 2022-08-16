#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL "%lld"
#endif

#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define si set<int>
#define sll set<ll>
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define mii map<int,int>
#define mll map<ll,ll>
#define vvi vector<vi >
#define vvl vector<vll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define what_is(x) cerr << #x << " is " << x << endl;
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))

void gett()
{
	cerr<< (clock())/(double)cps<<endl;
}

ll powr(ll a, ll b, ll mod)
{
	ll x = 1%mod;
	a %= mod;
	while(b)
	{
		if(b&1)
			x = (x*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return x;
}
ll inv(ll a, ll mod)
{
	return powr(a,mod-2,mod);
}

double EPS=1e-8;
struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double dist(PT p,PT q){ return sqrt(dot(p-q,p-q)); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
const int maxn = 1e5+10;
PT A,B,bin,bottle[maxn];
vector< pair<double,int > > p1,p2;
int main()
{
	cin>>A.x>>A.y>>B.x>>B.y>>bin.x>>bin.y;
	int n;
	sd(n);
	double _dist = 0;
	int p,q;
	rep(i,0,n)
	sd(p),bottle[i].x=p,sd(q),bottle[i].y=q,_dist+=2*dist(bottle[i],bin),p1.eb(mp(dist(A,bottle[i])-dist(bin,bottle[i]),i)),p2.eb(mp(dist(B,bottle[i])-dist(bin,bottle[i]),i));
	sort(p1.begin(),p1.end());sort(p2.begin(),p2.end());
	double __dist = _dist +p1[0].F ;
	if(p1[0].S != p2[0].S)
		__dist = min(__dist,_dist+p1[0].F+p2[0].F);
	if(n > 1 && (p1[0].S != p2[1].S))
		__dist = min(__dist,_dist+p1[0].F+p2[1].F);
	if(n > 1 && (p1[1].S != p2[0].S))
		__dist = min(__dist,_dist+p1[1].F+p2[0].F);
	__dist = min(__dist,_dist+p2[0].F);
	cout<<setprecision(15)<<fixed<<__dist;
}