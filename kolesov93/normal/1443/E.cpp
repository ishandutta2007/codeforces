#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

const int N = 16;
ll fact[N];

vector<int> get_perm(int n, ll num) {
    vector<int> a(n);
    vector<char> used(n);
    for (int pos = 0; pos < n; ++pos) {
        bool done = false;
        for (int i = 0; i < n; ++i) {
            if (used[i]) {
                continue;
            }

            if (fact[n - pos - 1] > num) {
                done = true;
                used[i] = true;
                a[pos] = i;
                break;
            } else {
                num -= fact[n - pos - 1];
            }
        }

        if (!done) {
            for (int i = n - 1; i >= 0; --i) {
                if (!used[i]) {
                    used[i] = true;
                    a[pos] = i;
                    break;
                }
            }
        }
    }
    return a;
}

ll get_sum(ll a, ll b) {
    return (a + b) * (b - a + 1) / 2;
}

int main() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = fact[i - 1] * ll(i);
    }

    int n, q;
    scanf("%d%d", &n, &q);
    int last = min(n, N - 1);
    int first = n - last;
    ll curnum = 0;
    while (q--) {
        int type; scanf("%d", &type);
        if (type == 1) {
            int l, r; scanf("%d%d", &l, &r);

            vector<int> a = get_perm(last, curnum);
            ll ans = 0;
            if (l <= first) {
                ans = get_sum(l, min(r, first));
            }
            for (int i = max(0, l - first - 1); i < r - first; ++i) {
                ans += a[i] + first + 1;
            }
            cout << ans << endl;
        } else {
            int x;
            scanf("%d", &x);
            curnum += x;
        }
    }


    return 0;
}