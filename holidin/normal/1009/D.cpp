#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;


int gcd(int a, int b) {
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    vector <pair<int, int> > v;
    int i, j, n, q, top, l, r, t, k, x, d;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    if (k < n - 1) {
        cout << "Impossible";
        return 0;
    }
    for (i = 2; i <= n; ++i)
        v.push_back({1, i});
    for (i = 2; i <= n; ++i) {
        for (j = i + 1; j <= n && v.size() < k; ++j)
        if (gcd(i, j) == 1)
            v.push_back({i, j});
    }
    if (v.size() < k) {
        cout << "Impossible";
        return 0;
    }
    cout << "Possible\n";
    for (i = 0; i < k; ++i)
        cout << v[i].first << ' ' << v[i].second << "\n";
}