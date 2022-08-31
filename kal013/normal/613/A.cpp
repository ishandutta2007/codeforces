#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
 os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
	return os << "(" << P.first << "," << P.second << ")";}

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif


#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define I insert 
#define pb push_back
#define F first
#define S second
#define endl "\n"

// int mod=1e9+7;
// inline int mul(int a,int b){return (a*1ll*b)%mod;}
// inline int add(int a,int b){a+=b;if(a>=mod)a-=mod;return a;}
// inline int sub(int a,int b){a-=b;if(a<0)a+=mod;return a;}
// inline int power(int a,int b){int rt=1;while(b>0){if(b&1)rt=mul(rt,a);a=mul(a,a);b>>=1;}return rt;}
// inline int inv(int a){return power(a,mod-2);}
// inline void modadd(int &a,int &b){a+=b;if(a>=mod)a-=mod;} 


//small non recursive functions should me made inline
//do not read input in double format if they are integer points
#define ld double
#define PI acos(-1)
//atan2(y,x) slope of line (0,0)->(x,y) in radian (-PI,PI]
// to convert to degree multiply by 180/PI
ld INF = 1e100;
ld EPS = 1e-9;
inline bool eq(ld a,ld b) {return fabs(a-b)<EPS;}
inline bool lt(ld a,ld b) {return a+EPS<b;}
inline bool gt(ld a,ld b) {return a>b+EPS;}
inline bool le(ld a,ld b) {return lt(a,b)||eq(a,b);}
inline bool ge(ld a,ld b) {return gt(a,b)||eq(a,b);}

struct pt {
  ld x, y; 
  pt() {}
  pt(ld x, ld y) : x(x), y(y) {}
  pt(const pt &p) : x(p.x), y(p.y)    {}
  pt operator + (const pt &p)  const { return pt(x+p.x, y+p.y); }
  pt operator - (const pt &p)  const { return pt(x-p.x, y-p.y); }
  pt operator * (ld c)     const { return pt(x*c,   y*c  ); }
  pt operator / (ld c)     const { return pt(x/c,   y/c  ); }
  bool operator < (const pt &p) const{ return lt(y,p.y)||(eq(y,p.y)&&lt(x,p.x));}
  bool operator > (const pt &p) const{ return p<pt(x,y);}
  bool operator <= (const pt &p) const{ return !(pt(x,y)>p);}
  bool operator >= (const pt &p) const{ return !(pt(x,y)<p);}
  bool operator == (const pt &p) const{ return (pt(x,y)<=p)&&(pt(x,y)>=p);}
};
ld dot(pt p,pt q) {return p.x*q.x+p.y*q.y;}
ld dist2(pt p, pt q) {return dot(p-q,p-q);}
ld dist(pt p,pt q) {return sqrt(dist2(p,q));}
ld norm2(pt p) {return dot(p,p);}
ld norm(pt p) {return sqrt(norm2(p));}
ld cross(pt p, pt q) { return p.x*q.y-p.y*q.x;}
ostream &operator<<(ostream &os, const pt &p) {
  return os << "(" << p.x << "," << p.y << ")";}
istream& operator >> (istream &is, pt &p){
  return is >> p.x >> p.y;}
//returns 0 if a,b,c are collinear,1 if a->b->c is cw and -1 if ccw
int orient(pt a,pt b,pt c)
{
  pt p=b-a,q=c-b;double cr=cross(p,q);
  if(eq(cr,0))return 0;if(lt(cr,0))return 1;return -1;}
// rotate a point CCW or CW around the origin
pt RotateCCW90(pt p)   { return pt(-p.y,p.x); }
pt RotateCW90(pt p)    { return pt(p.y,-p.x); }
pt RotateCCW(pt p, ld t) {  //rotate by angle t degree ccw 
  return pt(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t)); }
// project point c onto line (not segment) through a and b assuming a != b
pt ProjectPointLine(pt a, pt b, pt c) {
  return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);}
// project point c onto line segment through a and b (closest point on line segment)
pt ProjectPointSegment(pt a, pt b, pt c) {
  ld r = dot(b-a,b-a); if (eq(r,0)) return a;//a and b are same
  r = dot(c-a, b-a)/r;if (lt(r,0)) return a;//c on left of a
  if (gt(r,1)) return b; return a + (b-a)*r;}
// compute distance from c to segment between a and b
ld DistancePointSegment(pt a, pt b, pt c) {
  return (dist2(c, ProjectPointSegment(a, b, c)));}
// compute distance from c to line between a and b


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<setprecision(25);
	ll n;cin>>n;
	pt p;
	cin>>p;
	ld mind,maxd;
	mind = 1e18;maxd = 0;
	ll i,j;pt a;
	vector<pt> pts;
	for(i=0;i<n;i++){
		cin>>a;pts.pb(a);
		ld dis = dist2(p,a);
		mind = min(dis,mind);
		maxd = max(dis,maxd);
		if(i!=0){
		 	dis = DistancePointSegment(pts[i],pts[i-1],p);
			mind = min(mind,dis);
		}
		if(i==n-1){
			dis = DistancePointSegment(pts[0],pts[i],p);
			mind = min(mind,dis);			
		}
	}
	maxd -= mind;
	// trace(mind);
	ld pi = 4.0 * atan(1.0);
	pi *= maxd*1.0;
	cout<<pi;
}