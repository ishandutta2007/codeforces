#include <bits/stdc++.h>

using namespace std;

const int N = 20005, K = 105, SZ = 32768;

using ldou = long double;

struct Seg {
    struct Cht {
        struct Lin {
            int a, b;
        };
        vector<Lin> v;
        int c;
        int val(Lin p, Lin q, Lin r) {
            ldou pq = ldou(p.b - q.b) / (q.a - p.a);
            ldou pr = ldou(p.b - r.b) / (r.a - p.a);
            return pq < pr;
        }
        void u(int a, int b) {
            Lin t = {a, b};
            while (c > 1 && !val(v[c - 2], v[c - 1], t)) {
                c--;
                v.pop_back();
            }
            v.push_back(t);
            c++;
        }
        int f(int x, int i) { return v[x].a * i + v[x].b; }
        int g(int i) {
            if (!c) return int(1e9);
            while (c > 1 && f(c - 1, i) > f(c - 2, i)) {
                c--;
                v.pop_back();
            }
            return f(c - 1, i);
        }
    } d[2 * SZ];
    void cl() {
        for (int i = 1; i < 2 * SZ; ++i) {
            d[i].v.clear();
            d[i].c = 0;
        }
    }
    void u(int x, int a, int b) {
        for (x += SZ; x; x >>= 1) d[x].u(a, b);
    }
    void u(int x, int y, int a, int b) {
        for (x += SZ, y += SZ; x <= y; x >>= 1, y >>= 1) {
            if (x & 1) d[x++].u(a, b);
            if (~y & 1) d[y--].u(a, b);
        }
    }
    int g(int x, int i) {
        int r = int(1e9);
        for (x += SZ; x; x >>= 1) r = min(r, d[x].g(i));
        return r;
    }
    int g(int x, int y, int i) {
        int r = int(1e9);
        for (x += SZ, y += SZ; x <= y; x >>= 1, y >>= 1) {
            if (x & 1) r = min(r, d[x++].g(i));
            if (~y & 1) r = min(r, d[y--].g(i));
        }
        return r;
    }
} S, T;

struct Qry {
    int s, e, x, us, ue;
};

int n, k, a[N], d[K][N];
stack<int> st;
vector<Qry> v;

int main() {
    scanf("%d %d", &n, &k);
    st.push(0);
    for (int i = 1, mx = 0; i <= n; ++i) {
        scanf("%d", a + i);
        mx = max(mx, a[i]);
        d[1][i] = mx * i;
        while (st.top() && a[st.top()] <= a[i]) {
            v[st.top() - 1].ue = i - 1;
            st.pop();
        }
        v.push_back({st.top() + 1, i, a[i], i, 0});
        st.push(i);
    }
    for (auto &i : v)
        if (!i.ue) i.ue = n;
    sort(v.begin(), v.end(), [](Qry p, Qry q) { return p.x > q.x; });
    for (int t = 2; t <= k; ++t) {
        S.cl();
        T.cl();
        for (int i = 1; i <= n; ++i) S.u(i, -i, d[t - 1][i - 1]);
        for (auto &i : v) {
            int c = S.g(i.s, i.e, i.x) + (i.e + 1) * i.x;
            T.u(i.us, i.ue, i.x, c - i.us * i.x);
        }
        for (int i = n; i >= 1; --i) d[t][i] = T.g(i, i);
    }
    printf("%d\n", d[k][n]);
    return 0;
}