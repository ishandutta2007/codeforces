#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef double ld;
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

const int inf = 1e9;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");

    int useless;
    cin >> useless >> useless;
    int k;
    cin >> k;
    string s, t;
    cin >> s >> t;

    int n = sz(s), m = sz(t);

    vector<char> letters = {'A', 'C', 'G', 'T'};
    //vector<char> letters = {'A'};
    vector<int> ans(n - m + 1, 0);
    for (char c : letters) {
        vector<int> a(sz(s), 0);
        int lst = -inf;
        for (int i = 0; i < sz(s); ++i) {
            if (s[i] != c) {
                continue;
            }
            int lf = max(i - k, 0);
            int rg = min(i + k, sz(s) - 1);
            for (int j = max(lf, lst + 1); j <= rg; ++j) {
                a[j] = 1;
            }
            lst = rg;
        }
        vector<int> b(sz(t), 0);
        for (int i = 0; i < sz(t); ++i) {
            if (t[i] == c) {
                b[i] = 1;
            }
        }
        reverse(all(b));
        int p = 0;
        while ((1 << p) < sz(a) + sz(b)) {
            ++p;
        }
        vector<comp> A(1 << p), B(1 << p);
        for (int i = 0; i < sz(a); ++i) {
            A[i] = a[i];
        }
        for (int i = 0; i < sz(b); ++i) {
            B[i] = b[i];
        }
        fft(A, p, false);
        fft(B, p, false);
        for (int i = 0; i < sz(A); ++i) {
            A[i] *= B[i];
        }
        fft(A, p, true);
        for (int i = m - 1; i <= n - 1; ++i) {
            int x = round(A[i].real());
            //cout << "!" << x << endl;
            ans[i - (m - 1)] += x;
        }
    }

    int res = 0;
    for (int i = 0; i < sz(ans); ++i) {
        if (ans[i] == m) {
            ++res;
        }
    }
    cout << res << "\n";

}