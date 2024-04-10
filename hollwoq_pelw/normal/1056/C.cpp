#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int N = 2002;

int p[N];
bool w[N];
int a[N];
int b[N];

int main() {
#ifdef BZ
    //freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> p[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
        if (p[a[i]] < p[b[i]]) {
            swap(a[i], b[i]);
        }
    }

    int t;
    cin >> t;

    int pv = -1;
    for (int i = 0; i < 2 * n; ++i) {
        if (i % 2 != t % 2) {
            int x = -1;
            for (int j = 0; j < m; ++j) {
                if ((!w[a[j]] || !w[b[j]]) && (pv == a[j] || pv == b[j])) {
                    x = a[j] + b[j] - pv;
                }
            }

            if (x == -1) {
                for (int j = 0; j < m; ++j) {
                    if (!w[a[j]]) {
                        x = a[j];
                    }
                }
            }

            if (x == -1) {
                for (int j = 0; j < 2 * n; ++j) {
                    if (!w[j] && ((x == -1) || p[j] > p[x])) {
                        x = j;
                    }
                }
            }

            assert(x != -1);
            cout << x + 1 << endl;
            w[x] = true;
        } else {
            cin >> pv;
            --pv;
            w[pv] = true;
        }
    }
}