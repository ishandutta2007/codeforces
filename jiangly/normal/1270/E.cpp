#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    for (int i = n - 1; i >= 0; --i) {
        x[i] -= x[0];
        y[i] -= y[0];
    }
    while (true) {
        vector<int> a;
        for (int i = 0; i < n; ++i)
            if ((x[i] + y[i]) % 2 == 0)
                a.push_back(i);
        if (!a.empty() && a.size() != n) {
            cout << a.size() << "\n";
            for (int i : a)
                cout << i + 1 << " \n"[i == a.back()];
            return 0;
        }
        for (int i = 0; i < n; ++i)
            tie(x[i], y[i]) = make_pair((x[i] - y[i]) / 2, (x[i] + y[i]) / 2);
    }
}