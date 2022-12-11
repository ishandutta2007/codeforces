/*
  
 | _ _|
  ` _x 
   /  |
  /   ?
 | |||
 | (__)_)
 
  */

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
    static short st[30];short tp=0;
    if(x<0) putchar('-'),x=-x;
    do st[++tp]=x%10,x/=10; while(x);
    while(tp) putchar('0'|st[tp--]);
    putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

%:include <cmath>
%:define db long double
const int N = 200050;
pair<db, int> s[N];
int d[N], vis[N], cnt, n, m; 
db k[N], b[N];
inline void Add(int x, int c = 1) { for (; x <= cnt; x += x & -x) d[x] += c; }
inline int Sum(int x) { int res = 0; for (; x; x-= x & -x) res += d[x]; return res; }
inline db Y(db x, int t) { return k[t] * x + b[t]; }
inline void get(db a, db b, db c, db nm) {
    a = a * 2;
    db delta = b * b - 2 * a * c;
    if (delta < 0) return;
    delta = sqrt(delta);
    db x1 = (-b + delta) / a, x2 = (-b - delta) / a;
    s[++cnt] = MP(atan2(Y(x1, nm), x1), nm);
    s[++cnt] = MP(atan2(Y(x2, nm), x2), nm);
}

bool check(db md) {
    cnt = 0;
    for (int i = 1;i <= n; i++) 
        get(k[i] * k[i] + 1, 2 * k[i] * b[i], b[i] * b[i] - md * md, i);
    sort(s + 1, s + cnt + 1);
    ll ans = 0;
    /* for (int i = cnt;i >= 1; i--) { */
    for (int i = 1;i <= cnt; i++) {
        if (!vis[s[i].se]) { vis[s[i].se] = i; continue; }
        else {
            ans += Sum(i) - Sum(vis[s[i].se]), Add(i), Add(vis[s[i].se], -1);
            /* ans += Sum(vis[s[i].se]) - Sum(i - 1), Add(vis[s[i].se]); */
        }
    }
    for (int i = 1;i <= 2 * n; i++) vis[i] = d[i] = 0;
    return ans >= m;
}

inline db Dis(int x, int y) {
    db xx = (b[y]-b[x]) / (k[x]-k[y]);
    db yy = k[x] * xx + b[x];
    return sqrt(xx * xx + yy * yy);
}
int L[N], R[N];
inline void del(int x) { R[L[x]] = R[x], L[R[x]] = L[x]; }
bool equal(db x, db y) { 
    return fabs(x - y) <= 1e-7;
}

db getans(db md) {
    check(md);
    for (int i = 1;i <= cnt; i++) L[i] = i - 1, R[i] = i + 1, vis[i] = 0;
    db ans = 0; int nd = m;
    for (int i = 1;i <= cnt; i++) {
        if (!vis[s[i].se]) { vis[s[i].se] = i; continue; }
        int pre = vis[s[i].se];
        for (int j = L[i];j > pre; j = L[j]) {
            ans += Dis(s[i].se, s[j].se), nd--;
            if (!nd) return ans;
        }
        del(i), del(pre);
    }
    return ans + nd * md;
}

inline void Print(db x, char ed = '\n') { 
    printf("%.10Lf%c", x, ed);
}

#include <iomanip>
int main() {
    int x, y; read(n), read(x), read(y), read(m); 
    db tx = x / 1000.0, ty = y / 1000.0;
    for (int i = 1, t1, t2;i <= n; i++) {
        read(t1), read(t2), k[i] = t1 / 1000.0;
        b[i] = t2 / 1000.0 + k[i] * tx - ty;
        /* Print(b[i], ' '), Print(k[i]); */
    }
    db l = 0, r = 1e10;
    for (int i = 1;i <= 120; i++) {
        db mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    /* printf ("%.10Lf\n", l); */
    /* printf ("%.10Lf\n", getans(l)); */
    cout << fixed << setprecision(10) << getans(l) << endl;
    return 0;
}