#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

template<class T>
struct Point {
	typedef Point P;
	T x, y, r;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	bool operator!=(P p) const { return tie(x,y)!=tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	ll cross(P p) const { return x*(ll)p.y - y*(ll)p.x; }
	ll cross(P a, P b) const { return (a-*this).cross(b-*this); }
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
typedef Point<int>Pt;

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

template<class P>
bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}


struct seg{
	Pt a,b;
};

void ProGamerMove(){
	vector<seg>segs(4);
	for(int i=0;i<4;++i){
		cin>>segs[i].a>>segs[i].b;
		if(segs[i].b<segs[i].a)swap(segs[i].a,segs[i].b);
	}
	sort(segs.begin(),segs.end(),[&](seg&x,seg&y){
		return tie(x.a,x.b)<tie(y.a,y.b);
	});
	bool pos=1;
	pos&=segs[0].a==segs[1].a;
	pos&=segs[0].a.x==segs[0].b.x;
	pos&=segs[0].a.y==segs[1].b.y;
	pos&=segs[1].b==segs[3].a;
	pos&=segs[1].b.x==segs[3].b.x;
	pos&=segs[3].b==segs[2].b;
	pos&=segs[0].b==segs[2].a;
	pos&=segs[0].b.y==segs[2].b.y;
	pos&=segs[0].a!=segs[0].b;
	pos&=segs[1].a!=segs[1].b;
	cout<<(pos?"YES\n":"NO\n");
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}