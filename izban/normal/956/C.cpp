#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dbl;
const int INF = (int)1.01e9;

template <typename T>
struct fenwick {
    int n;
    vector<T> f;

    fenwick() {}

    fenwick(int N) {
        n = N;
        f.assign(N, T(0));
    }

    fenwick(vector<T> a) {
        n = a.size();
        for (int i = 0; i < n; i++) add(i, a[i]);
    }

    void add(int x, T y) {
        for (; x < n; x |= x + 1) f[x] += y;
    }

    T get(int x) {
        T res(0);
        for (; x >= 0; x = (x & (x + 1)) - 1) res += f[x];
        return res;
    }

    T get(int l, int r) {
        return get(r) - get(l - 1);
    }

    // return min i: sum(0, i) > x
    int upper_bound(T x) {
        int k = 1;
        while (2 * k <= n) k *= 2;

        int res = 0;
        while (k > 0) {
            if (f[res + k - 1] <= x) {
                x -= f[res + k - 1];
                res += k;
            }
            k /= 2;
        }
        return res;
    }
};


int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        //int m = *max_element(a.begin(), a.end()) + 1;
        /*ll ans = 0;
        fenwick<ll> f0(n), f1(n);
        for (int i = n - 1; i >= 0; i--) {
            ans += 1LL * a[i] * f0.get(a[i] - 1) - f1.get(a[i] - 1);
            f0.add(a[i], 1);
            f1.add(a[i], a[i]);
        }
        cout << ans << endl;*/
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = a[i] + 1;
            if (i) b[i] = max(b[i], b[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            b[i] = max(b[i], b[i + 1] - 1);
        }

        ll ans = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (cnt < b[i]) cnt++;
            ans += cnt - a[i] - 1;
        }
        cout << ans << endl;
    }

    return 0;
}