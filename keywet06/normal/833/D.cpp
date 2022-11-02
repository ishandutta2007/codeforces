#include <bits/stdc++.h>

typedef long long int64;
typedef std::pair<int, int> Pair;
typedef std::vector<std::pair<Pair, int> > VPair;

const int P = 1000000007;
const int N = 100010;

VPair e[N];
int Ans, mi, rt;
int a[N * 3], b[N * 3], c[N * 3], d[N * 3], Size[N], s[N * 3];
bool v[N];

int Pow(int x, int y) {
    int t = 1;
    while (y) {
        if (y & 1) t = int64(t) * x % P;
        x = int64(x) * x % P;
        y >>= 1;
    }
    return t;
}

void getrt(int k, int n) {
    v[k] = Size[k] = 1;
    int ma = 0;
    for (VPair::iterator p = e[k].begin(); p != e[k].end(); ++p) {
        if (!v[p->first.first]) {
            getrt(p->first.first, n);
            Size[k] += Size[p->first.first];
            ma = std::max(ma, Size[p->first.first]);
        }
    }
    ma = std::max(ma, n - Size[k]);
    if (ma < mi) {
        mi = ma;
        rt = k;
    }
    v[k] = 0;
}

void dfs(int k, int t1, int t2) {
    a[t2] = int64(a[t2]) * t1 % P, ++c[t2], v[k] = Size[k] = 1;
    for (VPair::iterator p = e[k].begin(); p != e[k].end(); ++p) {
        if (!v[p->first.first]) {
            dfs(p->first.first, int64(t1) * p->first.second % P, t2 + p->second);
            Size[k] += Size[p->first.first];
        }
    }
    v[k] = 0;
}

void divide(int k, int n) {
    mi = n, getrt(k, n), k = rt, v[k] = 1;
    for (int i = 0; i <= 3 * n; ++i) a[i] = b[i] = 1, c[i] = d[i] = 0;
    for (VPair::iterator p = e[k].begin(); p != e[k].end(); ++p) {
        if (!v[p->first.first]) {
            dfs(p->first.first, p->first.second, n + p->second);
            int l = n - Size[p->first.first], r = n + 2 * Size[p->first.first];
            s[l - 1] = 0;
            for (int i = l; i <= r; ++i) s[i] = s[i - 1] + c[i];
            for (int i = l; i <= r; ++i) b[i] = int64(b[i]) * a[i] % P, d[i] += c[i];
            for (int i = l; i <= r; ++i) {
                int t = std::max(l - 1, 2 * n - 1 - i);
                Ans = int64(Ans) * Pow(a[i], s[t]) % P;
            }
            for (int i = l; i <= r; ++i) a[i] = 1, c[i] = 0;
        }
    }
    ++d[n];
    int l = 1, r = n * 3;
    s[l - 1] = 0;
    for (int i = l; i <= r; ++i) s[i] = s[i - 1] + d[i];
    for (int i = l; i <= r; ++i) {
        int t = std::max(l - 1, 2 * n - 1 - i);
        Ans = int64(Ans) * Pow(b[i], P - 1 - s[t]) % P;
    }
    for (VPair::iterator p = e[k].begin(); p != e[k].end(); ++p) {
        if (!v[p->first.first]) divide(p->first.first, Size[p->first.first]);
    }
}

void calc(int k, int n) {
    v[k] = Size[k] = 1;
    for (VPair::iterator p = e[k].begin(); p != e[k].end(); ++p) {
        if (!v[p->first.first]) {
            calc(p->first.first, n);
            Size[k] += Size[p->first.first];
            Ans = int64(Ans) *
                  Pow(p->first.second, int64(Size[p->first.first]) * (n - Size[p->first.first]) % (P - 1)) % P;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int x, y, z, c;
        std::cin >> x >> y >> z >> c;
        c = c == 0 ? -1 : 2;
        e[x].push_back(std::make_pair(std::make_pair(y, z), c));
        e[y].push_back(std::make_pair(std::make_pair(x, z), c));
    }
    Ans = 1;
    divide(1, n);
    for (int i = 1; i <= n; ++i) {
        for (VPair::iterator p = e[i].begin(); p != e[i].end(); ++p) p->second = 1 - p->second;
    }
    memset(v, 0, sizeof(v));
    divide(1, n);
    memset(v, 0, sizeof(v));
    calc(1, n);
    printf("%d\n", Ans);
    return 0;
}