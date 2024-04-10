#include <bits/stdc++.h>

using namespace std;

#define FOR(i, l, r) for (ll (i) = (l); (i) < (r); ++(i))
#define FORD(i, l, r) for (ll (i) = (l); (i) > (r); --(i))
#define True true
#define False false
#define S second
#define F first
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
#define eps 1e-9
#define COUT 20
#define db(x) cerr << endl <<#x << " = " << x << endl
#define sqr(x) (x) * (x)
#define sqrt(x) pow((x), 0.5)
#define START_() ios::sync_with_stdio(0); cin.tie(0); cout.precision(COUT);

#define x0 pelfpskfo
#define y0 issgksknkdns
#define x1 kjwoieill
#define y1 poposkdlkd

typedef long long ll;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ld pi = acos(-1.0);

ll gcd (ll n1, ll n2) {return ((n2) == 0) ? (n1) : gcd ((n2), (n1) % (n2));}
ll lcm (ll n1, ll n2) {return n1 * n2 / gcd(n1, n2);}

class tree{
    public:
        ll n;
        ll tree_[40005];
        void build (ll a[], ll v, ll tl, ll tr) {
            if (tl == tr)
                tree_[v] = a[tl];
            else {
                ll tm = (tl + tr) / 2;
                build (a, v*2, tl, tm);
                build (a, v*2+1, tm+1, tr);
                tree_[v] = tree_[v*2] + tree_[v*2+1];
            }
        }
        ll sum (ll v, ll tl, ll tr, ll l, ll r) {
            if (l > r)
                return 0;
            if (l == tl && r == tr)
                return tree_[v];
            ll tm = (tl + tr) / 2;
            return sum (v*2, tl, tm, l, min(r,tm))
                + sum (v*2+1, tm+1, tr, max(l,tm+1), r);
        }
        void update (ll v, ll tl, ll tr, ll l, ll r, ll add) {
            if (l > r)
                return;
            if (l == tl && tr == r)
                tree_[v] += add;
            else {
                ll tm = (tl + tr) / 2;
                update (v*2, tl, tm, l, min(r,tm), add);
                update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
            }
        }
};

class point{
public:
    ld x, y;
    point()
    {
        x = 0;
        y = 0;
    }
    point(ld a, ld b)
    {
        x = a;
        y = b;
    }
    bool operator==(const point &p) const
    {
        return (fabs(x - p.x) < eps && fabs(y - p.y) < eps);
    }
    void read()
    {
        cin >> x >> y;
    }

    void write()
    {
        cout.precision(COUT);
        cout << x << " " << y << " ";
    }
};

class vect{
public:
    ld x, y;
    ld dist() const{
        return sqrt(sqr(x) + sqr(y));
    }
    vect one() const{
        vect result(x / sqrt(sqr(x) + sqr(y)), y / sqrt(sqr(x) + sqr(y)));
        return result;
    }
    vect contr()
    {
        vect v;
        v.x = -y;
        v.y = x;
        return v;
    }
    void read()
    {
        cin >> x >> y;
    }
    void write()
    {
        cout.precision(COUT);
        cout << x << " " << y << " ";
    }
    vect(point a, point b){
        x = b.x - a.x;
        y = b.y - a.y;
    }
    vect(point a){
        x = a.x;
        y = a.y;
    }
    vect(ld a, ld b){
        x = a;
        y = b;
    }
    vect(ld a1, ld b1, ld a2, ld b2){
        x = a2 - a1;
        y = b2 - b1;
    }
    vect(){
        x = 0;
        y = 0;
    }
    vect(const vect& orig){
        x = orig.x;
        y = orig.y;
    }
    ld operator*(const vect &sec) const{
        ld result = (x * sec.x + y * sec.y);
        return result;
    }
    vect operator*(const ld &sec) const{
        vect result(x * sec, y * sec);
        return result;
    }
    ld operator^(const vect &sec) const{
        ld result = (x * sec.y - y * sec.x);
        return result;
    }
    vect operator+(const vect &sec) const{
        vect result(x + sec.y, y + sec.x);
        return result;
    }
    bool operator==(const vect &p) const
    {
        return (fabs(x - p.x) < eps && fabs(y - p.y) < eps);
    }
    bool operator/(const vect &sec) const{
        bool result = (x * sec.y == y * sec.x);
        return result;
    }
    vect& operator= (const vect &orig){
        x = orig.x;
        y = orig.y;
    }
    ld operator& (const vect &sec){
        return fabs(atan2((x * sec.x + y * sec.y),(x * sec.y - y * sec.x)));
    }
};
point operator+(point const & p, vect const & v)
{
	point result(p.x + v.x, p.y + v.y);
    return result;
}

struct line
{
    ld a, b, c;

    line()
    {
        a = b = c = 0;
    }

    line(point p, vect v)
    {
        a = -v.y;
        b = v.x;
        c = v.y * p.x - v.x * p.y;
    }

    line(point p, point p2)
    {
        vect v(p, p2);
        a = -v.y;
        b = v.x;
        c = v.y * p.x - v.x * p.y;
    }

    line(ld x, ld y, ld z)
    {
        a = x;
        b = y;
        c = z;
    }

    bool operator==(const line &l) const
    {
        return (fabs(a - l.a) < eps && fabs(b - l.b) < eps && fabs(c - l.c) < eps);
    }
    ll operator&(const line &l2) const
    {
        ld d = a * l2.b - b * l2.a;
        ld dx = -c * l2.b + l2.c * b;
        ld dy = -a * l2.c + l2.a * c;
        if (fabs(d) < eps && fabs(dx) < eps && fabs(dy) < eps)
            return 2;
        if (fabs(d) < eps)
            return 0;
        return 1;
    }
    point operator/(const line &l2) const
    {
        ld d = a * l2.b - b * l2.a;
        ld dx = -c * l2.b + l2.c * b;
        ld dy = -a * l2.c + l2.a * c;
        return point(dx / d, dy / d);
    }
    vect napr()
    {
        vect v;
        v.x = -b;
        v.y = a;
        return v;
    }

    vect norm()
    {
        vect v;
        v.x = a;
        v.y = b;
        return v;
    }

    bool is(point p)
    {
        return (fabs(a * p.x + b * p.y + c) < eps);
    }

    ld height(point p)
    {
        return fabs(p.x * a + p.y * b + c) / sqrt(a * a + b * b);
    }

    ld f(point p)
    {
        return (a * p.x + b * p.y + c);
    }

    void read()
    {
        cin >> a >> b >> c;
    }

    void write()
    {
        cout.precision(COUT);
        cout << a << " " << b << " " << c << " ";
    }

    point rand_point()
    {
        point p;
        p.x = -(c * a) / (a * a + b * b);
        p.y = -(c * b) / (a * a + b * b);
        return p;
    }
    line operator+(const vect &v)
    {
        line ans;
        ans.a = a;
        ans.b = b;
        ans.c = c + a * v.x + b * v.y;
        return ans;
    }
};

line centr_perp(point p1, point p2)
{
    vect v = vect(p1, p2);
    v = vect(v.y, -v.x);
    point m = point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
    return line(m, v);
}

line biss(point a, point b, point c)
{
    vect v1 = vect(b, a);
    vect v2 = vect(b, c);
    v1 = v1.one();
    v2 = v2.one();
    vect v = v1 + v2;
    return line(b, v);
}

point perp(point p, line l)
{
    ld r = l.height(p);
    vect v = l.norm();
    v = v.one() * r;
    vect mv = v * -1;
    point t = p + v;
    if (l.is(p + v))
        return p + v;
    return p + mv;
}

point simm(point p, line l)
{
    point g = perp(p, l);
    vect v = vect(p, g);
    return g + v;
}


#define read_default() ll n; cin >> n; string a[n]; FOR(i, 0, n) getline(a[n]);
#define FILENAME "length"
main()
{
    //START_();
    /*
    freopen(FILENAME".in", "r", stdin);
    freopen(FILENAME".out", "w", stdout);
    /**/
    //read_default();
    ll n;
    cin >> n;
    string a[n];
    FOR(i, 0, n)
        cin >> a[i];
    ll ans = 7;
    FOR(i, 0, n)
        FOR(j, 0, n){
            if (i == j)
                continue;
            ll different = 0;
            FOR(lol, 0, 6)
                if (a[i][lol] != a[j][lol])
                    different++;
            ans = min(ans, (different + 1) / 2);
        }
    cout << ans - 1;
}