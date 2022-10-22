#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 1e5 + 5;

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
#define scalarapply(op) point &operator op(const T &c){ return *this = *this op c; }
    scalarapply(+=) scalarapply(-=) scalarapply(*=) scalarapply(/=)
#define compareop(op) bool operator op(const point &otr) const{ return pair(x, y) op pair(otr.x, otr.y); }
    compareop(>) compareop(<) compareop(>=) compareop(<=) compareop(==) compareop(!=)
#undef scalarop_l
#undef scalarop_r
#undef scalarapply
#undef compareop
    long double norm() const{
        return sqrt(x * x + y * y);
    }
    T squared_norm() const{
        return x * x + y * y;
    }
    long double angle() const{
        return atan2(y, x);
    } // [-pi, pi]
    point<long double> unit() const{
        return point<long double>(x, y) / norm();
    }
    point perp() const{
        return {-y, x};
    }
    point<long double> normal() const{
        return perp().unit();
    }
    point<long double> rotate(const long double &theta) const{
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
long double distance(const point<T> &p, const point<T> &q){
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
long double angle(const point<T> &p, const point<T> &q){
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

template<class T>
struct point3{
    T x{}, y{}, z{};
    point3(){ }
    template<class U> point3(const point3<U> &otr): x(otr.x), y(otr.y), z(otr.z){ }
    template<class U, class V, class W> point3(U x, V y, W z): x(x), y(y), z(z){ }
    template<class U> explicit operator point3<U>() const{
        return point3<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(z));
    }
    T operator*(const point3 &otr) const{
        return x * otr.x + y * otr.y + z * otr.z;
    }
    point3 operator^(const point3 &otr) const{
        return {y * otr.z - z * otr.y, z * otr.x - x * otr.z, x * otr.y - y * otr.x};
    }
    point3 operator+(const point3 &otr) const{
        return {x + otr.x, y + otr.y, z + otr.z};
    }
    point3 &operator+=(const point3 &otr){
        return *this = *this + otr;
    }
    point3 operator-(const point3 &otr) const{
        return {x - otr.x, y - otr.y, z - otr.z};
    }
    point3 &operator-=(const point3 &otr){
        return *this = *this - otr;
    }
    point3 operator-() const{
        return {-x, -y, -z};
    }
#define scalarop_l(op) friend point3 operator op(const T &c, const point3 &p){ return {c op p.x, c op p.y, c op p.z}; }
    scalarop_l(+) scalarop_l(-) scalarop_l(*) scalarop_l(/)
#define scalarop_r(op) point3 operator op(const T &c) const{ return {x op c, y op c, z op c}; }
    scalarop_r(+) scalarop_r(-) scalarop_r(*) scalarop_r(/)
#define scalarapply(op) point3 &operator op(const T &c){ return *this = *this op c; }
    scalarapply(+=) scalarapply(-=) scalarapply(*=) scalarapply(/=)
#define compareop(op) bool operator op(const point3 &otr) const{ return tuple(x, y, z) op tuple(otr.x, otr.y, otr.z); }
    compareop(>) compareop(<) compareop(>=) compareop(<=) compareop(==) compareop(!=)
#undef scalarop_l
#undef scalarop_r
#undef scalarapply
#undef compareop
    long double norm() const{
        return sqrt(x * x + y * y + z * z);
    }
    T squared_norm() const{
        return x * x + y * y + z * z;
    }
    point3<long double> unit() const{
        return point3<long double>(x, y, z) / norm();
    }
    point3 reflect_x() const{
        return {x, -y, -z};
    }
    point3 reflect_y() const{
        return {-x, y, -z};
    }
    point3 reflect_z() const{
        return {-x, -y, z};
    }
    point3 reflect_xy() const{
        return {x, y, -z};
    }
    point3 reflect_yz() const{
        return {-x, y, z};
    }
    point3 reflect_zx() const{
        return {x, -y, z};
    }
    point3 reflect(const point3 &o = {}) const{
        return {2 * o.x - x, 2 * o.y - y, 2 * o.z - z};
    }
    bool operator||(const point3 &otr) const{
        auto d = *this ^ otr;
        return abs(d.x) <= 1e-9 && abs(d.y) <= 1e-9 && abs(d.z) <= 1e-9;
    }
    long double operator()(int a) const{
        return x * a * a + y * a + z;
    }
};
template<class T> istream &operator>>(istream &in, point3<T> &p){
    return in >> p.x >> p.y >> p.z;
}
template<class T> ostream &operator<<(ostream &out, const point3<T> &p){
    return out << "{" << p.x << ", " << p.y << ", " << p.z << "}";
}
template<class T>
long double distance(const point3<T> &p, const point3<T> &q){
    return (p - q).norm();
}
template<class T>
T squared_distance(const point3<T> &p, const point3<T> &q){
    return (p - q).squared_norm();
}
template<class T>
long double doubled_signed_area(const point3<T> &p, const point3<T> &q, const point3<T> &r){
    return (q - p ^ r - p).norm();
}
template<class T>
long double angle(const point3<T> &p, const point3<T> &q){
    return atan2((p ^ q).norm(), p * q);
}

using point3int = point3<int>;
using point3ll = point3<long long>;
using point3lll = point3<__int128_t>;
using point3d = point3<double>;
using point3ld = point3<long double>;

struct disjoint_set_union{
    int par[N]; point3ld f[N];

    disjoint_set_union(){
        memset(par, -1, sizeof(par));
    }

    int root(int x){
        return par[x] < 0 ? x : (par[x] = root(par[x]));
    }

    void merge(int x, int y){
        if ((x = root(x)) == (y = root(y))){
            return;
        }
        if (par[x] > par[y]){
            swap(x, y);
        }
        par[x] += par[y];
        par[y] = x;
        f[x] += f[y];
    }
} dsu;

struct query_t{
    int h, idx;
    query_t(){ }
    query_t(int h, int idx): h(h), idx(idx){ }
};

int n, m, q;
point3ld a[N];
array <int, 3> tri[N];
query_t b[N];

vi contain[N];
point3ld ftri[N];
ld ans[N];

struct event_t{
    int h, type, idx;
    event_t(){ }
    event_t(int h, int type, int idx): h(h), type(type), idx(idx){ }
    bool operator <(const event_t &otr) const{ return tuple(h, type, -idx) < tuple(otr.h, otr.type, -otr.idx); }
};

vector <event_t> c;

point3ld cal_f(const array <int, 3> &tri, int h){
    if (a[tri[2]].z < h){
        return point3ld(0, 0, 0);
    }
    if (a[tri[0]].z >= h){
        ld S = abs(doubled_signed_area(a[tri[2]], a[tri[1]], a[tri[0]]));
        return point3ld(0, 0, S);
    }
    point3ld p = (point3ld)a[tri[2]] + (point3ld)(a[tri[0]] - a[tri[2]]) * (long double)(a[tri[2]].z - a[tri[1]].z) / (a[tri[2]].z - a[tri[0]].z);
    // cout << "P " << p << endl;
    // cout << (point3ld)(a[tri[0]] - a[tri[2]]) << endl;
    // cout << (long double)(a[tri[2]].z - a[tri[1]].z) / (a[tri[2]].z - a[tri[0]].z) << endl;
    // cout << (point3ld)(a[tri[0]] - a[tri[2]]) * (long double)(a[tri[2]].z - a[tri[1]].z) / (a[tri[2]].z - a[tri[0]].z) << endl;
    if (a[tri[1]].z < h){
        ld s = abs(doubled_signed_area((point3ld)a[tri[2]], (point3ld)a[tri[1]], p));
        // cout << "CASE 3 " << tri[0] << ' ' << tri[1] << ' ' << tri[2] << ' ' << h << ' ' << p << ' ' << s << endl;
        return point3ld(1, -2 * a[tri[2]].z, a[tri[2]].z * a[tri[2]].z) / ((a[tri[2]].z - a[tri[1]].z) * (a[tri[2]].z - a[tri[1]].z)) * s;
    }
    else{
        ld S = abs(doubled_signed_area(a[tri[2]], a[tri[1]], a[tri[0]]));
        ld s = abs(doubled_signed_area((point3ld)a[tri[1]], (point3ld)a[tri[0]], p));
        // cout << "CASE 4 " << tri[0] << ' ' << tri[1] << ' ' << tri[2] << ' ' << h << ' ' << p << ' ' << S << ' ' << s << endl;
        point3ld ans = point3ld(1, -2 * a[tri[0]].z, a[tri[0]].z * a[tri[0]].z) / ((a[tri[1]].z - a[tri[0]].z) * (a[tri[1]].z - a[tri[0]].z)) * (-s);
        ans.z += S;
        return ans;
    }
    assert(0);
    return point3ld(69, 69, 69);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    cin >> m;
    ForE(i, 1, m){
        cin >> tri[i][0] >> tri[i][1] >> tri[i][2];
    }
    cin >> q;
    ForE(i, 1, q){
        cin >> b[i].h >> b[i].idx;
    }

    ForE(i, 1, m){
        sort(bend(tri[i]), [&](int i, int j){ return a[i].z < a[j].z; });
    }
    ForE(i, 1, m){
        contain[tri[i][0]].emplace_back(i);
        contain[tri[i][1]].emplace_back(i);
        contain[tri[i][2]].emplace_back(i);
    }

    ForE(i, 1, n){
        c.emplace_back(a[i].z, 0, i);
    }
    ForE(i, 1, q){
        c.emplace_back(b[i].h, 1, i);
    }
    sort(bend(c)); reverse(bend(c));
    Fora(event, c){
        int h = event.h, i = event.idx;
        if (event.type == 0){
            Fora(j, contain[i]){
                dsu.f[dsu.root(i)] -= ftri[j];
                ftri[j] = cal_f(tri[j], h);
                // cout << "FTRI " << h << ' ' << i << ' ' << j << ' ' << ftri[j] << ' ' << ftri[j](4) << endl;
                dsu.f[dsu.root(i)] += ftri[j];
                if (a[tri[j][0]].z >= h and a[tri[j][1]].z >= h){
                    dsu.merge(tri[j][0], tri[j][1]);
                }
                if (a[tri[j][1]].z >= h and a[tri[j][2]].z >= h){
                    dsu.merge(tri[j][1], tri[j][2]);
                }
                if (a[tri[j][2]].z >= h and a[tri[j][0]].z >= h){
                    dsu.merge(tri[j][2], tri[j][0]);
                }
            }
            // cout << "COMPONENT " << dsu.f[dsu.root(i)] << endl;
        }
        else{
            int idx = b[i].idx;
            if (a[idx].z <= h){
                ans[i] = -1;
                continue;
            }
            // cout << "DSU" << endl;
            // ForE(i, 1, n){
            //     cout << dsu.par[i] << ' ' << dsu.f[i] << endl;
            // }
            ans[i] = dsu.f[dsu.root(idx)](h) / 2;
        }
    }
    cout << fixed << setprecision(15);
    ForE(i, 1, q){
        if (ans[i] <= -0.5){
            cout << "-1" << endl;
        }
        else{
            cout << abs(ans[i]) << endl;
        }
    }
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