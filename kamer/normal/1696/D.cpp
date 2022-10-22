#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <complex>
using namespace std;
typedef long long ll;

struct TreeMax {
    typedef int T;
    static constexpr T unit = -1;
    T f(T a, T b) { return max(a, b); } // (any associative fn )
    vector<T> s; int n;
    TreeMax(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [ b , e)
    T ra = unit, rb = unit;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
        if (b % 2) ra = f(ra, s[b++]);
        if (e % 2) rb = f(s[--e], rb);
    }
    return f(ra, rb);
    }
};

struct TreeMin {
    typedef int T;
    static constexpr T unit = 1'000'000;
    T f(T a, T b) { return min(a, b); } // (any associative fn )
    vector<T> s; int n;
    TreeMin(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [ b , e)
    T ra = unit, rb = unit;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
        if (b % 2) ra = f(ra, s[b++]);
        if (e % 2) rb = f(s[--e], rb);
    }
    return f(ra, rb);
    }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        TreeMax t_max(n);
        TreeMin t_min(n);

        vector<int> pos(n), a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            pos[a[i]] = i;

            t_min.update(i, a[i]);
            t_max.update(i, a[i]);
        }

        if (n == 1) {
            cout << "0\n";
            continue;
        }

        if (n == 2) {
            cout << "1\n";
            continue;
        }

        queue<tuple<int, int, bool>> segs;
        segs.emplace(0, n - 1, true);

        int num_ops = 0;
        while (!segs.empty()) {
            auto [l, r, is_min] = segs.front();
            segs.pop();

            if (r == l + 1) {
                num_ops++;
                continue;
            }

            int m_pos = -1;
            if (is_min) {
                m_pos = pos[t_min.query(l, r + 1)];
            } else {
                m_pos = pos[t_max.query(l, r + 1)];
            }

            if (m_pos > l && m_pos < r) {
                segs.emplace(l, m_pos, !is_min);
                segs.emplace(m_pos, r, !is_min);
            } else {
                int o_pos = is_min ? pos[t_max.query(l, r + 1)] : pos[t_min.query(l, r + 1)];
                num_ops++;
                if (o_pos > l && o_pos < r) {
                    if (m_pos == l) {
                        segs.emplace(o_pos, r, is_min);
                    } else {
                        segs.emplace(l, o_pos, is_min);
                    }
                }
            }
        }

        cout << num_ops << "\n";
    }
}