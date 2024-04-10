#include <bits/stdc++.h>
 
#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
 
#define DMAX 550
#define NMAX 
#define MMAX 
 
#define EPS 1e-9
 
using namespace std;
 
int n, k;
string s;
 
struct point{
    double x, y;
     
    point() {   }
    point(const point &a) {x = a.x, y = a.y;}
    point(double _x, double _y) { x = _x; y = _y; }
 
    point operator-(point &a) {point r(*this); r.x -= a.x, r.y -= a.y; return r;}
    point operator+(point &a) {point r(*this); r.x += a.x, r.y += a.y; return r;}
    point operator*(double val) {point r(*this); r.x *= val, r.y *= val; return r;}
    point operator/(double val) {point r(*this); r.x /= val, r.y /= val; return r;}
    bool operator<(const point &a) const { if(fabs(x - a.x) < EPS) return y < a.y; return x < a.x; }
 
    void rotate(long double alfa) {
        long double cx = x;
        x = x * cos(alfa) - y * sin(alfa);
        y = y * cos(alfa) + cx * sin(alfa);
    }
};
 
 
template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
    out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out; 
}
ostream& operator<<(ostream& out, point p) { return out << p.x << ' ' << p.y; }
 
struct line
{
    double m, n;
 
    line(point A, point B) {
        m = (A.y - B.y) / (A.x - B.x) ;
        n = A.y - m * A.x;
    }
 
    line(point A, double _m) {
        // linia de panta _m care trece prin punctul A
        m = _m;
        n = A.y - m * A.x; 
    }
 
    line(double _m, double _n) {
        m = _m;
        n = _n;
    }
 
    point intersect(line l) {
        // returneaza punctul in care se intersecteaza linia this cu linia l
        point O;
        //if(m == l.m)
        // return 
        O.x = (l.n - n) / (m - l.m);
        O.y = m * O.x + n;
        return O;
    }
 
};
 
double dx[] = {1, -1, -1, 1};
double dy[] = {1, 1, -1, -1};
 
long double dist(point a, point b) {
    long double X = a.x - b.x;
    long double Y = a.y - b.y;
    return sqrt(X * X + Y * Y);
}
 
struct circle {
    point o;
    double r;
 
    circle() {}
    circle(point a, point b, point c) {
        point mab = (a + b) / 2;
        point mbc = (c + b) / 2;
        line ab(a, b), bc(b, c);
        line ab1(mab, -1.0/ab.m);
        line bc1(mbc, -1.0/bc.m);
        o = ab1.intersect(bc1);
        r = dist(o, a);
    } 
 
    bool operator==(circle & c) {
        if(fabs(c.r - r) > EPS) return false;
        if(fabs(c.o.x - o.x) > EPS) return false;
        if(fabs(c.o.y - o.y) > EPS) return false;
        return true;
    }
 
    vector <point> intersect(circle c) {
        vector <point> ans;
        point p1;
 
        // if(fabs(dist(o, c.o) - (r + c.r)) <= EPS) {
        //  ans.push_back((o + c.o) / 2.);
        //  return ans;
        // }
        if(dist(o, c.o) > r + c.r) return ans;
 
 
        circle re = c;
        re.o = re.o - o;
        double angle = atan2(re.o.y, re.o.x);
 
        double cc = dist(o, c.o); 
        double p = (cc + r + c.r) / 2.;
        double area = sqrt(p * (p - r) * (p - c.r) * (p - cc));
        double h = 2.0 * area / cc;
 
        double alfa1 = asin(h / r), an1;
 
        an1 = angle + acos(-1) / 2.0 - alfa1;
        for(int i = 0; i < 4; i++) {
            p1.x = r * sin(an1) * dx[i];
            p1.y = r * cos(an1) * dy[i];
            // dbg(dist(p1, re.o));
            if(fabs(dist(p1, re.o) - re.r) < EPS)
                ans.push_back(p1 + o);
        }
 
        an1 = angle + acos(-1) / 2.0 + alfa1;
        for(int i = 0; i < 4; i++) {
            p1.x = r * sin(an1) * dx[i];
            p1.y = r * cos(an1) * dy[i];
            // dbg(dist(p1, re.o));
            if(fabs(dist(p1, re.o) - re.r) < EPS)
                ans.push_back(p1 + o);
        }
 
        return ans;     
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
 
 
circle c[550];
// map <point, int> m;
map <pair<long long, long long>, int> m;
set <double> xs, ys;
vector <short> v[20100];
bool use[40100];
int C, V, E;
// point vp[DMAX];
 
int get_p(point p) {
 
    // dbg(p);
    long double itx = 1e8 * p.x + 0.5;
    long double ity = 1e8 * p.y + 0.5;
 
    long long X = itx;
    long long Y = ity;
    if(m.count({X, Y}) == 0) m[{X, Y}] = m.size();
    int res = m[{X, Y}];
    // dbg(res);
    return m[{X, Y}];
}
 
void dfs(int k) {
    use[k] = 1;
    for(auto i : v[k])
        if(!use[i])
            dfs(i);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
     
    for(int i = 1; i <= n; i++)
        cin >> c[i];
     
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++) {
            if(c[i] == c[j]) swap(c[j], c[n]), n--, j--;
        }
 
    for(int i = 1; i <= n; i++) {
        // dbg(i);
        set <int> inters;
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            // if(c[i] == c[j]) continue;
            // dbg(j);
            auto in = c[i].intersect(c[j]);
            for(auto p : in) {
                // dbg(p);
                int ind = get_p(p);
                inters.insert(ind);
            }
        }
        for(auto i : inters) {
            if(i != *inters.begin())
                v[*inters.begin()].push_back(i),
                v[i].push_back(*inters.begin());
        }
        // dbg(inters.size());
        E += inters.size();
        if(inters.size() == 0) C++;
        // dbg(inters.size());
        // dbg(E);
        // for(auto i : inters) dbg(i);
    }
 
    V = m.size();
    for(int i = 1; i <= V; i++) {
        if(!use[i])
            dfs(i), C++;
    }
    // dbg(V);
    // dbg(E);
    // dbg(C);
    cout << E - V + C + 1<< '\n';
}