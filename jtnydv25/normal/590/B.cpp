#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define vll vector<ll >
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define endl "\n"

#define eps 1e-7
struct pt{
	double x, y;
	pt(ld _x, ld _y){x = _x, y = _y;}
	double dot(pt p){ return x * p.x + y * p.y;}
	pt operator - (pt p){ return pt(x - p.x, y - p.y);}
	pt operator + (pt p){ return pt(x + p.x, y + p.y);}
	pt operator * (double d){ return pt(x * d, y * d);}
	pt operator / (double d){ return pt(x / d, y / d);}
	double norm(){ return sqrt(x * x + y * y);}
	pt dir(){ if(norm() <= eps) return *this; return (*this) / ((*this).norm());}
	pt project(pt p){ return p * ((*this).dot(p));}
	pt perpendicular(pt p){ return (*this) - project(p);}
};
double time_taken(double x1, double y1, double x2, double y2, int vx, int vy, int v){
	pt P = pt(x2 - x1, y2 - y1);
	double r = P.norm();
	if(r < eps) return 0;
	pt unit = (P / r), vel = pt(vx, vy);

	double m = (vel.perpendicular(unit)).norm();
	double speed = sqrt(v * v -	 m * m) + vel.dot(unit);
	return abs(r / speed);
}
const double PI = acos(-1);
int main(){
	int x1, y1, x2, y2, t, v, vx, vy, wx, wy;
	sd(x1), sd(y1), sd(x2), sd(y2); sd(v); sd(t);
	sd(vx), sd(vy), sd(wx), sd(wy);
	double T = time_taken(x1, y1, x2, y2, vx, vy, v);
	if(T <= t + eps){
		cout << setprecision(10) << fixed << T << endl;
		return 0;
	}
	double ans = 1e18;
	clock_t st = clock();
	double cang = 1, sang = 0, delta = 9e-7;
	int i = 0;
	for(double ang = 0; ang < 2 * PI; ang += delta, i++){
		pt vel = pt(vx, vy) + pt(v * cang, v * sang);
		vel = vel * t;
		double x = x1 + vel.x, y = y1 + vel.y;
		ans = min(ans, t  + time_taken(x, y, x2, y2, wx, wy, v));
		cang = (i % 2 == 0) ? cang - sang * delta : cos(ang + delta);
		sang = sqrt(1 - cang * cang); if(ang > PI) sang *= -1;
	}
	cerr << "time taken = " << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
	cout << setprecision(10) << fixed << ans;
}