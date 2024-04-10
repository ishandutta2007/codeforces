#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
uniform_real_distribution randr(0.0, 1.0);

double randreal(){
    return randr(rando);
}

template<class T>
struct point{
    T x{}, y{};
    point(){ }
    template<class U> point(const point<U> &otr): x(otr.x), y(otr.y){ }
    template<class U, class V> point(U x, V y): x(x), y(y){ }
    template<class U> explicit operator point<U>() const{
        return point<U>(static_cast<U>(x), static_cast<U>(y));
    }
    T operator*(const point &otr) const{
        return x * otr.x + y * otr.y;
    }
    T operator^(const point &otr) const{
        return x * otr.y - y * otr.x;
    }
    point operator+(const point &otr) const{
        return {x + otr.x, y + otr.y};
    }
    point &operator+=(const point &otr){
        return *this = *this + otr;
    }
    point operator-(const point &otr) const{
        return {x - otr.x, y - otr.y};
    }
    point &operator-=(const point &otr){
        return *this = *this - otr;
    }
    point operator-() const{
        return {-x, -y};
    }
#define scalarop_l(op) friend point operator op(const T &c, const point &p){ return {c op p.x, c op p.y}; }
    scalarop_l(+) scalarop_l(-) scalarop_l(*) scalarop_l(/)
#define scalarop_r(op) point operator op(const T &c) const{ return {x op c, y op c}; }
    scalarop_r(+) scalarop_r(-) scalarop_r(*) scalarop_r(/)
// #define scalarapply(op) point &operator op(const T &c){ return *this = *this op c; }
    // scalarapply(+=) scalarapply(-=) scalarapply(*=) scalarapply(/=)
#define compareop(op) bool operator op(const point &otr) const{ return pair(x, y) op pair(otr.x, otr.y); }
    compareop(>) compareop(<) compareop(>=) compareop(<=) compareop(==) compareop(!=)
#undef scalarop_l
#undef scalarop_r
// #undef scalarapply
#undef compareop
    ld norm() const{
        return sqrtl(x * x + y * y);
    }
    T squared_norm() const{
        return x * x + y * y;
    }
    ld angle() const{
        return atan2(y, x);
    } // [-pi, pi]
    point<double> unit() const{
        return point<double>(x, y) / norm();
    }
    point perp() const{
        return {-y, x};
    }
    point<double> normal() const{
        return perp().unit();
    }
    point<double> rotate(const double &theta) const{
        return {x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta)};
    }
    point reflect_x() const{
        return {x, -y};
    }
    point reflect_y() const{
        return {-x, y};
    }
    point reflect(const point &o = {}) const{
        return {2 * o.x - x, 2 * o.y - y};
    }
    bool operator||(const point &otr) const{
        return !(*this ^ otr);
    }
};
template<class T> istream &operator>>(istream &in, point<T> &p){
    return in >> p.x >> p.y;
}
template<class T> ostream &operator<<(ostream &out, const point<T> &p){
    return out << "{" << p.x << ", " << p.y << "}";
}
template<class T>
ld distance(const point<T> &p, const point<T> &q){
    return (p - q).norm();
}
template<class T>
T squared_distance(const point<T> &p, const point<T> &q){
    return (p - q).squared_norm();
}
template<class T, class U, class V>
T doubled_signed_area(const point<T> &p, const point<U> &q, const point<V> &r){
    return q - p ^ r - p;
}
template<class T>
T doubled_signed_area(const vector<point<T>> &a){
    if(a.empty()){
        return 0;
    }
    int n = (int)a.size();
    T res = a.back() ^ a.front();
    for(auto i = 1; i < n; ++ i) res += a[i - 1] ^ a[i];
    return res;
}
template<class T>
double angle(const point<T> &p, const point<T> &q){
    return atan2(p ^ q, p * q);
}
template<class T>
bool is_sorted(const point<T> &origin, point<T> p, point<T> q, point<T> r){
    p -= origin, q -= origin, r -= origin;
    T x = p ^ r, y = p ^ q, z = q ^ r;
    return x >= 0 && y >= 0 && z >= 0 || x < 0 && (y >= 0 || z >= 0);
} // check if p->q->r is sorted with respect to the origin
template<class T, class IT>
bool is_sorted(const point<T> &origin, IT begin, IT end){
    for(auto i = 0; i < (int)(end - begin) - 2; ++ i) if(!is_sorted(origin, *(begin + i), *(begin + i + 1), *(begin + i + 2))) return false;
    return true;
} // check if begin->end is sorted with respect to the origin
template<class T>
bool counterclockwise(const point<T> &p, const point<T> &q, const point<T> &r){
    return doubled_signed_area(p, q, r) > 0;
}
template<class T>
bool clockwise(const point<T> &p, const point<T> &q, const point<T> &r){
    return doubled_signed_area(p, q, r) < 0;
}

using pointint = point<int>;
using pointll = point<long long>;
using pointlll = point<__int128_t>;
using pointd = point<double>;
using pointld = point<long double>;

const ld pi = acos(-1);

pointld fermat_point(const pointld &a, const pointld &b, const pointld &c){
    ld sa = distance(b, c), sb = distance(c, a), sc = distance(a, b);
    ld ssa = squared_distance(b, c), ssb = squared_distance(c, a), ssc = squared_distance(a, b);
    if (ssa >= ssb + sb * sc + ssc){
        return a;
    }
    if (ssb >= ssc + sc * sa + ssa){
        return b;
    }
    if (ssc >= ssa + sa * sb + ssb){
        return c;
    }
    ld aa = angle(b - a, c - a), bb = angle(c - b, a - b), cc = angle(a - c, b - c);
    if (aa < 0) aa = -aa; if (bb < 0) bb = -bb; if (cc < 0) cc = -cc;
    ld x = 1 / sin(aa + pi / 3), y = 1 / sin(bb + pi / 3), z = 1 / sin(cc + pi / 3);
    return (((sa * x) / (sa * x + sb * y + sc * z)) * (a - c) + ((sb * y) / (sa * x + sb * y + sc * z)) * (b - c) + c);
}

ld geometric_median(const pointld &a, const pointld &b, const pointld &c){
    pointld X13 = fermat_point(a, b, c);
    return distance(X13, a) + distance(X13, b) + distance(X13, c);
}

ld f(const pointld &a, const pointld &b, const pointld &c, const pointld& p){
    return max({geometric_median(p, a, b), geometric_median(p, b, c), geometric_median(p, c, a)});
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cout << fixed << setprecision(9);
    pointld a, b, c; cin >> a >> b >> c;

    ld spanx = max({a.x, b.x, c.x}) - min({a.x, b.x, c.x}), spany = max({a.y, b.y, c.y}) - min({a.y, b.y, c.y});
    uniform_real_distribution disx((ld)0.0, spanx);
    uniform_real_distribution disy((ld)0.0, spany);

    ld ans = 1e6;
    const int cases = 1;
    ForE(start, 1, 5){
        // cout << "START " << start << endl;
        pointld p(disx(rando) + min({a.x, b.x, c.x}), disy(rando) + min({a.y, b.y, c.y}));
        // if (start <= 1 * cases){
        //     p = a;
        // }
        // else if (start <= 2 * cases){
        //     p = b;
        // }
        // else if (start <= 3 * cases){
        //     p = c;
        // }
        // else if (start <= 4 * cases){
        //     p = pointld((a.x + b.x) / 2, (a.y + b.y) / 2);
        // }
        // else if (start <= 5 * cases){
        //     p = pointld((b.x + c.x) / 2, (b.y + c.y) / 2);
        // }
        // else if (start <= 6 * cases){
        //     p = pointld((c.x + a.x) / 2, (c.y + a.y) / 2);
        // }
        if (start <= 1 * cases){
            p = fermat_point(a, b, c);
        }
        else if (start <= 2 * cases){
            p = pointld((a.x + b.x + c.x) / 3, (a.y + b.y + c.y) / 3);
        }
        ld val = f(a, b, c, p);
        ld tans = val;

        const int maxiter = 100000, scale = 1e7;
        ld step = ((ld)0.5 - (ld)1.0 / scale) / maxiter;
        ld temp = 1e5;
        FordE(counter, maxiter, 0){
            pointld tp(p.x + disx(rando) * (rando() & 1 ? 1 : -1) * (1 / scale + counter * step), p.y + disy(rando) * (rando() & 1 ? 1 : -1) * (1 / scale + counter * step));
            ld tval = f(a, b, c, tp);
            if (tans > tval){
                tans = tval;
            }

            if (val > tval or exp((val - tval) / temp) <= randreal()){
                p = tp;
                val = tval;
            }

            temp *= 0.99995;
        }
        // cout << tans << ' ' << temp << endl;
        ans = min(ans, tans);
    }
    cout << ans << endl;
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/