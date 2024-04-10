#include <bits/stdc++.h>
using namespace std;

class FFT {
public:
    FFT(int max_degree) {
        int lg = get_lg(max_degree + 1);
        reverse.resize(lg + 1);

        int size = 1 << lg;
        const double PI = acos(-1);
        ws.resize(lg);
        ws[lg-1].resize(size >> 1);
        for (int i = 0; i < (size >> 1); i++) {
            double ang = 2 * PI * i / size;
            ws[lg-1][i] = {cos(ang), sin(ang)};
        }
        for (int j = lg - 2; j >= 0; j--) {
            int sz_level = ws[j+1].size() >> 1;
            ws[j].resize(sz_level);
            for (int i = 0; i < sz_level; i++)
                ws[j][i] = ws[j+1][i<<1];
        }
    }

    int get_lg(int x) {
        return x ? 32 - __builtin_clz(x - 1) : 0;
    }

    void precompute_reverse(int lg) {
        int size = 1 << lg;
        reverse[lg].assign(size, 0);
        for (int i = 1, j = 0; i < size; i++) {
            int bit = size >> 1;
            for (; j & bit; bit >>= 1)
                j ^= bit;
            j ^= bit;
            reverse[lg][i] = j;
        }
    }

    using cd = std::complex<double>;
    using vcd = std::vector<cd>;

    void fft(vcd & a, bool inv) {
        int lg = get_lg(a.size());
        if (reverse[lg].empty())
            precompute_reverse(lg);
        int size = 1 << lg;

        auto& rev = reverse[lg];
        for (int i = 0; i < size; i++) {
            if (i < rev[i])
                swap(a[i], a[rev[i]]);
        }

        for (int k = 0; k < lg; k++) {
            int len = 1 << k;
            auto& w = ws[k];
            for (int i = 0; i < size; i += 2*len) {
                for (int j = 0; j < len; j++) {
                    cd u = a[i+j], v = a[i+j+len] * w[j];
                    a[i+j] = u + v;
                    a[i+j+len] = u - v;
                }
            }
        }

        if (inv) {
            for (cd & x : a)
                x /= size;
            std::reverse(a.begin() + 1, a.end());
        }
    }

    template <typename T>
    std::vector<long long> multiply_brute_force(std::vector<T> const& a, std::vector<T> const& b, int sz) {
        std::vector<long long> result(sz);
        for (int i = 0; i < (int)a.size(); i++) {
            for (int j = 0; j < (int)b.size(); j++) {
                result[i + j] += a[i] * b[j];
            }
        }
        return result;
    }

    template <typename T>
    std::vector<long long> multiply(std::vector<T> const& a, std::vector<T> const& b) {
        int result_size = a.size() + b.size() - 1;
        if (result_size <= 200)
            return multiply_brute_force(a, b, result_size);

        vcd fa(a.begin(), a.end()), fb(b.begin(), b.end());
        int size = 1 << get_lg(result_size);
        fa.resize(size);
        fb.resize(size);

        fft(fa, false);
        fft(fb, false);
        for (int i = 0; i < size; i++)
            fa[i] *= fb[i];
        fft(fa, true);

        std::vector<long long> result(result_size);
        for (int i = 0; i < result_size; i++)
            result[i] = std::llround(fa[i].real());
        return result;
    }

    std::vector<int> multiply_mod(std::vector<int> const& a, std::vector<int> const& b, int const mod) {
        int result_size = a.size() + b.size() - 1;
        int size = 1 << get_lg(result_size);

        vcd v1(size), v2(size);
        for (int i = 0; i < (int)a.size(); i++)
            v1[i] = cd(a[i] >> 15, a[i] & 32767);
        for (int i = 0; i < (int)b.size(); i++)
            v2[i] = cd(b[i] >> 15, b[i] & 32767);
        fft(v1, false);
        fft(v2, false);

        vcd r1(size), r2(size);
        for (int i = 0; i < size; i++) {
            int j = i ? size - i : i;
            cd ans1 = (v1[i] + conj(v1[j])) * cd(0.5, 0);
            cd ans2 = (v1[i] - conj(v1[j])) * cd(0, -0.5);
            cd ans3 = (v2[i] + conj(v2[j])) * cd(0.5, 0);
            cd ans4 = (v2[i] - conj(v2[j])) * cd(0, -0.5);
            r1[i] = ans1*ans3 + ans1*ans4*cd(0,1);
            r2[i] = ans2*ans3 + ans2*ans4*cd(0,1);
        }
        fft(r1, true);
        fft(r2, true);

        std::vector<int> result(result_size);
        for (int i = 0; i < result_size; i++) {
            long long ans1 = std::llround(r1[i].real()) % mod;
            long long ans2 = std::llround(r1[i].imag() + r2[i].real()) % mod;
            long long ans3 = std::llround(r2[i].imag()) % mod;
            result[i] = ((ans1 << 30) + (ans2 << 15) + ans3) % mod;
        }
        return result;
    }

private:
    std::vector<std::vector<int>> reverse;
    std::vector<vcd> ws;
};

class UnionFind
{
public:
    UnionFind(int n)
    {
        p.resize(n);
        std::iota(p.begin(), p.end(), 0);
        rank.assign(n, 0);
    }

    int Find(int x) { return x == p[x] ? x : p[x] = Find(p[x]); }

    void Union(int x, int y)
    {
        int xRoot = Find(x);
        int yRoot = Find(y);

        if (xRoot == yRoot)
            return;

        if (rank[xRoot] < rank[yRoot]) {
            p[xRoot] = yRoot;
        } else if (rank[xRoot] > rank[yRoot]) {
            p[yRoot] = xRoot;
        } else {
            p[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }

    bool sameUnion(int x, int y) { return Find(x) == Find(y); }

private:
    std::vector<int> p, rank;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;
    reverse(t.begin(), t.end());
    
    int n = s.size() - t.size() + 1;
    vector<UnionFind> ufs(n, 26);
    FFT fft(250'000);
    int size = 1 << 18;
    
    using cd = complex<double>;
    using vcd = vector<cd>;
    vector<vcd> Ss(6);
    for (char c = 'a'; c <= 'f'; c++) {
        vcd S(s.size());
        for (int i = 0; i < (int)s.size(); i++) {
            S[i] = s[i] == c;
        }
        S.resize(size);
        fft.fft(S, false);
        Ss[c - 'a'] = S;
    }
    vector<vcd> Ts(6);
    for (char c = 'a'; c <= 'f'; c++) {
        vcd T(t.size());
        for (int i = 0; i < (int)t.size(); i++) {
            T[i] = t[i] == c;
        }
        T.resize(size);
        fft.fft(T, false);
        Ts[c - 'a'] = T;
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (i == j)
                continue;
            auto res = vcd(size);
            for (int k = 0; k < (size); k++)
                res[k] = Ss[i][k] * Ts[j][k];
            fft.fft(res, true);
            for (int k = 0; k < n; k++) {
                if (round(res[t.size() - 1 + k].real()))
                    ufs[k].Union(i, j);
            }
        }
    }

    for (auto uf : ufs) {
        int result = 6;
        for (int i = 0; i < 6; i++) {
            if (uf.Find(i) == i)
                result--;
        }
        cout << result << " ";
    }
    cout << endl;
}