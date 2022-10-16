// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
 
#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
 
#define DMAX 505
#define NMAX 
#define MMAX 

#define EPS 1e-9
 
using namespace std;
 
int n, k, nrr = 1, t[2 * DMAX * DMAX];
string s;
 
struct point{
    double x, y;
    int ind;
    point() {   }
    point(const point &a) {x = a.x, y = a.y; ind = a.ind;}
    point(double _x, double _y) { x = _x; y = _y; }
 
    point& operator-(point &a) {point *r = new point(*this); r->x -= a.x, r->y -= a.y; return *r;}
    point& operator+(point &a) {point *r = new point(*this); r->x += a.x, r->y += a.y; return *r;}
    point& operator*(double val) {point *r = new point(*this); r->x *= val, r->y *= val; return *r;}
    point& operator/(double val) {point *r = new point(*this); r->x /= val, r->y /= val; return *r;}
    bool operator<(const point &a) const { if(fabs(x - a.x) < EPS) {if(fabs(y - a.y) < EPS) return false; return y < a.y;} return x < a.x; }
    bool operator==(const point &a) const { if(fabs(x - a.x) < EPS) if(fabs(y - a.y) < EPS) return true; return false; }
    bool operator!=(const point &a) const { return !(*this == a); }
};
 
 
template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
    out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out; 
}
ostream& operator<<(ostream& out, point p) { return out << p.x << ' ' << p.y; }
 
double dx[] = {1, -1, -1, 1};
double dy[] = {1, -1, 1, -1};
 
long double dist(point a, point b) {
    long double X = a.x - b.x;
    long double Y = a.y - b.y;
    return sqrt(X * X + Y * Y);
}
 
struct circle {
    point o;
    double r;
 
    circle() {}
    bool operator==(circle & c) {
        if(fabs(c.r - r) > EPS) return false;
        if(fabs(c.o.x - o.x) > EPS) return false;
        if(fabs(c.o.y - o.y) > EPS) return false;
        return true;
    }
 
    vector <point> intersect(circle c) {
        long double p, h, a, area, d;
        d = dist(o, c.o); 
        if(d > r + c.r) return {};
        if(d < fabs(r - c.r)) return {};
        a = 0.5 * (d  + (r * r - c.r * c.r) / d );
        h = sqrt(r * r - a * a);
        point B = o + (c.o - o) * a / d;
        point aa = c.o - o;
        point ff(-aa.y, aa.x);//aa.y = -aa.y;
        aa = ff * h / d;
        return {B + aa, B - aa};  
    }
 
};
 
struct seg {
    point a, b;
 
};
  
istream& operator>>(istream& in, point &p) { return in >> p.x >> p.y; }
istream& operator>>(istream& in, circle &c) { return in >> c.o >> c.r; }
istream& operator>>(istream& in, seg &s) { return in >> s.a >> s.b; }

long double area(point a, point b, point c) {
    return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
 
circle c[DMAX];
point pts[2 * DMAX * DMAX], buff[2 * DMAX];
int C, V, E, buffsz, sz = 0;
// set <point> inters;

// struct lex_compare {
//     bool operator() (const int& lhs, const int& rhs) const {
//          return pts[lhs] < pts[rhs];
//     }
// };
// set<int, lex_compare> m;

inline int par(int k) {
  if(k == t[k]) 
    return k;
  return t[k] = par(t[k]);
}


void unite(int i, int j){
  t[par(i)] = par(j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < DMAX * DMAX * 2; i++) 
      t[i] = i;

    for(int i = 1; i <= n; i++)
        cin >> c[i];
     
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            if(c[i] == c[j]) swap(c[j], c[n]), n--, j--;
 
    for(int i = 1; i <= n; i++) {
        // dbg(i);
        buffsz = 0;
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            auto in = c[i].intersect(c[j]);
            for(auto p : in)
              buff[buffsz++] = p;
        }
        int init = sz;
        for(int i = 0; i < buffsz; i++) {
            sz++;
            pts[sz] = buff[i];
            pts[sz].ind = sz;
            if(i > 0) unite(sz, init);
        }
        sort(buff, buff+buffsz);
        buffsz = unique(buff, buff + buffsz) - buff;
        // dbg_v(buff, buffsz);
        // dbg(buffsz);
        E += buffsz;
        if(buffsz == 0) C++;
    }
 
    V = sz;
    int u = 0;
    for(int i = 1; i <= sz; i++)
      pts[i].ind = i;

    sort(pts + 1, pts + sz + 1);
    for(int i = 1; i <= sz; i++, u++) {
      int j = i + 1;
      while(j <= sz && pts[i] == pts[j]) {
        unite(pts[i].ind, pts[j].ind);
        j++;
      } 
      i = j - 1;
    }    
    
    for(int i = 1; i <= V; i++)
      if(t[i] == i) C++;

    V = u;
    dbg(V);
    dbg(E);
    dbg(C);
    cout << E - V + C + 1<< '\n';
}