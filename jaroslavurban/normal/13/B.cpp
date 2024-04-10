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
	bool operator!=(P p) const { return tie(x,y)!=tie(p.x,p.y); }
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
typedef Point<__int128>Pt;

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


struct lin{
	Pt a,b;
};

void ProGamerMove(){
	vector<lin>l(3);
	for(int i=0;i<3;++i){
		ll x,y,a,b;cin>>x>>y>>a>>b;
		l[i].a=Pt(x,y);
		l[i].b=Pt(a,b);
	}
	auto ol=l;
	for(int i=0;i<3;++i){
		l=ol;
		swap(l[i],l[0]);
		for(int it=0;it<2;++it){
			swap(l[0].a,l[0].b);
			for(int it2=0;it2<2;++it2){
				swap(l[1].a,l[1].b);
				swap(l[2].a,l[2].b);
				for(int it3=0;it3<2;++it3){
					swap(l[1],l[2]);
					if(l[0].a==l[1].a)goto done;
				}
			}
		}
	}
	done:
	if(l[0].a!=l[1].a||(l[0].b-l[0].a).dot(l[1].b-l[0].a)<0||!l[0].a.cross(l[0].b,l[1].b)){
		cout<<"NO\n";return;
	}
	if(!onSegment(l[0].a,l[0].b,l[2].a))swap(l[2].a,l[2].b);
	if(!onSegment(l[0].a,l[0].b,l[2].a)||!onSegment(l[0].a,l[1].b,l[2].b)){
		cout<<"NO\n";return;
	}
	__int128 d1=(l[0].a-l[2].a).dist2(),d2=(l[2].a-l[0].b).dist2();
	if(d1>d2)swap(d1,d2);
	if(16*d1<d2){cout<<"NO\n";return;}
	d1=(l[0].a-l[2].b).dist2(),d2=(l[2].b-l[1].b).dist2();
	if(d1>d2)swap(d1,d2);
	if(16*d1<d2){cout<<"NO\n";return;}
	cout<<"YES\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}