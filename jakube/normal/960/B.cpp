#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        a[i] = abs(a[i] - b[i]);
    }

    map<int, int> m;
    for (int x : a)
        m[x]++;

    int k = k1 + k2;
    while (k) {
        int x = m.rbegin()->first;
        if (x == 0)
            break;
        if (m[x] > k) {
            m[x] -= k;
            m[x-1] += k;
            k = 0;
        } else {
            m[x-1] += m[x];
            k -= m[x];
            m.erase(next(m.rbegin()).base());
        }
    }

    if (k) {
        cout << k % 2 << endl;
    } else {
        long long total = 0;
        for (auto it : m) {
            total += (long long)it.first * (long long)it.first * (long long)it.second;
        }
        cout << total << endl;
    }
}