#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
typedef complex<ld> comp;

const ld pi = 4 * atan(1.0);

void fft(vector<comp>& a, int k, bool flag) {
    int n = (1 << k);
    assert(sz(a) == n);
    vector<int> rev(n);
    int oldest = -1;
    rev[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (!(i & (i - 1))) {
            ++oldest;
        }
        rev[i] = rev[i ^ (1 << oldest)] + (1 << (k - oldest - 1));
    }
    for (int i = 0; i < n; ++i) {
        if (rev[i] < i) {
            swap(a[i], a[rev[i]]);
        }
    }
    for (int r = 0; r < k; ++r) {
        ld angle = 2 * pi / (1 << (r + 1));
        if (flag) {
            angle *= (-1);
        }
        comp omega = {cos(angle), sin(angle)};
        for (int i = 0; i < n; i += (1 << (r + 1))) {
            comp p = {1, 0};
            for (int j = 0; j < (1 << r); ++j) {
                comp x = a[i + j], y = a[i + j + (1 << r)];
                y *= p;
                a[i + j] = x + y;
                a[i + j + (1 << r)] = x - y;
                p *= omega;
            }
        }
    }
    if (flag) {
        for (int i = 0; i < n; ++i) {
            a[i] /= n;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> c(m + 1);
    c[0] = 1;
    vector<int> p(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        p[x] = 1;
        for (int j = x; j <= m; j += x) {
            c[j] = 1;
        }
    }

    int k = 0;
    while ((1 << k) <= 2 * m + 1) {
        ++k;
    }
    vector<comp> a(1 << k);
    for (int i = 0; i <= m; ++i) {
        a[i] = c[i];
    }

    fft(a, k, false);
    for (int i = 0; i < sz(a); ++i) {
        a[i] *= a[i];
    }
    fft(a, k, true);

    vector<int> ans;
    for (int i = 1; i <= m; ++i) {
        int cnt = round(a[i].real());
        if (cnt >= 1 && p[i] == 0) {
            cout << "NO\n";
            return 0;
        }
        if (cnt == 0) {
            continue;
        }
        if (cnt == 2) {
            ans.pb(i);
        }
    }

    cout << "YES\n";
    cout << sz(ans) << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";

}