#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,a) FOR(i,0,(a)-1)
#define SIZE(a) (int)(a).size()

typedef vector<int> vi;


#define PB push_back
#define snd second
#define fst first
typedef pair<int, int> Pii;
typedef vector<Pii> vpii;
typedef long long ll;
typedef vector<ll> vll;


const long double EPS = 1e-9;
inline bool IsZero(double x){ return x>=-EPS && x<=EPS; }
#define POINTT long double 
#define POINTR long double 
struct POINT {
    POINTT x,y;
    POINT(POINTT wx, POINTT wy) : x(wx), y(wy) {}
    POINT() {}
    bool operator ==(POINT& a) {return IsZero(a.x-x) && IsZero(a.y-y);}
};
#define SQ(x) ((x)*(x))
vector<POINT> CirclesCross(POINT c1, POINTR c1r, POINT c2, POINTR c2r){
  vector<POINT> r;
  c2.x -= c1.x; c2.y-= c1.y;
  if (IsZero(c2.x) && IsZero(c2.y)) return r;
  double A = (-SQ(c2r)+SQ(c1r)+SQ(c2.x)+SQ(c2.y))/2.0;
  if (IsZero(c2.y)){
    double x = A/c2.x; double y2=SQ(c1r)-SQ(x);
    if (y2 <-EPS) return r;
    if(IsZero(y2)) r.PB(POINT(c1.x+x,c1.y));
    else{
      r.PB(POINT(c1.x+x,c1.y+sqrt(y2)));
      r.PB(POINT(c1.x+x,c1.y-sqrt(y2)));
    }
    return r;
  }
  double a = SQ(c2.x) + SQ(c2.y);
  double b = -2.0 *A * c2.x;
  double d = 4.0*((SQ(c2.x)+SQ(c2.y))*SQ(c1r)-A*A);
  if (d<-EPS) return r;
  double x = -b/(2.0*a);
  if (IsZero(d)) r.PB(POINT(c1.x + x, c1.y+(A - c2.x*x)/c2.y));
  else{
    double e = sqrt(d)*c2.y/(2.0*a);
    r.PB(POINT(c1.x+x+e, c1.y+(A-c2.x*(x+e))/c2.y));
    r.PB(POINT(c1.x+x-e, c1.y+(A-c2.x*(x-e))/c2.y));
  }
  return r;
}


struct circle {
	POINT P; 
	POINTT r;
};



int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "2\n";
		return 0;
	}
	if (n == 2) {
		vector<circle> circles(2);
		REP(i, 2) cin >> circles[i].P.x >> circles[i].P.y >> circles[i].r;
		auto w = CirclesCross(circles[0].P, circles[0].r, 
									  circles[1].P, circles[1].r);
									  
		if (SIZE(w) == 2) cout << "4\n";
		else cout << "3\n";
		return 0;
	
	}
	vector<circle> circles(3);
	REP(i, 3) cin >> circles[i].P.x >> circles[i].P.y >> circles[i].r;
	int comps = 1, edges = 0;
	vector<POINT> allv;
	REP(i, 3) {
		vector<POINT> v;
		REP(j, 3) {
			if (i != j) {
				auto w = CirclesCross(circles[i].P, circles[i].r, 
									  circles[j].P, circles[j].r);
				cerr << i << " " << j << " : \n" << circles[i].P.x << 
				 " " << circles[i].P.y << " " << circles[i].r << 
				"\n" << SIZE(w) << "\n";
				for (auto p : w) {
					bool zle = false;
					for (auto q : v) {
						if (p == q) zle = true;
					}
					if (!zle) v.PB(p);
				}
			}
		}
		if (v.empty()) comps++;
		else {
			edges += SIZE(v);
			for (auto p : v) {
				bool zle = false;
				for (auto q : allv) {
					if (p == q) zle = true;
				}
				if (!zle) allv.PB(p);
			}
		}
	}
	int points = SIZE(allv);
	if (comps == 4) comps--;
	int f = edges - points + comps + 1;
	cout << f << "\n";
}