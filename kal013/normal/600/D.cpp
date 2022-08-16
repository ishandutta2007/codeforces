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


//small non recursive functions should me made inline
//do not read input in double format if they are integer points
// #define ld double
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


struct pt{
    #define F1 ld
    #define F2 ld
    #define F3 ld
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
    bool operator < (const pt &p) const{ return lt(y,p.y)||(eq(y,p.y)&&lt(x,p.x));}
    inline bool operator == (const pt &r) const {return (eq(y,r.y) && eq(x,r.x));}
    bool operator > (const pt &p) const{ return p<pt(x,y);}
    inline bool operator <= (const pt &r) const {return !(*this>r);}
    inline bool operator >= (const pt &r) const {return !(*this<r);}
    inline bool operator != (const pt &r) const {return !(*this==r);}
    friend istream& operator >> (istream& is, pt& p){return is>>p.x>>p.y;}
    friend ostream& operator << (ostream& os, const pt& p) {return os<<"("<<p.x<<","<<p.y<<")";}
};
ld dot(pt p,pt q) {return p.x*q.x+p.y*q.y;}
ld dist2(pt p, pt q) {return dot(p-q,p-q);}  
ld dist(pt p,pt q) {return sqrt(dist2(p,q));}   //https://acm.timus.ru/status.aspx?space=1
ld norm2(pt p) {return dot(p,p);}
ld norm(pt p) {return sqrt(norm2(p));}
ld cross(pt p, pt q) { return p.x*q.y-p.y*q.x;}

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
  return sqrt(dist2(c, ProjectPointSegment(a, b, c)));}
// compute distance from c to line between a and b
ld DistancePointLine(pt a, pt b, pt c) {
  return sqrt(dist2(c, ProjectPointLine(a, b, c)));}
// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(pt a, pt b, pt c, pt d) { 
  return eq(cross(b-a, c-d),0); }
bool LinesCollinear(pt a, pt b, pt c, pt d) { 
  return LinesParallel(a, b, c, d) && eq(cross(a-b, a-c),0) && eq(cross(c-d, c-a),0);}
// determine if line segment from a to b intersects with line segment from c to d
bool SegmentsIntersect(pt a, pt b, pt c, pt d) {
  if (LinesCollinear(a, b, c, d)) {
    //a->b and c->d are collinear and have one point common
    if(eq(dist2(a,c),0)||eq(dist2(a,d),0)||eq(dist2(b,c),0)||eq(dist2(b,d),0)) return true;
    if(gt(dot(c-a,c-b),0)&&gt(dot(d-a,d-b),0)&&gt(dot(c-b,d-b),0)) return false;
    return true;}
  if(gt(cross(d-a,b-a)*cross(c-a,b-a),0)) return false;//c,d on same side of a,b
  if(gt(cross(a-c,d-c)*cross(b-c,d-c),0)) return false;//a,b on same side of c,d
  return true;}
// compute intersection of line passing through a and b
// with line passing through c and d,assuming that **unique** intersection exists;
//*for segment intersection,check if segments intersect first
pt ComputeLineIntersection(pt a,pt b,pt c,pt d){
  b=b-a;d=c-d;c=c-a;//lines must not be collinear
  assert(gt(dot(b, b),0)&&gt(dot(d, d),0));
  return a + b*cross(c, d)/cross(b, d);}
//returns true if point a,b,c are collinear and b lies between a and c
bool between(pt a,pt b,pt c){
  if(!eq(cross(b-a,c-b),0))return 0;//not collinear
  return le(dot(b-a,b-c),0);
}
//compute intersection of line segment a-b and c-d
pt ComputeSegmentIntersection(pt a,pt b,pt c,pt d){
  if(!SegmentsIntersect(a,b,c,d))return {INF,INF};//don't intersect
  //if collinear then infinite intersection points, this returns any one
  if(LinesCollinear(a,b,c,d)){if(between(a,c,b))return c;if(between(c,a,d))return a;return b;}
  return ComputeLineIntersection(a,b,c,d);
}
// compute center of circle given three points - *a,b,c shouldn't be collinear
pt ComputeCircleCenter(pt a,pt b,pt c){
  b=(a+b)/2;c=(a+c)/2;
  return ComputeLineIntersection(b,b+RotateCW90(a-b),c,c+RotateCW90(a-c));}
//point in polygon using winding number -> returns 0 if point is outside
//winding number>0 if point is inside and equal to 0 if outside
//draw a ray to the right and add 1 if side goes from up to down and -1 otherwise
bool PointInPolygon(const vector<pt> &p,pt q){
  int n=p.size(),windingNumber=0;
  for(int i=0;i<n;++i){
    if(eq(dist2(q,p[i]),0)) return 1;//q is a vertex
    int j=(i+1)%n;
    if(eq(p[i].y,q.y)&&eq(p[j].y,q.y)) {//i,i+1 vertex is vertical
      if(le(min(p[i].x,p[j].x),q.x)&&le(q.x,max(p[i].x, p[j].x))) return 1;}//q lies on boundary
    else {
      bool below=lt(p[i].y,q.y);
      if(below!=lt(p[j].y,q.y)) {
        auto orientation=orient(q,p[j],p[i]);
        if(orientation==0) return 1;//q lies on boundary i->j
        if(below==(orientation>0)) windingNumber+=below?1:-1;}}}
  return windingNumber==0?0:1;
}
// determine if point is on the boundary of a polygon
bool PointOnPolygon(const vector<pt> &p,pt q) {
  for (int i = 0; i < p.size(); i++)
    if (eq(dist2(ProjectPointSegment(p[i],p[(i+1)%p.size()],q),q),0)) return true;
  return false;}
// Compute area or centroid of any polygon (coordinates must be listed in cw/ccw
//fashion.The centroid is often known as center of gravity/mass
ld ComputeSignedArea(const vector<pt> &p) {
  ld ans=0;
  for(int i = 0; i < p.size(); i++) {
    int j = (i+1) % p.size();
    ans+=cross(p[i],p[j]);
  } return ans / 2.0;}
ld ComputeArea(const vector<pt> &p) {
  return fabs(ComputeSignedArea(p));
}
// compute intersection of line through points a and b with
// circle centered at c with radius r > 0
vector<pt> CircleLineIntersection(pt a, pt b, pt c, ld r) {
  vector<pt> ret;
  b = b-a;a = a-c;
  ld A = dot(b, b),B = dot(a, b),C = dot(a, a) - r*r,D = B*B - A*C;
  if (lt(D,0)) return ret;	//don't intersect
  ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
  if (gt(D,0)) ret.push_back(c+a+b*(-B-sqrt(D))/A);
  return ret;}

// compute intersection of circle centered at a with radius r
// with circle centered at b with radius R
vector<pt> CircleCircleIntersection(pt a, pt b, ld r, ld R) {
  vector<pt> ret;
  ld d = sqrt(dist2(a, b)),d1=dist2(a,b);
  pt inf(INF,INF);
  if(eq(d1,0)&&eq(r,R)){ret.pb(inf);return ret;}//circles are same return (INF,INF) 
  if(gt(d,r+R) || lt(d+min(r, R),max(r, R)) ) return ret;  
  ld x = (d*d-R*R+r*r)/(2*d),y = sqrt(r*r-x*x);
  pt v = (b-a)/d;
  ret.push_back(a+v*x + RotateCCW90(v)*y);
  if (gt(y,0)) ret.push_back(a+v*x - RotateCCW90(v)*y);
  return ret;}
ld CircleCircleIntersectionArea(pt c1,ld r1,pt c2,ld r2){
	if(lt(r1,r2))swap(c1,c2),swap(r1,r2);
	ld d=dist2(c1,c2),d1=dist(c1,c2);
	if(le(r1+r2,d1))return 0;
	if(ge(r1-r2,d1))return PI*r2*r2;
	ld alfa=acos((d+r1*r1-r2*r2)/(2*d1*r1));
	ld beta=acos((d+r2*r2-r1*r1)/(2*d1*r2));
	return alfa*r1*r1+beta*r2*r2-sin(2*alfa)*r1*r1/2-sin(2*beta)*r2*r2/2;}
//compute centroid of simple polygon by dividing it into disjoint triangles
//and taking weighted mean of their centroids (Jerome)
pt ComputeCentroid(const vector<pt> &p) {
  pt c(0,0),inf(INF,INF);
  ld scale = 6.0 * ComputeSignedArea(p);
  if(p.empty())return inf;//empty vector
  if(eq(scale,0))return inf;//all points on straight line
  for (int i = 0; i < p.size(); i++){
    int j = (i+1) % p.size();
    c = c + (p[i]+p[j])*cross(p[i],p[j]);}
  return c / scale;}
// tests whether or not a given polygon (in CW or CCW order) is simple
bool IsSimple(const vector<pt> &p) {
  for (int i = 0; i < p.size(); i++) {
    for (int k = i+1; k < p.size(); k++) {
      int j = (i+1) % p.size();
      int l = (k+1) % p.size();
      if (i == l || j == k) continue;
      if (SegmentsIntersect(p[i], p[j], p[k], p[l])) 
        return false;}}
  return true;}
/*point in convex polygon
****bottom left point must be at index 0 and top is the index of upper right vertex
****and counter clockwise if not call make_hull once*/
int pointinConvexPolygon(vector<pt>& poly,pt point, int top) {
	if (point < poly[0] || point > poly[top]) return 1;//1 for outside and 0 for on/ -1 inside
	auto orientation = orient(point, poly[top], poly[0]);
	
	if (orientation == 0) {
		if (point == poly[0] || point == poly[top]) return 0;
		return top == 1 || top + 1 == poly.size() ? 0 : -1;//checks if point lies on boundary when
		//bottom and top points are adjacent
	} else if (orientation < 0) {
		auto itRight = lower_bound(poly.begin() + 1, poly.begin() + top, point);
		return orient(itRight[0], point, itRight[-1]);
  	} else {
		auto itLeft = upper_bound(poly.rbegin(), poly.rend() - top-1, point);
		return (orient(itLeft == poly.rbegin() ? poly[0] : itLeft[-1], point, itLeft[0]));
  	}
}
/*maximum distance between two points in convexy polygon using rotating calipers
make sure that polygon is convex. if not call make_hull first
*/
ld maxDist2(vector<pt>& poly) { //https://open.kattis.com/problems/roberthood
	int n = poly.size();
	if (n==2) return dist2(poly[0],poly[1]);
	ld res=0;
	for (int i = 0, j = n < 2 ? 0 : 1; i < j; ++i)

		for (;; j = (j+1) %n) {
	  		res = max(res, dist2(poly[i], poly[j]));
	  	if (gt(cross(poly[(j+1 )% n] - poly[j],poly[i+1] - poly[i]),0)) break;
	}
	return res;
}
//Line polygon intersection: check if given line intersects any side of polygon
//if yes then line intersects. If no, then check if its midpoint is inside polygon
//if midpoint is inside then line is inside else outside



inline bool cmp_x(pt a,pt b){
    return (lt(a.x,b.x) || (eq(a.x,b.x) && lt(a.y,b.y)));
}
inline int ccw(pt a,pt b,pt c){
    F2 d=((b-a)^(c-a));
    if (d==0) return 0;   if (d<0) return -1;
    return 1;
}
// const ll INF=1e18;
struct convex_hull{
    vector<pt> down;
    vector<pt> up;
    int n=0;
    convex_hull(): n(0ll) {};
    convex_hull(vector<pt> points,bool issort=false){
        down=points;
        if (!issort) sort(all(down),cmp_x); n=down.size();
        up.resize(n);  
        For(i,n) up[i]=down[i];
        build();
    }
    convex_hull operator = (const convex_hull& a){
        down=a.down;n=down.size(); // up=a.up;
        return *this;
    }
    void build(){
        int m=0;
        if (n<=1){ return; }
        For(i,n){
            while (m>1 && ccw(down[m-2],down[m-1],down[i])<=0) --m;
            down[m++]=down[i];
        }
        down.resize(m);
        m=0; //convert convex hull trick to convex hull
        For(i,n){
            while(m>1 && ccw(up[m-2],up[m-1],up[i])>=0) --m;
            up[m++]=up[i];
        }
        up.resize(m);
        n=m;
    }
    void clear(){
        down.clear();
        up.clear();
        n=0;
    }
    convex_hull merger(const convex_hull& a) const {
        vector<pt> points(a.down.size()+down.size());
        merge(down.begin(),down.end(),a.down.begin(),a.down.end(),points.begin());
        convex_hull b(points,true);
        return b;
    }
    vector<pt> All(){
    	vector<pt> cu=down;
    	for(int i=(int)up.size()-2;i>0;--i) cu.pb(up[i]);
    	return cu;
    }
    ll min(ld x){
        if (n==0) return INF;
        int low=0,high=n-1;
        pt line={x,1};
        while (low<high){
            int mid=(low+high)/2;
            if (down[mid]*line<down[mid+1]*line){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return down[low]*line;
    }
    friend ostream& operator << (ostream& os, const convex_hull& p) {return os<<"{"<<p.n<<" : "<<p.down<<"}";}
};

const int maxn=2300;
vector<pt> pos;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(25);
	pt a,b;
	ll r1,r2;
	cin>>a>>r1;
	cin>>b>>r2;
	cout<<CircleCircleIntersectionArea(a,r1,b,r2)<<endl;
	
	// int n;
	// cin>>n;
	// ll R;
	// // cin>>R;
	// pos.resize(n);
	// For(i,n) cin>>pos[i];
	// trace(ComputeCentroid(pos));
	// reverse(all(pos));
	// ld peri=0;
	// // trace(pos);
	// convex_hull U(pos);
	// pos=U.All();
	// // trace(pos);
	// cout<<sqrt(maxDist2(pos))<<endl;

	return 0;
}