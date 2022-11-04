#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

template<class T>
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
	ld dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi], positive above y=0
	ld angle() const { return atan2(y, x); }
	// angle of two points when looking from this point [0, pi]
	ld angle(P a,P b){ld res=fabs((a-*this).angle()-(b-*this).angle());return min(res,2*M_PI-res);}
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
typedef Point<ld>Pt;

template<class P>
bool circleInter(P a,P b,ld r1,ld r2,pair<P, P>&out) {
	if (a == b) { assert(r1 != r2); return false; }
	P vec = b - a;
	double d2 = vec.dist2(), sum = r1+r2, dif = r1-r2,
	       p = (d2 + r1*r1 - r2*r2)/(d2*2), h2 = r1*r1 - p*p*d2;
	if (sum*sum < d2 || dif*dif > d2) return false;
	P mid = a + vec*p, per = vec.perp() * sqrt(fmax(0, h2) / d2);
	out = {mid + per, mid - per};
	return true;
}

template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
	auto d = (e1 - s1).cross(e2 - s2);
	if (d == 0) // if parallel
		return {-(s1.cross(e1, s2) == 0), P(0, 0)};
	auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
	return {1, (s1 * p + e1 * q) / d};
}

struct cir{
	Pt s;
	ld r;
};

void ProGamerMove(){
	int t[2];cin>>t[0]>>t[1];
	Pt pts[3];
	for(int i=0;i<3;++i)cin>>pts[i];
	swap(pts[1],pts[2]);
	auto d1=(pts[0]-pts[1]).dist(),d2=(pts[1]-pts[2]).dist(),d3=(pts[0]-pts[2]).dist();
	ld t1=d1+d2+t[0],t2=d3+t[1];
	if(d1+d2<=d3+t[1]){
		cout<<min(t1,t2)<<"\n";return;
	}
	ld lf=0,rg=d1+d2;
	ld r[3],EPS1=1e-10,EPS2=1e-11;
	auto tr=[&](Pt p){
//		cerr<<p<<endl;
		return (p-pts[0]).dist()-EPS1<=r[0]&&(p-pts[1]).dist()-EPS1<=r[1]&&(p-pts[2]).dist()-EPS1<=r[2];
	};
	int mit=60;
	for(int it=0;it<mit;++it){
		r[0]=(lf+rg)/2;
//		r[0]=1;
		r[1]=t1-d2-r[0];
		r[2]=t2-r[0];
		bool pos=0;
		for(int i=0;i<3;++i)pos|=tr(pts[i]);
		pair<Pt,Pt>res;
		for(int i=0;i<3;++i)
			for(int j=i+1;j<3;++j)
				if(circleInter(pts[i],pts[j],r[i]+EPS2,r[j]+EPS2,res)){
					pos|=tr(res.first);
					pos|=tr(res.second);
//					cerr<<pts[i]<<" "<<pts[j]<<" "<<r[i]<<" "<<r[j]<<" "<<pos<<endl;
				}
//		cerr<<r[0]<<" "<<pos<<endl;
		if(pos)lf=r[0];
		else rg=r[0];
	}
	cout<<r[0]<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
	//cin>>tc;
	while(tc--)ProGamerMove();
}