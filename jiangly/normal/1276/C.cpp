#include <bits/stdc++.h>
using namespace std;
constexpr int N = 400'000;
int n;
int a[N];
pair<int, int> b[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int t = 0;
    for (int i = 0; i < n; ) {
        int j = i;
        while (a[i] == a[j])
            ++j;
        b[t++] = {j - i, a[i]};
        i = j;
    }
    sort(b, b + t);
    int x = 0, p, q, sum = 0;
    for (int i = 1, j = 0; i <= n; ++i) {
        while (j < t && b[j].first <= i) {
            sum += b[j].first;
            ++j;
        }
        int tot = sum + (t - j) * i;
        int k = tot / i;
        if (k >= i && i * k > x) {
            x = i * k;
            p = i;
            q = k;
        }
    }
    cout << x << "\n";
    cout << p << " " << q << "\n";
    vector<vector<int>> v(p, vector<int>(q));
    for (int i = 0; i < t; ++i)
        if (b[i].first > p)
            b[i].first = p;
    sum = 0;
    for (int i = 0; i < t; ++i) {
        sum += b[i].first;
        if (sum > x) {
            b[i].first -= sum - x;
            t = i + 1;
            break;
        }
    }
    x = 0;
    int y = 0;
    sort(b, b + t, greater<>());
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < b[i].first; ++j) {
            v[x][(x + y) % q] = b[i].second;
            ++x;
            if (x == p) {
                x = 0;
                ++y;
            }
        }
    }
    for (int i = 0; i < p; ++i, cout << "\n")
        for (int j = 0; j < q; ++j)
            cout << v[i][j] << " ";
    return 0;
}