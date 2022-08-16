#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;


template<class T> ostream& operator<<(ostream &os, vector<T> V){
	os << "[ ";
	for(auto v  : V) os << v << " ";
	return os << " ]";
}
template<class T> ostream& operator<<(ostream &os, set<T> V){
	os << "[ ";
	for(auto v  : V) os << v << " ";
	return os << " ]";
}
template<class T , class R > ostream& operator<<(ostream &os, map<T , R> V){
	os << "[ ";
	for(auto v  : V) os << "(" << v.first << ":" << v.second << ")";
	return os << " ]";
}
template<class T , class R > ostream& operator<<(ostream &os, pair<T , R> V){
	return os << "(" << V.first << "," << V.second << ")";
}

#define cerr cout
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cout << name << " : " << arg1 << endl;
}
template<typename Arg1, typename... Args>
void __f(const char* names , Arg1&& arg1, Args&&... args){
	const char* comma=strchr(names+1 , ','); cout.write(names, comma-names) << " : " << arg1<< " |";
	__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll,ll>
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define For(i,n) for(int i = 0;i < (int)n ; ++i)
#define Rep(i,n) for(int i = 1;i <= (int)n ; ++i)
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define endl '\n'
#define pb push_back
#define I insert
#define MP make_pair

#define d0(x) cout << (x) << " "
#define d1(x) cout << (x) << endl
#define d2(x, y) cout << (x) <<" " << (y) << endl
#define d3(x,y,z) cout << (x) << " " << (y) << " " << (z) << endl
const int maxn=1e6+100;
const ll INF=1e18;
const int MaxN=1e5+10;
struct pt{
    #define F1 ll
    #define F2 ll
    #define F3 ll
    F1 x,y;
    
    pt() {};
    pt(F1 _x): x(_x),y((F1)(0)){};
    pt(F1 _x, F1 _y): x(_x),y(_y){};
    pt operator + (const pt &p) const {return pt(x+p.x,y+p.y);}
    pt operator - (const pt &p) const {return pt(x-p.x,y-p.y);}
    F2 operator * (const pt &p) const {return x*p.x+y*p.y;}
    F2 operator ^ (const pt &p) const {return x*p.y-y*p.x;}
    pt operator * (const F3 c) const {return pt(x*c,y*c);}
    pt operator / (const F3 c) const {return pt(x/c,y/c);}
    pt operator += (const pt &p) {this->x+=p.x;this->y+=p.y;return *this;}
    pt operator -= (const pt &p) {this->x-=p.x;this->y-=p.y;return *this;}
    pt operator *= (const F3 c) {this->x*=c;this->y*=c; return *this;}
    pt operator /= (const F3 c) {this->x/=c;this->y/=c;return *this;}
    // COMPARES y first
    // bool operator < (const pt &p) const{ return lt(y,p.y)||(eq(y,p.y)&&lt(x,p.x));}
    // inline bool operator == (const pt &r) const {return (eq(y,r.y) && eq(x,r.x));}
    // bool operator > (const pt &p) const{ return p<pt(x,y);}
    // inline bool operator <= (const pt &r) const {return !(*this>r);}
    // inline bool operator >= (const pt &r) const {return !(*this<r);}
    // inline bool operator != (const pt &r) const {return !(*this==r);}
    friend istream& operator >> (istream& is, pt& p){return is>>p.x>>p.y;}
    friend ostream& operator << (ostream& os, const pt& p) {return os<<"("<<p.x<<","<<p.y<<")";}
};

inline ll f(pt x,ll v){
	return x*pt(v,1);
}
pt line[maxn];int vis[maxn];int cut;
/*All pair of lines must not intersect at more
than 1 points */
//set off as minimum negative value of l.
ll off=0;
void add_l(pt nw,int v,int l,int r) {
	//[l,r)
	if (vis[v]!=cut){
		vis[v]=cut;
		line[v]=pt(0,INF);
	}
	 int m = (((l+off)+(r+off)) / 2)-off;
	 bool lef = f(nw, l) < f(line[v], l);
	 bool mid = f(nw, m) < f(line[v], m);
	 if(mid) swap(line[v], nw);
	 if(r - l == 1) return;
	 else if(lef != mid) add_l(nw, 2 * v, l, m);
	 else add_l(nw, 2 * v + 1, m, r);}
ll get(int x,int v,int l,int r) {
	if (vis[v]!=cut){
		vis[v]=cut;line[v]=pt(0,INF);
	}
	int m = (((l+off)+(r+off)) / 2)-off;
	if(r - l == 1) return f(line[v], x);
	else if(x < m)
		return min(f(line[v],x),get(x,2*v,l,m));
	else
		return min(f(line[v],x),get(x,2*v+1,m,r));}



ll a[maxn],b[maxn];
ll dp[maxn];
int bigC[maxn],sub[maxn];
int P[maxn];
vi adj[maxn];

void dfs(int n,int p){
	P[n]=p;
	sub[n]=1;bigC[n]=-1;
	int mx=0;
	for(auto e:adj[n]){
		if (e==p) continue;
		dfs(e,n);
		sub[n]+=sub[e];
		if (sub[e]>mx){
			mx=sub[e];
			bigC[n]=e;
		}
	}
}
void add(int n){
	add_l(pt(b[n],dp[n]),1,-MaxN,MaxN);
	for(auto e:adj[n]){
		if (e!=P[n]) add(e);
	}
}
void sol(int n){
	if (P[n]!=0 && adj[n].size()==1){
		dp[n]=0;
		add_l(pt(b[n],0ll),1,-MaxN,MaxN);
		return;
	}
	for(auto e:adj[n]){
		if (e!=bigC[n] && e!=P[n]){
			sol(e);
			++cut;
		}
	}
	if (bigC[n]!=-1){
		sol(bigC[n]);
	}
	for(auto e:adj[n]){
		if (e!=bigC[n] && e!=P[n]) add(e);
	}
	dp[n]=get(a[n],1,-MaxN,MaxN);
	add_l(pt(b[n],dp[n]),1,-MaxN,MaxN);

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(25);
	int n,u,v;
	cin>>n;
	cut=1;
	Rep(i,n) {cin>>a[i];dp[i]=INF;}
	Rep(i,n) cin>>b[i];


	Rep(i,n-1){
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,0);
	sol(1);
	Rep(i,n){d0(dp[i]);}

	return 0;
}