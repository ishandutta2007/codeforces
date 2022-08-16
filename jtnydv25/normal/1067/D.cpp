#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
// #define double long double
// #define int long long

struct Line {
    double a, b, get(double x) { return a * x + b; }
};
const double EPS = 1e-9;
bool double_eq(double a, double b){
    return fabs(a - b) <= EPS;
}
struct ConvexHull {
    int size;
    Line *hull;
    double alpha, beta, gamma;
    ConvexHull() {
        hull = new Line[100005], size = 0;
    }

    bool is_bad(int curr, int prev, int next) {
        Line c = hull[curr], p = hull[prev], n = hull[next];
        return (c.b - n.b) * (c.a - p.a) <= (p.b - c.b) * (n.a - c.a);
    }

    void add_line(double a, double b) {
        hull[size++] = (Line){a, b};
        while (size > 2 && is_bad(size - 2, size - 3, size - 1))
            hull[size - 2] = hull[size - 1], size--;
    }

    double query(double x) {
        int l = -1, r = size - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (hull[m].get(x) <= hull[m + 1].get(x))
                l = m;
            else
                r = m;
        }
        return hull[r].get(x);
    }

    double get(double x, ll t){
        return (x - gamma) * pow(alpha, t) + gamma;
    }

    double query2(long long t, double m){
        int ind = 0;
        double x = 0;
        ll iter = 0;
        while(ind < size && iter < t){
            alpha = 1 - hull[ind].a;
            beta = m - hull[ind].b;
            gamma = beta / (1 - alpha);
            if(ind == size - 1){
                return get(x, t - iter);
            }
            if(hull[ind].get(x) < hull[ind+1].get(x)){
                ind++;
                continue;
            }
            ll lo = 0, hi = t - iter - 1;

            while(lo < hi){
                ll mid = (lo + hi + 1) >> 1;
                double val = get(x, mid);
                if(hull[ind].get(val) >=  hull[ind + 1].get(val)) lo = mid;
                else hi = mid - 1;
            }
            lo++;
            x = get(x, lo);
            iter += lo;
            ind++;
        }
        assert(iter == t);
        return x;
    }
} ch;

const int N = 100005;
int a[N], b[N];
double p[N];
double k[N];



int perm[N];
main(){
    int n; 
    ll t;
    scanf("%d %lld", &n, &t);
    double m = 0;
    double m1 = 0;
    for(int i = 1; i <= n;i++){
        scanf("%d %d", a+i, b+i);
        scanf("%lf", &p[i]);
        m = max(p[i] * b[i], m);
        m1 = max(p[i] * a[i], m1);
        k[i] = a[i] * p[i];
        perm[i] = i;
    }

    sort(perm + 1, perm + n + 1, [](int i, int j){return p[i] < p[j];});

    for(int i = 1; i <= n; i++) ch.add_line(p[perm[i]], k[perm[i]]);
    if(double_eq(m, m1)){
        printf("%.15lf\n", t * m);
        return 0;
    }
    
    printf("%.15lf\n", m * t - ch.query2(t, m));
}