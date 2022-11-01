#include <bits/stdc++.h>
#define maxn 2086
using namespace std;

typedef long long ll;

struct Frac{
    ll x, y;
    void norm(){
        ll d = __gcd(x, y);
        x /= d; y /= d;
        if(y < 0) {
            x = -x;
            y = -y;
        }
    }
    Frac(ll xx, ll yy){
        x = xx, y = yy;
        norm();
    }
    inline bool operator < (const Frac &k) const {
        return x * k.y < k.x * y;
    }
    inline bool operator <= (const Frac &k) const {
        return x * k.y <= k.x * y;
    }
};

struct Line {
    mutable double k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(double x) const { return p < x; }
};

struct LineContainer : std::multiset<Line, std::less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const double inf = 1/.0;
    double div(double a, double b) { return a / b; }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(double k, double m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    double query(double x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
}u, d;

int n;
int xl[maxn], xr[maxn], y[maxn];
vector<pair<Frac, int> > v;
vector<Frac> a;

int main(){
    scanf("%d", &n);
    for(int i = 1;i <= n;i++) scanf("%d%d%d", &xl[i], &xr[i], &y[i]);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(y[i] >= y[j]) continue;
            Frac a(xl[i] - xr[j], y[j] - y[i]), b(xr[i] - xl[j], y[j] - y[i]);
            if(b < a) swap(a, b);
            v.emplace_back(a, 1), v.emplace_back(b, -1);
        }
    }
    if(v.empty()){
        int mn = 1e6, mx = -1e6;
        for(int i = 1;i <= n;i++) mn = min(mn, xl[i]), mx = max(mx, xr[i]);
        printf("%d", mx - mn);
        return 0;
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for(int i = 0;i < v.size();i++){
        //printf("%lf %d--\n", 1.0 * v[i].first.x / v[i].first.y, v[i].second);
        if(!sum) a.push_back(v[i].first);
        sum += v[i].second;
        if(!sum) a.push_back(v[i].first);
    }
    for(int i = 1;i <= n;i++){
        u.add(y[i], xl[i]), d.add(-y[i], -xl[i]);
        u.add(y[i], xr[i]), d.add(-y[i], -xr[i]);
    }
    double ans = 1e100;
    for(int i = 0;i < a.size();i++){
        //printf("%lf--\n", 1.0 * a[i].x / a[i].y);
        ans = min(ans, u.query(1.0 * a[i].x / a[i].y) + d.query(1.0 * a[i].x / a[i].y));
    }
    printf("%.10lf", ans);
}