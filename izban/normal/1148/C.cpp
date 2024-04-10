#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;


const ll INF = 4e9;

void print(vector<pair<int, int>> a) {
    printf("%d\n", (int)a.size());
    for (auto o : a) printf("%d %d\n", o.first + 1, o.second + 1);
}

vector<pair<int, int>> solve(vector<int> a) {
    int n = a.size();

    auto was = a;

    vector<int> rev(n);
    for (int i = 0; i < n; i++) rev[a[i]] = i;

    vector<pair<int, int>> ans;
    auto Swap = [&](int i, int j) {
        assert(abs(i - j) * 2 >= n);
        swap(a[i], a[j]);
        swap(rev[a[i]], rev[a[j]]);
        ans.push_back({i, j});
    };

    for (int i = 1; i * 2 < n; i++) {
        if (rev[i] * 2 >= n) {
            Swap(rev[i], 0);
        }
        Swap(rev[i], n - 1);
        Swap(n - 1, i);
    }
    for (int i = n / 2; i < n - 1; i++) {
        if (rev[i] * 2 < n) {
            Swap(rev[i], n - 1);
        }
        Swap(rev[i], 0);
        Swap(0, i);
    }
    if (a[0] != 0) {
        Swap(0, n - 1);
    }


    assert((int)ans.size() <= 5 * n);
    for (auto &o : ans) {
        assert(0 <= o.first && o.first < n && 0 <= o.second && o.second < n);
        assert(o.first != o.second);
        assert(2 * abs(o.first - o.second) >= n);
        swap(was[o.first], was[o.second]);
    }
    for (int i = 1; i < n; i++) assert(was[i] > was[i - 1]);

    return ans;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
    if (0) {
        for (int n = 2; n <= 10; n += 2) {
            db(n);
            vector<int> p(n);
            iota(p.begin(), p.end(), 0);
            do {
                solve(p);
            } while (next_permutation(p.begin(), p.end()));
        }
    }

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            a[i]--;
        }

        print(solve(a));
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}