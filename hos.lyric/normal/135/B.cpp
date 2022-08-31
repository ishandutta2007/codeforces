#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

double EPS = 1e-10;
const double INF = 1e+10;
const double PI = acos(-1.0);
int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }

struct Pt {
    double x, y;
    Pt() {}
    Pt(double x, double y) : x(x), y(y) {}
    Pt operator+(const Pt &a) const { return Pt(x + a.x, y + a.y); }
    Pt operator-(const Pt &a) const { return Pt(x - a.x, y - a.y); }
    Pt operator*(const Pt &a) const { return Pt(x * a.x - y * a.y, x * a.y + y * a.x); }
    Pt operator-() const { return Pt(-x, -y); }
    Pt operator*(const double &k) const { return Pt(x * k, y * k); }
    Pt operator/(const double &k) const { return Pt(x / k, y / k); }
    double abs() const { return sqrt(x * x + y * y); }
    double abs2() const { return x * x + y * y; }
    double arg() const { return atan2(y, x); }
    double dot(const Pt &a) const { return x * a.x + y * a.y; }
    double det(const Pt &a) const { return x * a.y - y * a.x; }
    bool operator<(const Pt &a) const { return (x != a.x) ? (x < a.x) : (y < a.y); }
    bool operator==(const Pt &a) const { return (sig(x - a.x) == 0 && sig(y - a.y) == 0); }
};
ostream &operator<<(ostream &os, const Pt &a) { os << "(" << a.x << ", " << a.y << ")"; return os; }
double tri(Pt a, Pt b, Pt c) { return (b - a).det(c - a); }

Pt pLL(Pt a, Pt b, Pt c, Pt d) {
    b = b - a; d = d - c;
    return a + b * (c - a).det(d) / b.det(d);
}
int convexCut(int n, Pt p[], Pt a, Pt b, Pt q[]) {
    int m = 0, i;
    p[n] = p[0];
    for (i = 0; i < n; ++i) {
        if (sig(tri(a, b, p[i])) >= 0) q[m++] = p[i];
        if (sig(tri(a, b, p[i])) * sig(tri(a, b, p[i + 1])) < 0) q[m++] = pLL(a, b, p[i], p[i + 1]);
    }
    q[m] = q[0];
    return m;
}


bool isRectangle(int n, Pt p[]) {
    if (n != 4) return 0;
    if (sig((p[1] - p[0]).det(p[2] - p[0])) < 0) return 0;
    int i;
    for (i = 0; i < n; ++i) {
        if (sig((p[i] - p[i + 1]).dot(p[i + 2] - p[i + 1])) != 0) return 0;
    }
    return 1;
}
bool isSquare(int n, Pt p[]) {
    if (!isRectangle(n, p)) return 0;
    int i;
    for (i = 0; i < n; ++i) {
        if (sig((p[i] - p[i + 1]).abs() - (p[i + 2] - p[i + 1]).abs()) != 0) return 0;
    }
    return 1;
}

const int N = 8;
Pt P[20];

int main() {
    int i, j;
    int m, n;
    Pt a[20], b[20];
    
    int mm, mmm;
    Pt aa[20], aaa[20];
    double area;
    
    int ou;
    
    int perm[20];
    
    for (; ; ) {
        for (i = 0; i < N; ++i) {
            if (!~scanf("%lf%lf", &P[i].x, &P[i].y)) break;
        }
        if (i < N) break;
        
        /*
        for (h = 0; h < 1 << N; ++h) {
            m = n = 0;
            for (i = 0; i < N; ++i) {
                if (h & 1 << i) {
                    b[n++] = P[i];
                } else {
                    a[m++] = P[i];
                }
            }
        */
        for (i = 0; i < N; ++i) {
            perm[i] = i;
        }
        do {
            m = n = N / 2;
            for (i = 0; i < m; ++i) a[i] = P[perm[i]];
            for (j = 0; j < n; ++j) b[j] = P[perm[m + j]];
            
            for (i = 0; i < m; ++i) a[m + i] = a[i];
            for (j = 0; j < n; ++j) b[n + j] = b[j];
            if (!isSquare(m, a)) {
                goto failed;
            }
            if (!isRectangle(n, b)) {
                goto failed;
            }
            
            /*
            mm = m;
            for (i = 0; i <= mm; ++i) aa[i] = a[i];
            for (j = 0; j < n; ++j) {
                if (mm == 0) break;
                mmm = convexCut(mm, aa, b[j], b[j + 1], aaa);
                mm = mmm;
                for (i = 0; i <= mm; ++i) aa[i] = aaa[i];
            }
            area = 0;
            for (i = 0; i < mm; ++i) {
                area += aa[i].det(aa[i + 1]);
            }
            if (sig(area) == 0) {
                goto failed;
            }
            */
/*
cout<<"area = "<<area<<endl;
cout<<"aa : ";pv(aa,aa+mm);
cout<<"a : ";pv(a,a+m+1);
cout<<"b : ";pv(b,b+n+1);
*/
            
            puts("YES");
            ou = 0;
            for (i = 0; i < m; ++i) {
                if (ou++) printf(" ");
                printf("%d", perm[i] + 1);
            }
            puts("");
            ou = 0;
            for (j = 0; j < n; ++j) {
                if (ou++) printf(" ");
                printf("%d", perm[m + j] + 1);
            }
            puts("");
            goto found;
        failed:;
        } while (next_permutation(perm, perm + N));
        puts("NO");
    found:;
    }
    
    return 0;
}