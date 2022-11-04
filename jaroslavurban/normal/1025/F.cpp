#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS=1e-6;
bool eq(ld a, ld b) { return fabs(a-b) <= fabs(a+b) * EPS || fabs(a-b) < EPS; }

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
//	bool operator==(P p) const { eq(x,p.x) && eq(y,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T dot(P a, P b) const { return (a-*this).dot(b-*this); }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	ld dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi], positive above y=0
	ld angle() const { return atan2(y, x); }
	// angle of two points when looking from this point [0, pi] (not tested)
	ld angle(P v,P w){return acos(clamp(v.dot(w)/abs(v)/abs(w),-1.,1.));}
	// counter-clockwise angle from b to c (not tested)
	ld orientedAngle(P a,P b,P c){return a.cross(b,c)>=0?a.angle(b,c):2*M_PI-a.angle(b,c);}
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
	friend istream&operator>>(istream&is,P&p){return is>>p.x>>p.y;}
};
typedef Point<ll>Pl;
typedef Point<ld>Pd;
// todo: function for removing collinear points

// was made for long longs
// goes through all pairs of points, calls f(int i,vec<P>&pts)
// pts will be sorted by their distance from the line going through pts[i],pts[i+1]
// collinear points will be to the left and to the right of i
template<class P,class F>
void allPointPairs(vector<P>&pts,F f){
	int n=pts.size();
	vector<int>pos(n);
	iota(pos.begin(),pos.end(),0);
	sort(pts.begin(),pts.end());
	struct E{P v;int i,j;};
	vector<E>evs(n*(n-1)/2);
	for(int p=0,i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			evs[p++]={pts[j]-pts[i],i,j};
	sort(evs.begin(),evs.end(),[&](E&a,E&b){
//		if(!a.v.cross(b.v))return tie(pts[b.j],pts[b.i])<tie(pts[a.j],pts[a.i]);
		return a.v.cross(b.v)>0;
	});
	for(auto[v,i,j]:evs)f(pos[i],pts),swap(pts[pos[i]],pts[pos[j]]),swap(pos[i],pos[j]);
}

void ProGamerMove(){
	int n;cin>>n;
	vector<Pl>pts(n);
	for(auto&[x,y]:pts)cin>>x>>y;
	ll res=0;
	auto choose2=[&](int n){return ll(n-1)*n/2;};
	allPointPairs(pts,[&](int i,vector<Pl>&pts){
		res+=choose2(i)*choose2(n-i-2);
	});
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
	//cin>>tc;
	while(tc--)ProGamerMove();
}