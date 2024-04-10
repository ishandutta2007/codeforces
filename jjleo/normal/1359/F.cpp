#include <bits/stdc++.h>
#define maxn 50086 

using namespace std;

const double eps = 1e-9;

inline bool equal(double x, double y){
	return fabs(x - y) < eps;
}

struct Point{
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y){}
};

inline bool convexHullCmp(Point a, Point b){
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}

typedef Point Vector;

inline Vector operator + (Vector A, Vector B){
    return Vector(A.x + B.x, A.y + B.y);
}

inline Vector operator - (Vector A, Vector B){
    return Vector(A.x - B.x, A.y - B.y);
}

inline Vector operator * (Vector A, double p){
    return Vector(A.x * p, A.y * p);
}

inline Vector operator * (double p, Vector A){
    return Vector(A.x * p, A.y * p);
}

inline Vector operator / (Vector A, double p){
    return Vector(A.x / p, A.y / p);
}

inline Vector operator / (double p, Vector A){
    return Vector(A.x / p, A.y / p);
}

inline double dot(Vector A, Vector B){
    return A.x * B.x + A.y * B.y;
}

inline double cross(Vector A, Vector B){
    return A.x * B.y - A.y * B.x;
}

inline bool toLeftTest(Vector A, Vector B){//AB AB  
    return cross(A, B) <= 0;
}

inline double length(Vector A){
    return sqrt(dot(A, A));
}

inline Vector rotate(Vector A, double rad){//rad 
    return Vector(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad));
}

struct Line{
    Point p;
    Vector v;
    Line(Point a = Point(0, 0), Point b = Point(0, 0)):p(a), v(b - a){}// a -> b
};

inline bool polarAngleCmp(Line x, Line y){
	double agx = atan2(x.v.y, x.v.x), agy = atan2(y.v.y, y.v.x);
	return equal(agx, agy) ? agx < agy : toLeftTest(x.v, y.p - x.p);
}

inline Point getLineIntersection(Line x, Line y){
    double t = cross(y.v, x.p - y.p) / cross(x.v, y.v);
    return x.p + t * x.v;
}

inline double distanceToLine(Point P, Line l){
    return fabs(cross(l.v, P - l.p) / length(l.v));
}

inline double getLineY(Line l, double x){
	return l.p.y + (x - l.p.x) / l.v.x * l.v.y;
}

double X;

inline bool operator < (Line a, Line b){
	return getLineY(a, X) < getLineY(b, X);
}

set<pair<Line, int> > st;

int n;
int v[maxn];
Line l[maxn];
set<pair<Line, int> >::iterator it[maxn], It;

inline bool checkInter(Line a, Line b, int i, int j, double t){
	if(equal(cross(a.v, b.v), 0)){
		if(!equal(cross(a.p - b.p, a.v), 0)) return false;
		double V = 0;
		if((b.p.x - a.p.x) * a.v.x > 0) V += v[i];
		if((a.p.x - b.p.x) * b.v.x > 0) V += v[j];
		return V * t >= length(a.p - b.p);
	}
	Point p = getLineIntersection(a, b);
	double x = length(p - a.p), y = length(p - b.p);
	//printf("%lf %lf %lf %d %d--\n", t, (p.x - a.p.x) * a.v.x, (p.x - b.p.x) * b.v.x, i, j);
	if((p.x - a.p.x) * a.v.x < 0 && !equal(p.x - a.p.x, 0)) return false;
	if((p.x - b.p.x) * b.v.x < 0 && !equal(p.x - b.p.x, 0)) return false;
	if(x > v[i] * t || y > v[j] * t) return false;
	return true;
}

struct Node{
	double x;
	int y, z;
}a[maxn];


inline bool cmp(Node a, Node b){
	return a.x < b.x;
}

inline bool check(double t){
	for(int i = 1;i <= n;i++){
		double x = l[i].p.x, xx = x + t * v[i] * l[i].v.x;
		if(x > xx) swap(x, xx);
		a[i] = (Node){x, i, 0};
		a[i + n] = (Node){xx, i, 1};
	}
	sort(a + 1, a + 1 + n * 2, cmp);
	st.clear();
	for(int i = 1;i <= n * 2;i++){
		//printf("%d %d--\n", t, a[i].y, a[i].z);
		X = a[i].x;
		if(a[i].z == 0){
			It = st.lower_bound({l[a[i].y], a[i].y});
			if(It != st.end()){
				if(checkInter(l[a[i].y], It->first, a[i].y, It->second, t)) return true;
			}
			if(!st.empty() && It != st.begin()){
				if(checkInter(l[a[i].y], prev(It)->first, a[i].y, prev(It)->second, t)) return true;
			}
			st.insert({l[a[i].y], a[i].y});//firstit second 
		}else{
			st.erase({l[a[i].y], a[i].y}); 
			It = st.lower_bound({l[a[i].y], a[i].y});
			if(!st.empty() && It != st.end() && It != st.begin()){
				if(checkInter(It->first, prev(It)->first, It->second, prev(It)->second, t)) return true;
			}
		}
	} 
	return false;
}


int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%lf%lf%lf%lf%d", &l[i].p.x, &l[i].p.y, &l[i].v.x, &l[i].v.y, &v[i]);
		double mo = length(Vector(l[i].v.x, l[i].v.y));
		l[i].v.x /= mo, l[i].v.y /= mo;
	}
	double l = 0, r = 1e13, mid;
	for(int i = 1;i <= 100;i++){
		mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid;
	}
	if(l >= 1e12) printf("No show :(");
	else printf("%.15lf", l);
}