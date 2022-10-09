// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());
using uid = uniform_int_distribution<ll>;
using urd = uniform_real_distribution<double>;

int n;

struct baza {
    int idx[3];
    int a, b;
};

map<tuple<int, int, int>, int> cache;

int ask(int x, int y, int z) {
    // let's see if this will help...
    if ((int)cache.size() >= 418 + 2*n) {
        while (1);
    }

    int a[3] = {x, y, z};
    sort(a, a+3);
    x = a[0], y = a[1], z = a[2];

    if (cache.count({x, y, z})) {
        return cache[{x, y, z}];
    }

    cout << "? " << x << ' ' << y << ' ' << z << '\n' << flush;
    int t;
    cin >> t;
    return cache[{x, y, z}] = t;
}

baza nadji() {
    while (1) {
        int idx[4];
        for (int i=0; i<4; i++) {
            idx[i] = uid(1, n)(eng);
        }
        sort(idx, idx+4);
        bool ok = 1;
        for (int i=0; i<3; i++) {
            if (idx[i] == idx[i+1]) {
                ok = 0;
            }
        }
        if (!ok) continue;

        int ans[4];
        ans[0] = ask(idx[1], idx[2], idx[3]);
        ans[1] = ask(idx[0], idx[2], idx[3]);
        if (ans[1] == ans[0]) continue;
        ans[2] = ask(idx[0], idx[1], idx[3]);
        if (ans[2] == ans[1] || ans[2] == ans[0]) continue;
        ans[3] = ask(idx[0], idx[1], idx[2]);

        // let's hope this is enough
        int aso[4];
        copy(ans, ans+4, aso);
        sort(aso, aso+4);

        if (aso[0] != aso[1] && aso[1] != aso[2] && aso[2] != aso[3]) {
            if (aso[3] != aso[1] + aso[0]) {
                baza z;
                z.a = aso[0];
                z.b = aso[2] - aso[0];
                
                const int table[3] = {1, 2, 3};
                for (int i=0; i<3; i++) {
                    z.idx[i] = idx[find(ans, ans+4, aso[table[i]]) - ans];
                }

                return z;
            } else if (aso[3] != aso[2] + aso[1] - aso[0]) {
                baza z;
                z.a = aso[2] - aso[0];
                z.b = aso[0];

                const int table[3] = {1, 2, 3};
                for (int i=0; i<3; i++) {
                    z.idx[i] = idx[find(ans, ans+4, aso[table[i]]) - ans];
                }

                // flip
                swap(z.a, z.b);
                swap(z.idx[0], z.idx[2]);

                return z;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cache.clear();
        auto z = nadji();

        auto q = z;

        vector<int> pos(n+1);
        pos[q.idx[0]] = 0;
        pos[q.idx[1]] = q.a;
        pos[q.idx[2]] = q.a + q.b;

        vector<int> middle;
        vector<pair<int, int>> big;

        int spec = -1;
        int spec2 = -1;
        for (int i=1; i<=n; i++) {
            if (count(q.idx, q.idx+3, i)) continue;

            int x = ask(q.idx[1], q.idx[2], i);
            if (x < q.b) {
                // assert q.a > q.b
                pos[i] = ask(q.idx[0], i, q.idx[2]);

                // spec
                if (pos[i] == pos[q.idx[1]] + 1) {
                    spec = i;
                }

                if (pos[i] == pos[q.idx[1]] + 2) {
                    spec2 = i;
                }

            } else if (x == q.b) {
                middle.push_back(i);
            } else {
                big.emplace_back(i, x);
            }
        }

        if (z.b >= 3) {
            for (int i : middle) {
                int x = ask(q.idx[1], spec, i);
                if (x < q.b) {
                    pos[i] = q.a - x;
                } else if (x > q.b) {
                    pos[i] = q.a + 1 + x;
                } else {
                    // ovo je samo dvaput, tako da je ok
                    int y = ask(spec, spec2, i);
                    if (y == q.b + 1) {
                        pos[i] = q.a - q.b;
                    } else {
                        pos[i] = q.a + q.b + 1;
                    }
                }
            }
        } else if (z.b == 2) {
            for (int i : middle) {
                int x = ask(q.idx[1], spec, i);
                int y = ask(spec, q.idx[2], i);

                if (x < y) {
                    // levo
                    pos[i] = q.a - x;
                } else {
                    pos[i] = q.a + 1 + x;
                }
            }
        } else if (z.b == 1) {
            for (int i : middle) {
                int x = ask(q.idx[0], q.idx[1], i);
                if (x == 1) {
                    pos[i] = q.a - 1;
                } else {
                    pos[i] = q.a + 2;
                }
            }
        }

        for (auto [i, x] : big) {
            int y = ask(q.idx[1], spec, i);
            if (y == x) {
                pos[i] = q.a - x;
            } else {
                pos[i] = q.a + 1 + y;
            }
        }

        // permutize
        if (pos[1] > pos[2]) {
            for (int i=1; i<=n; i++) pos[i] *= -1;
        }

        {
            int h = *max_element(pos.begin() + 1, pos.end());
            for (int i=1; i<=n; i++) pos[i] += n - h;
        }

        cout << '!';
        for (int i=1; i<=n; i++) {
            cout << ' ' << pos[i];
        }
        cout << '\n' << flush;
        {
            int ok;
            cin >> ok;
            if (ok == -1) {
                while (1);
            }
        }
    }
}