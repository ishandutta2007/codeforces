#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]]++;
    }
    sort(v.begin(), v.end());
    if (v.back() - v.front() < 2) {
        cout << n << endl;
        for (int x : v)
            cout << x << " ";
        cout << endl;
        return 0;
    }
    int a = v.front();
    int b = a + 1;
    int c = b + 1;
    int x = m[b] / 2;
    int y = min(m[a], m[c]);
    if (x > y) {
        m[a] += x;
        m[b] -= 2 * x;
        m[c] += x;
    } else {
        m[a] -= y;
        m[b] += 2*y;
        m[c] -= y;
    }

    cout << n - max(x, y) * 2 << endl;
    for (auto [val, cnt] : m) {
        for (int i = 0; i < cnt; i++) {
            cout << val << " ";
        }
    }
    cout << endl;
}