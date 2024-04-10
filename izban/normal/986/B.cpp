#include <bits/stdc++.h>
#define pw(x) (1LL << (x))
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl

using namespace std;
typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;

vector<int> gen(int n, int k) {
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    for (int i = 0; i < k; i++) {
        int l = 0, r = 0;
        while (l == r) {
            l = rand() % n;
            r = rand() % n;
        }
        swap(p[l], p[r]);
    }
    return p;
}

vector<int> gen1(int n) {
    return gen(n, 3 * n);
}

vector<int> gen2(int n) {
    return gen(n, 7 * n + 1);
}


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


ll inversions(vector<int> p) {
    int n = p.size();
    fenwick<int> f(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += f.get(p[i], n - 1);
        f.add(p[i], 1);
    }
    return ans;
}

string solve(vector<int> p) {
    ll x = inversions(p);
    int y = (x % 2) ^ (p.size() % 2);
    return y == 1 ? "Um_nik" : "Petr";
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    /*for (int i = 0; i < 100; i++) {
        //int n = rand() % (int)1e6 + 1e3;
        int n = rand() % 5 + 2;
        vector<int> p;
        string need;
        if (rand() % 2) {
            p = gen1(n);
            need = "Petr";
        } else {
            p = gen2(n);
            need = "Um_nik";
        }
        cerr << n << " " << solve(p) << " " << need << endl;
        for (int x : p) cerr << x << " "; cerr << endl;
        cerr << inversions(p) << endl;
        assert(solve(p) == need);
    }
    return 0;*/

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
            p[i]--;
        }
        cout << solve(p) << endl;
    }

#ifdef HOME
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
#endif
    return 0;
}