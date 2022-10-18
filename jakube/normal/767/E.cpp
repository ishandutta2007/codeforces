#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    priority_queue<pair<int, int>> pq;
    vector<int> days(n, 0);
    long long result = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] % 100 == 0) continue;

        pq.push({-w[i] * (100 - (c[i] % 100)), i});

        m -= c[i] % 100;
        if (m < 0) {
            m += 100;
            result += -pq.top().first;
            int idx = pq.top().second;
            days[idx] = 1;
            pq.pop();
        }
    }

    cout << result << '\n';
    for (int i = 0; i < n; i++) {
        if (days[i] == 1) {
            cout << (c[i] + 99) / 100 << ' ' << 0 << '\n';
        } else {
            cout << c[i] / 100 << ' ' << c[i] % 100 << '\n';
        }
    }
    
    return 0;
}