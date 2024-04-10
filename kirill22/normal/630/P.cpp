#include<bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char& s) {
    string res = "'";
    res += s;
    res += "'";
    return res;
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (i) res += ", ";
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

bool doubleEqual(double a, double b) { //   ==
    return fabs(a - b) < 1e-9;
}

bool doubleLessOrEqual(double a, double b) { //   <=
    return a < b || doubleEqual(a, b);
}

bool doubleLess(long double a, long double b) { //   <
    return a < b && !doubleEqual(a, b);
}

bool doubleGreaterOrEqual(double a, double b) { //   <=
    return a > b || doubleEqual(a, b);
}

bool doubleGreater(long double a, long double b) { //   <
    return a > b && !doubleEqual(a, b);
}

long double mysqrt(long double a) { //   
    if (doubleLess(a, 0)) {
        throw "sqrt(-1)";
    }
    if (a < 0) return 0;
    return sqrt(a);
}

struct Point{ //   
    long double x, y;
    Point() : x(0), y(0) {};
    Point(long double x, long double y) : x(x), y(y) {};
    Point operator +(const Point& a) const { //  
        return Point(x + a.x, y + a.y);
    }
    Point operator -(const Point& a) const { //  
        return Point(x - a.x, y - a.y);
    }
    Point operator -() const { //  
        return Point(-x, -y);
    }
    Point operator *(long double k) const { //    
        return Point(x * k, y * k);
    }
    Point operator /(long double k) const { //    
        return Point(x / k, y / k);
    }
    Point& operator +=(const Point& a) { //   
        return *this = *this + a;
    }
    Point& operator -=(const Point& a) { //   
        return *this = *this - a;
    }
    Point& operator *=(long double k) { //  
        return *this = *this * k;
    }
    Point& operator /=(long double k) { //  
        return *this = *this / k;
    }
    bool operator <(const Point& a) const {
        return doubleLess(y, a.y) || (doubleEqual(y, a.y) && doubleLess(x, a.x));
    }
    bool operator >(const Point& a) const {
        return a < *this;
    }
    bool operator ==(const Point& a) const {
        return doubleEqual(x, a.x) && doubleEqual(y, a.y);
    }
    bool operator <=(const Point& a) const {
        return !(*this > a);
    }
    bool operator >=(const Point& a) const {
        return !(*this < a);
    }
    bool operator !=(const Point& a) const {
        return !(*this == a);
    }
    long double operator *(const Point &b) const { //   sin
        return x * b.y - y * b.x;
    }
    long double operator %(const Point &b) const { //   cos
        return x * b.x + y * b.y;
    }
    long double len() const { //  
        return mysqrt(*this % *this);
    }
    long double len2() const { //    
        return (*this % *this);
    }
    long double distTo(const Point& a) const { //     
        return (*this - a).len();
    }
    long double distTo(const Point& a, const Point& b) const { //     
        long double d = a.distTo(b);
        Point v = *this;
        if (doubleEqual(d, 0)) {
            return v.distTo(a);
            //throw "A = B";
        }
        long double s = (*this - a) * (*this - b);
        return fabs(s) / d;
    }
    long double distTosegment(const Point& a, const Point& b) const { //     
        Point v = *this;
        if (doubleGreater((b - a) % (b - v), 0) && doubleGreater((a - b) % (a - v), 0)) {
            return v.distTo(a, b);
        }
        else {
            return min(v.distTo(a), v.distTo(b));
        }
    }
    Point normalize(long double k = 1) const { //   
        long double l = len();
        if (doubleEqual(l, 0)) {
            if (doubleEqual(k, 0)) return Point();
            throw "zero-size vector";
        }
        return (*this) * (k / l);
    }
    Point symmetry(const Point& a) const { //    a
        return a + a - *this;
    }
    Point getH(const Point& a, const Point& b) const { //      ab
        Point c = *this;
        if (a == b) return a;
        Point v = b - a, u = c - a;
        long double k = (v % u) / v.len();
        v = v.normalize(k);
        Point H = a + v;
        return H;
    }
    Point rotate() const { //   90    
        return Point(-y, x);
    }
    Point rotate(long double alpha) const { //   
        return rotate(cos(alpha), sin(alpha));
    }
    Point rotate(long double cosa, long double sina) const { //     
        Point v = *this, u = v.rotate();
        Point w = v * cosa + u * sina;
        return w;
    }
    bool isZero() const { //    (0, 0)
        return doubleEqual(x, 0) && doubleEqual(y, 0);
    }
    bool isOnLine(const Point& a, const Point& b) const { //     
        return doubleEqual((a - *this) * (b - *this), 0);
    }
    bool isInSegment(const Point& a, const Point& b) const { //     
        return isOnLine(a, b) && doubleLessOrEqual((a - *this) % (b - *this), 0);
    }
    bool isInSegmentStrictly(const Point& a, const Point& b) const { //   ?
        return isOnLine(a, b) && doubleLess((a - *this) % (b - *this), 0);
    }
    long double Angle() const { //     Ox
        return atan2(y, x);
    }
    long double Angle(const Point& a) const { //   
        Point v = *this;
        return atan2(v * a, v % a);
    }
};

long double Angle(const Point& a, const Point& b) { //   
    return atan2(b * a, b % a);
}

int getIntersection(const Point& a, const Point& b, const Point& c, const Point& d, Point& O) { //  
    Point v = b - a;
    long double s1 = (c - a) * (d - a), s2 = (d - b) * (c - b), s = s1 + s2;
    if (doubleEqual(s, 0)) {
        if (!a.isOnLine(c, d)) {
            return 0;
        }
        return 2;
    }
    v = v / s;
    v = v * s1;
    O = a + v;
    return 1;
}

int getIntersectionsegment(const Point& a, const Point& b, const Point& c, const Point& d, Point& O) { //  
    Point v = b - a;
    long double s1 = (c - a) * (d - a), s2 = (d - b) * (c - b), s = s1 + s2;
    if (doubleEqual(s, 0)) {
        if (a.isInSegmentStrictly(c, d)) {
            O = a;
            return 2;
        }
        if (b.isInSegmentStrictly(c, d)) {
            O = b;
            return 2;
        }
        if (a == c || a == d) {
            O = a;
            return 1;
        }
        if (b == c || b == d) {
            O = b;
            return 1;
        }
        return 0;
    }
    v = v / s;
    v = v * s1;
    O = a + v;
    if (O.isInSegment(a, b) && O.isInSegment(c, d)) return 1;
    return 0;
}

int getIntersection(const Point& a, long double ra, const Point& b, long double rb, Point& M, Point& N) { //  
    long double d = a.distTo(b);
    if (doubleLess(ra + rb, d) || doubleLess(d, fabs(ra - rb))) {
        return 0;
    }
    long double A = (ra * ra - rb * rb + d * d) / 2.0 / d;
    long double h = mysqrt(ra * ra - A * A);
    Point v = b - a, u = v.rotate();
    v = v.normalize(A);
    u = u.normalize(h);
    Point H = a + v;
    M = H + u, N = H - u;
    if (u.isZero()) return 1;
    return 2;
}

int getIntersection(const Point& a, const Point& b, const Point& O, long double r, Point& M, Point& N) { //    
    long double h = O.distTo(a, b);
    if (doubleLess(r, h)) {
        return 0;
    }
    Point H = O.getH(a, b), v = b - a;
    long double k = mysqrt(r * r - h * h);
    v = v.normalize(k);
    M = H + v;
    N = H - v;
    if (v.isZero()) return 1;
    return 2;
}

int getTangent(const Point& A, const Point& O, long double r, Point& M, Point& N) { //     
    Point v = O - A;
    long double d = v.len();
    if (doubleLess(d, r)) return 0;
    long double alpha = asin(r / d);
    long double L = mysqrt(d * d - r * r);
    v = v.normalize(L);
    M = A + v.rotate(alpha);
    N = A - v.rotate(alpha);
    if (doubleEqual(r, d)) return 1;
    return 2;
}

void getOutTangent(Point A, long double ra, Point B, long double rb, pair<Point, Point>& P, pair<Point, Point>& Q) { //    2 
    if (ra > rb) {
        swap(ra, rb);
        swap(A, B);
    }
    long double d = (A - B).len();
    Point u = (A - B).rotate(asin(ra / d)).rotate().normalize(ra); // ra ? rb
    P.first = A + u;
    Q.first = A - u;
    Point T1, T2;
    getTangent(A, B, rb - ra, T1, T2);
    P.second = T1 + u;
    Q.second = T2 - u;
}

long double dist(const Point& a, const Point& b) { //   2 
    return (a - b).len();
}

istream &operator >>(istream& in, Point& a) { //  
    in >> a.x;
    in >> a.y;
    return in;
}

ostream &operator <<(ostream& out, Point& a) { //  
    out << a.x << " " << a.y;
    return out;
}

Point middle(const Point& a, const Point& b) { //  
    return (a + b) / 2.0;
}

Point min(const Point& a, const Point& b) {
    return (a < b ? a : b);
}

Point max(const Point& a, const Point& b) {
    return (a > b ? a : b);
}

bool in_triangle(const Point &a, const Point &b, const Point &c, const Point &p) { //     p  abc
	return doubleEqual(abs((a - p) * (b - p)) + abs((b - p) * (c - p)) + abs((c - p) * (a - p)), abs((a - b) * (c - b)));
}

long double S(const Point& a, const Point& b, const Point& c) { //  
    return ((b - a) * (c - a)) / 2.0;
}

int id(const Point& a) { //  
    if (a == Point(0, 0)) return 1;
    if (doubleGreater(a.x, 0) && doubleGreaterOrEqual(a.y, 0)) return 1;
    if (doubleLessOrEqual(a.x, 0) && doubleGreater(a.y, 0)) return 2;
    if (doubleLess(a.x, 0) && doubleLessOrEqual(a.y, 0)) return 3;
    return 4;
}

bool cmp(const Point& a, const Point& b) {
    if (id(a) != id(b)) return id(a) < id(b);
    if (doubleEqual(a *b, 0)) return doubleLess(a.len(), b.len());
    return doubleGreater(a * b, 0);
}

bool cmp2(Point a, Point b, Point c) {
    a -= c;
    b -= c;
    if (id(a) != id(b)) return id(a) < id(b);
    if (a * b == 0) return doubleLess(a.len(), b.len());
    return doubleGreater(a * b, 0);
}

struct line{
    long double a = 1, b = 0, c = 0;
    line() {};
    line(long double a, long double b, long double c) : a(a), b(b), c(c) {};
    line(Point A, Point B) {
        a = B.y - A.y;
        b = A.x - B.x;
        c = - (a * A.x + b * A.y);
    };
    line normalize() const {
        long double x = sqrt(a * a + b * b);
        line ans = *this;
        if (ans.a < 0) x *= -1;
        ans.a /= x;
        ans.b /= x;
        ans.c /= x;
        return ans;
    }
};

bool isonline(const line& l, const Point& p) { //   
    return doubleEqual(l.a * p.x + l.b * p.y + l.c, 0);
}

bool same_sign_equal(long double a, long double b) {
    return (doubleGreaterOrEqual(a, 0) && doubleGreaterOrEqual(b, 0))
    || (doubleLessOrEqual(a, 0) && doubleLessOrEqual(b, 0));
}

struct Polygon{ // 
    int n;
    vector<Point> p; //  
    vector<Point> v; //       
    Polygon() {}
    Polygon(vector<Point>& a) {
        n = a.size();
        p.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = a[i];
        }
        int ind_beg = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < a[ind_beg]) {
                ind_beg = i;
            }
        }
        vector<Point> trash = p;
        for (int i = 0; i < n; i++) {
            p[(i - ind_beg + n) % n] = trash[i];
        }
        for (int i = 1; i < n; i++) {
            v.push_back(p[i] - p[0]);
        }
    }
    Polygon operator+(const Polygon& a) const { //  
        vector<Point> v;
        int i = 0, j = 0;
        while (i < n || j < a.n) {
            if (j == a.n || (i < n && (p[(i + 1) % n] - p[i]) < (a.p[(j + 1) % a.n] - a.p[j]))) {
                v.push_back(p[(i + 1) % n] - p[i]);
                i++;
            }
            else {
                v.push_back(a.p[(j + 1) % a.n] - a.p[j]);
                j++;
            }
        }
        vector<Point> res;
        res.push_back(Point(0, 0));
        for (int i = 0; i < (int) v.size() - 1; i++) {
            res.push_back(Point(res.back().x + v[i].x, res.back().y + v[i].y));
        }
        const long double INF = 5e18;
        Point min_Point1 = Point(INF, INF);
        Point min_Point2 = Point(INF, INF);
        Point min_Point_res = Point(INF, INF);
        for (auto& c : p) {
            min_Point1 = min(min_Point1, c);
        }
        for (auto& c : a.p) {
            min_Point2 = min(min_Point2, c);
        }
        for (auto& c : res) {
            min_Point_res = min(min_Point_res, c);
        }
        Point delta(min_Point1.x + min_Point2.x - min_Point_res.x, min_Point1.y + min_Point2.y - min_Point_res.y);
        for (auto& c : res) {
            c.x += delta.x;
            c.y += delta.y;
        }
        return Polygon(res);
    }
    Polygon operator-(const Polygon& a) const { //  
        vector<Point> now = a.p;
        for (auto& c : now) {
            c.x *= -1;
            c.y *= -1;
        }
        return (*this) + Polygon(now);
    }
    bool is_inside(const Point &a) const { //     
        Point v1 = a - p[0], v2 = a - p.back();
        if (!same_sign_equal(v[0] * v1, v[0] * v.back()) || !same_sign_equal(v.back() * v2, v.back() * v[0])) {
            return false;
        }
        int ind2 = upper_bound(v.begin(), v.end(), v1) - v.begin();
        ind2++;
        ind2 = min(ind2, n - 1);
        int ind1 = ind2 - 1;
        return in_triangle(p[0], p[ind1], p[ind2], a);;
    }
    bool inside(const Point& a) const { //     
        Point to(a.x + 1e10 + 7, a.y - 1e10 + 9);
        int cnt = 0;
        Point U;
        for (int i = 0; i < n; i++) {
            cnt += getIntersectionsegment(p[i], p[(i + 1) % n], a, to, U);
        }
        return cnt % 2 == 1;
    }
    long double S() { // 
        Point beg(0, 0);
        long double ans = 0;
        for (int i = 0; i < n; i++) {
            Point v1 = p[i] - beg, v2 = p[(i + 1) % n] - beg;
            ans += (long double) (v1 * v2);
        }
        return abs(ans) / 2.0;
    }
};

Polygon obl(vector<Point> a) { //   
    int n = a.size();
    Point start = a[0];
    for (int i = 0; i < n; i++) start = min(start, a[i]);
    sort(a.begin(), a.end(), [&] (Point a, Point b) {
         return cmp2(a, b, start); });
    vector<Point> ch;
    for (int i = 0; i < n; i++) {
        while (ch.size() >= 2 && doubleLessOrEqual((ch.back() - ch[(int) ch.size() - 2]) * (a[i] - ch.back()), 0)) {
            ch.pop_back();
        }
        ch.push_back(a[i]);
    }
    return Polygon(ch);
}

ld Pi = 3.14159265358979323846264338;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ld n, r;
    cin >> n >> r;
    ld alpha = Pi / n / 2;
    ld beta = Pi - 3 * alpha;
    ld x = r * sin(alpha) / sin(beta);
    ld ans = x * r * sin(2 * alpha);
    cout << fixed << setprecision(15) << ans * n;
}