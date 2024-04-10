#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

typedef double D;
typedef complex<D> Point;
const D EPS = 1e-8;
typedef vector<Point> Polygon; // 
inline int sign(D a){
    return (a > EPS ? 1 : a < -EPS ? -1 : 0);
}

inline D dot(Point a, Point b){
    return real(conj(a) * b);
}
inline D cross(Point a, Point b){
    return imag(conj(a) * b);
}
inline int ccw(Point a, Point b, Point c) {
    b -= a; c -= a;
    //D len = abs(b) * abs(c); // 1
    if (cross(b, c) > EPS)   return +1; // 
    if (cross(b, c) < -EPS)   return -1; // 
    if (dot(b, c) < 0)     return +2; // c--a--b 
    if (norm(b) < norm(c)) return -2; // a--b--c 
    return 0;                         // ab
}

struct Line : public vector<Point> {
    Line() {}
    Line(const Point& a, const Point& b) {
        push_back(a); push_back(b);
    }
    Point vector() const {
        return back() - front();
    }
};

inline Point curr(const Polygon& a, int x){ return a[x]; }
inline Point next(const Polygon& a, int x){ return a[(x + 1) % a.size()]; }
inline Point prev(const Polygon& a, int x){ return a[(x - 1 + a.size()) % a.size()]; }

inline Point crosspointLL(Line l, Line m){
    D A = cross(l.vector(), m.vector());
    D B = cross(l.vector(), l[1] - m[0]);
    if(sign(A) == 0 && sign(B) == 0) return m[0]; // 
    if(sign(A) == 0) assert(false); // 
    return m[0] + m.vector() * B / A;
}


void convex_cut(Polygon& P, Line l){
    Polygon Q;
    for(int i = 0; i < P.size(); i++){
        Point A = curr(P, i), B = next(P, i);
        if(ccw(l[0], l[1], A) != -1) Q.push_back(A); //Al
        if(ccw(l[0], l[1], A) * ccw(l[0], l[1], B) < 0)
            Q.push_back(crosspointLL(l, Line(A, B)));
    }
    P.swap(Q);
}

inline D area(const Polygon& P) {
    D A = 0;
    for(int i = 0; i < P.size(); i++){
        A += cross(curr(P, i), next(P, i));
    }
    return abs(A) / 2.0;
}

int main(){
    int N, K;
    cin >> N >> K;
    D y[303][303];
    Line l[303][303];
    REP(i, N) REP(j, K + 1) cin >> y[i][j];
    REP(i, N) REP(j, K) l[i][j] = Line(Point(0, y[i][j]), Point(1, y[i][j + 1]));
    vector<double> ans(N);
    REP(x, K){
        Polygon P;
        P.push_back(Point(0, 0));
        P.push_back(Point(1, 0));
        P.push_back(Point(1, 1e4 + 1));
        P.push_back(Point(0, 1e4 + 1));
        double prev_area = area(P);
        REP(i, N){
            convex_cut(P, l[i][x]);
            double cur_area = area(P);
            ans[i] += prev_area - cur_area;
            prev_area = cur_area;
        }
    }
    REP(i, N){
        printf("%.12f\n", ans[i]);
    }
    return 0;
}