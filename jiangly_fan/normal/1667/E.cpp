#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
constexpr LL g = 3;
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
vector<int> r;
struct Poly : vector<LL>{
    Poly(){}
    Poly(int n) : vector<LL>(n){}
    Poly(const initializer_list<LL>& list) : vector<LL>(list){}
    void dft(int n, bool inverse = false){
        if((int)r.size() != n){
            r.resize(n);
            r[1] = n >> 1;
            for(int i = 2; i < n; i += 1) r[i] = r[i >> 1] >> 1 | (i & 1 ? n >> 1 : 0);
        }
        resize(n);
        for(int i = 0; i < n; i += 1) if(i < r[i]) std::swap(at(i), at(r[i]));
        for(int d = 0; (1 << d) < n; d += 1){
            int m = 1 << d, m2 = m << 1;
            LL _w = power(inverse ? power(g, mod - 2) : g, (mod - 1) / m2);
            for(int i = 0; i < n; i += m2)
                for(int w = 1, j = 0; j < m; j += 1, w = w * _w % mod){
                    LL& x = at(i + j + m), &y = at(i + j), t = w * x % mod;
                    x = y - t;
                    if(x < 0) x += mod;
                    y += t;
                    if(y >= mod) y -= mod;
                }
        }
        if(inverse) for(int i = 0, inv = power(n, mod - 2); i < n; i += 1) at(i) = at(i) * inv % mod;
    }
    Poly operator * (const Poly& p)const{
        auto a = *this, b = p;
        int k = 1, n = size() + p.size() - 1;
        while(k < n) k <<= 1;
        a.dft(k);
        b.dft(k);
        for(int i = 0; i < k; i += 1) a[i] = a[i] * b[i] % mod;
        a.dft(k, true);
        a.resize(n);
        return a;
    }
    Poly inverse()const{
        Poly a = {power(at(0), mod - 2)};
        for(int n = 1; n < (int)size(); n <<= 1){
            int k = n << 2;
            auto b = *this, c = a;
            for(int i = n << 1; i < (int)b.size(); i += 1) b[i] = 0;
            b.dft(k);
            c.dft(k);
            for(int i = 0; i < k; i += 1) b[i] = b[i] * c[i] % mod * c[i] % mod;
            b.dft(k, true);
            a.resize(n << 1);
            for(int i = 0; i < (n << 1); i += 1) a[i] = (2 * a[i] + mod - b[i]) % mod;
        }
        a.resize(size());
        return a;
    }
    pair<Poly, Poly> operator / (const Poly& p){
        int n = size() - p.size() + 1;
        auto a = *this, b = p;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        a.resize(n);
        b.resize(n);
        auto q = a * b.inverse();
        q.resize(n);
        reverse(q.begin(), q.end());
        auto r = p * q;
        r.resize(p.size() - 1);
        for(int i = 0; i + 1 < (int)p.size(); i += 1){
            r[i] = at(i) - r[i];
            if(r[i] < 0) r[i] += mod;
        }
        return {q, r};
    }
    Poly log()const{
        int n = size();
        Poly a(n - 1);
        for(int i = 0; i + 1 < n; i += 1) a[i] = at(i + 1) * (i + 1) % mod;
        a = a * inverse();
        a.resize(n);
        for(int i = n - 1; i >= 0; i -= 1) a[i] = i ? a[i - 1] * power(i, mod - 2) % mod : 0;
        return a;
    }
    Poly exp()const{
        Poly a = {1};
        for(int n = 1; n < (int)size(); n <<= 1){
            int k = n << 2;
            auto b = a.log();
            b.resize(k);
            for(int i = 0; i < k; i += 1)
                b[i] = ((i < (int)size() ? at(i) : 0) + not i + mod - b[i]) % mod;
            a = a * b;
            a.resize(k);
        }
        a.resize(size());
        return a;
    }
    Poly mulT(const Poly& p)const{
        auto a = *this;
        reverse(a.begin(), a.end());
        a = a * p;
        a.resize(size());
        reverse(a.begin(), a.end());
        return a;
    }
#define tm ((tl + tr) >> 1)
#define ls (v << 1)
#define rs (ls | 1)
    Poly eval(const Poly& x)const{
        vector<Poly> Q(x.size() << 2), P(x.size() << 2);
        Poly y(x.size());
        function<void(int, int, int)> dfs1 = [&](int v, int tl, int tr){
            if(tl == tr){
                Q[v].push_back(1);
                Q[v].push_back((mod - x[tm]) % mod);
                return;
            }
            dfs1(ls, tl, tm);
            dfs1(rs, tm + 1, tr);
            Q[v] = Q[ls] * Q[rs];
        };
        function<void(int, int, int)> dfs2 = [&](int v, int tl, int tr){
            if(tl == tr){
                y[tm] = P[v][0];
                return;
            }
            P[v].resize(tr - tl + 1);
            P[ls] = P[v].mulT(Q[rs]);
            P[rs] = P[v].mulT(Q[ls]);
            dfs2(ls, tl, tm);
            dfs2(rs, tm + 1, tr);
        };
        dfs1(1, 0, x.size() - 1);
        Q[1].resize(max(size(), x.size()));
        P[1] = mulT(Q[1].inverse());
        dfs2(1, 0, x.size() - 1);
        return y;
    }
    friend Poly inter(const Poly& x, const Poly& y) {
        vector<Poly> Q(x.size() << 2), P(x.size() << 2);
        function<void(int, int, int)> dfs1 = [&](int v, int tl, int tr){
            if(tl == tr){
                Q[v].push_back((mod - x[tm]) % mod);
                Q[v].push_back(1);
                return;
            }
            dfs1(ls, tl, tm);
            dfs1(rs, tm + 1, tr);
            Q[v] = Q[ls] * Q[rs];
        };
        dfs1(1, 0, x.size() - 1);
        Poly f((int)Q[1].size() - 1);
        for (int i = 0; i + 1 < Q[1].size(); i += 1) f[i] = (Q[1][i + 1] * (i + 1)) % mod;
        Poly g = f.eval(x);
        function<void(int, int, int)> dfs2 = [&](int v, int tl, int tr){
            if(tl == tr){
                P[v].push_back(y[tm] * power(g[tm], mod - 2) % mod);
                return;
            }
            dfs2(ls, tl, tm);
            dfs2(rs, tm + 1, tr);
            P[v].resize(tr - tl + 1);
            Poly A = P[ls] * Q[rs];
            Poly B = P[rs] * Q[ls];
            for (int i = 0; i <= tr - tl; i += 1) P[v][i] = (A[i] + B[i]) % mod;
        };
        dfs2(1, 0, x.size() - 1);
        return P[1];
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<LL> f(n + 1), g(n + 1);
    for (int i = 0; i <= n; i += 1)
        g[i] = power(f[i] = i ? f[i - 1] * i % mod : 1, mod - 2);
    vector<LL> h(n + 1), z(n + 1);
    Poly a(n * 2 + 1), b(n * 2 + 1);
    for (int i = 2; i <= n / 2 + 1; i += 1)
        a[i] = f[i - 2];
    for (int i = 0; i <= n; i += 1)
        b[i] = g[n - i];
    auto c = a * b;
    for (int i = 2; i <= n / 2 + 1; i += 1) {
        if(0) for (int j = 0; i + j <= n / 2 + 1; j += 1) {
            LL x = g[j] % mod * f[i + j - 2];
            h[i] = (h[i] + x) % mod;
        }
        h[i] = c[n + i];
        h[i] = h[i] * (i - 1) % mod * f[n - i] % mod;
    }
    h[1] = f[n - 1];
    //for (int i = 1; i <= n; i += 1) cout << h[i] << " "; cout << '\n';
    for (int i = n, s = 0; i >= 1; i -= 1) {
        z[i] = (h[i] + mod - s) % mod;
        s = (s + h[i] * power(i - 1, mod - 2)) % mod;
    }
    for (int i = 1; i <= n; i += 1) cout << z[i] << " "; cout << '\n';
}