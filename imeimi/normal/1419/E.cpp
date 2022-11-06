#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<lf, lf> pff;

void solve() {
    int n;
    cin >> n;
    vector<int> P, D;
    int x = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            D.push_back(i);
            if (i * i < n) D.push_back(n / i);
        }
        if (x % i) continue;
        P.push_back(i);
        while (x % i == 0) x /= i;
    }
    if (x > 1) P.push_back(x);
    D.push_back(n);
    int m = P.size();
    vector<int> ans;
    if (m == 1) {
        ans = D;
    }
    else if (m == 2) {
        int x = P[0], y = P[1];
        for (llong v = x; n % v == 0; v *= x) ans.push_back(v), D.erase(find(D.begin(), D.end(), int(v)));
        ans.push_back(x * y);
        D.erase(find(D.begin(), D.end(), x * y));
        for (llong v = y; n % v == 0; v *= y) ans.push_back(v), D.erase(find(D.begin(), D.end(), int(v)));
        ans.insert(ans.end(), D.begin(), D.end());
    }
    else {
        for (int i = 0; i < m; ++i) {
            int x = P[i], y = P[(i + 1) % m];
            D.erase(find(D.begin(), D.end(), x * y));
        }
        for (int i = 0; i < m; ++i) {
            int x = P[i], y = P[(i + 1) % m];
            vector<int> nD;
            for (int i : D) (i % x == 0 ? ans : nD).push_back(i);
            ans.push_back(x * y);
            swap(D, nD);
        }
    }
    for (int i : ans) printf("%d ", i);
    printf("\n%d\n", m == 2 && n == P[0] * P[1]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}