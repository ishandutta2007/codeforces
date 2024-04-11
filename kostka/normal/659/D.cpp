//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define real long long //albo long double
const real eps=1e-9;
inline bool iszero(real x){return x<=eps && x>=-eps;}
struct pt {
    real x,y;
    pt(real xx=0,real yy=0):x(xx),y(yy){}
    bool operator==(pt &a){return iszero(a.x-x) && iszero(a.y-y);}
};
bool operator<(const pt &a, const pt &b) {
    if (a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}
ostream& operator<<(ostream &s,pt p) {return s<<"("<<p.x<<","<<p.y<<")";}

pt operator+(pt a,pt b){return pt(a.x+b.x,a.y+b.y);}
pt operator-(pt a,pt b){return pt(a.x-b.x,a.y-b.y);}
pt operator*(pt a,real r){return pt(a.x*r,a.y*r);}
real vec(pt a,pt b){return a.x*b.y-a.y*b.x;}
real det(pt a,pt b,pt c){return vec(b-a,c-a);}

pt operator*(pt a,pt b){return pt(a.x*b.x-a.y*b.y,b.x*a.y+b.y*a.x);}
real sqabs(pt a){return a.x*a.x+a.y*a.y;}
pt operator/(pt a,pt b) {return (a*pt(b.x,-b.y))/sqabs(b);}

real abs(pt a){return sqrt(a.x*a.x+a.y*a.y);}
real dist(pt a,pt b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
real sqdist(pt a,pt b){return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}

real arg(pt a){return atan2(a.y,a.x);}//z przedzialu [-pi,pi]
real skal(pt a,pt b){return a.x*b.x+a.y*b.y;}

// odleglosc A od prostej BC
real dist(pt a,pt b,pt c){return abs(det(b,c,a))/dist(b,c);}
//dlugosc (ze znakiem) rzutu A na prosta B
real dlrzut(pt a,pt b){return skal(a,b)/abs(b);}

bool przecinanie_wl(pt a,pt b,pt c,pt d) {
    real d1=vec(b-a,c-a),d2=vec(b-a,d-a);
    if (!(d1>eps && d2<-eps) && !(d1<-eps && d2>eps)) return 0;
    d1=vec(d-c,a-c),d2=vec(d-c,b-c);
    if (!(d1>eps && d2<-eps) && !(d1<-eps && d2>eps)) return 0;
    return 1;
}

bool inpoly(pt a, vector<pt> &pol) {
    pt b(3e8+500.0,4e6+77777.0);
    int pr=0;
    for(int i=0; i<(int)pol.size(); i++)
      pr+=przecinanie_wl(a,b,pol[i],pol[(i+1)%(int)(pol.size())]);
    return pr%2;
}

int main()
{
  int n;
  cin >> n;
  vector <pt> P(n);
  for(int i=0; i<n; i++)
  {
    cin >> P[i].x >> P[i].y;
    P[i].x *= 2;
    P[i].y *= 2;
  }
  //P.pop_back();
  int ile = 0;
  for(int i=0; i<n-1; i++)
  {
    int kierx = P[i+1].x - P[i].x;
    int kiery = P[i+1].y - P[i].y;
    int wskx = (kierx == 0) ? 0 : (kierx / abs(kierx));
    int wsky = (kiery == 0) ? 0 : (kiery / abs(kiery));
    pt nowy = pt(P[i+1].x + wskx, P[i+1].y + wsky);
    //cerr << nowy << "\n";
    if(inpoly(nowy, P))
      ile++;
  }
  cout << ile << "\n";
  return 0;
}