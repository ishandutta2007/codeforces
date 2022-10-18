#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

template <typename T>
void transpose(std::vector<std::vector<T>> & M) {
    auto tmp = M;
    M.resize(tmp[0].size());
    for (auto& row : M)
        row.resize(tmp.size());

    for (int i = 0; i < (int)M.size(); i++) {
        for (int j = 0; j < (int)M[0].size(); j++) {
            M[i][j] = tmp[j][i];
        }
    }
}

class FFT {
public:
    FFT(int max_degree) {
        int lg = get_lg(max_degree + 1);
        reverse.resize(lg + 1);

        int size = 1 << lg;
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
    using vvcd = std::vector<vcd>;

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

    void multiply(vcd & fa, vcd & fb) {
        int result_size = fa.size() + fb.size() - 1;
        int size = 1 << get_lg(result_size);
        fa.resize(size);
        fb.resize(size);

        fft(fa, false);
        fft(fb, false);
        for (int i = 0; i < size; i++)
            fa[i] *= fb[i];
        fft(fa, true);

        fa.resize(result_size);
    }

    template <typename T>
    std::vector<long long> multiply(std::vector<T> const& a, std::vector<T> const& b) {
        int result_size = a.size() + b.size() - 1;
        if (result_size <= 200)
            return multiply_brute_force(a, b, result_size);

        vcd fa(a.begin(), a.end()), fb(b.begin(), b.end());
        multiply(fa, fb);

        std::vector<long long> result(result_size);
        for (int i = 0; i < result_size; i++)
            result[i] = std::llround(fa[i].real());
        return result;
    }

    void fft2D(vvcd & a, bool inv) {
        for (auto& row : a)
            fft(row, inv);
        transpose(a);
        for (auto& row : a)
            fft(row, inv);
        transpose(a);
    }

    void multiply2D(vvcd & a, vvcd & b) {
        int result_r = a.size() + b.size() - 1;
        int result_c = a[0].size() + b[0].size() - 1;
        int size_r = 1 << get_lg(result_r);
        int size_c = 1 << get_lg(result_c);
        a.resize(size_r);
        b.resize(size_r);
        for (auto& row : a)
            row.resize(size_c);
        for (auto& row : b)
            row.resize(size_c);

        fft2D(a, false);
        fft2D(b, false);
        for (int i = 0; i < size_r; i++) {
            for (int j = 0; j < size_c; j++) {
                a[i][j] *= b[i][j];
            }
            
        }
        fft2D(a, true);

        a.resize(result_r);
        for (auto& row : a)
            row.resize(result_c);
    }

private:
    std::vector<std::vector<int>> reverse;
    std::vector<vcd> ws;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> t(2*n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    int r, c;
    cin >> r >> c;
    vector<string> p(r);
    for (int i = 0; i < r; i++) {
        cin >> p[i];
        reverse(p[i].begin(), p[i].end());
    }
    for (auto& T : t) {
        T.resize(m + c - 1);
        for (int i = m; i < m + c - 1; i++)
            T[i] = T[i-m];
    }
    t.resize(n + r - 1);
    for (int i = n; i < n + r - 1; i++)
        t[i] = t[i-n];

    int target = 0;
    for (auto row : p)
        for (char c : row)
            target += c != '?';

    FFT fft(1200);
    // for (int x = 0; x < n; x++) {
    //     vector<bool> bo(m, true);
    //     for (int y = 0; y < r; y++) {
    //         vector<FFT::cd> a;
    //         for (char c : t[x+y]) {
    //             double angle = 2 * PI / 26 * (c - 'a');
    //             a.push_back({cos(angle), sin(angle)});
    //         }
    //         vector<FFT::cd> b;
    //         for (char c : p[y]) {
    //             if (c == '?') {
    //                 b.push_back(0);
    //             } else {
    //                 double angle = 2 * PI / 26 * (c - 'a');
    //                 b.push_back({cos(angle), -sin(angle)});
    //             }
    //         }
    //         fft.multiply(a, b);
    //         vector<int> res(a.size());
    //         for (int i = 0; i < (int)a.size(); i++) {
    //             res[i] = floor(a[i].real() + 0.001);
    //         }
    //         for (int i = 0; i < m; i++) {
    //             bo[i] = bo[i] & (res[i + c - 1] == c - sum(y,0,y,c-1));
    //         }
    //     }
    //     for (bool b : bo)
    //         cout << b;
    //     cout << '\n';
    // }

    FFT::vvcd a(t.size(), FFT::vcd(t[0].size()));
    for (int i = 0; i < (int)t.size(); i++) {
        for (int j = 0; j < (int)t[0].size(); j++) {
            double angle = 2 * PI / 26 * (t[i][j] - 'a');
            a[i][j] = {cos(angle), sin(angle)};
        }
    }
    reverse(p.begin(), p.end());
    FFT::vvcd b(r, FFT::vcd(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (p[i][j] != '?') {
                double angle = -2 * PI / 26 * (p[i][j] - 'a');
                b[i][j] = {cos(angle), sin(angle)};
            }
        }
    }

    fft.multiply2D(a, b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (target == std::floor(a[i + r - 1][j + c - 1].real() + 0.001));
            // cout << a[i + r - 1][j + c - 1].real() << " ";
        }
        cout << endl;
    }
}