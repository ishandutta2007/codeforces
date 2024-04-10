#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int t, n;
llint a[MAXN], d[MAXN];
vector <llint> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        v.clear();
        cin >> n;
        llint mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mx = max(mx, a[i]);
            if (i > 0) d[i] = a[i] - a[i - 1];
            if (i > 1 && d[i] != d[i - 1]) v.push_back(abs(d[i] - d[i - 1]));
        }
        if (n <= 2 || v.empty()) {
            cout << "0\n";
            continue;
        }
        llint m = v[0];
        for (auto x : v) m = __gcd(m, x);
        if (mx < m) {
            cout << m << " " << (d[1] + m * ((llint) 4e9)) % m << '\n';
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}