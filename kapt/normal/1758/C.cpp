#include <bits/stdc++.h>
using namespace std;

int main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n, x;
        cin >> n >> x;
        if (n % x != 0) {
            cout << -1 << endl;
            continue;
        }
        int t = n / x;
        vector<int> pr;
        for (int i = 2; i * i <= t; ++i) {
            while (t % i == 0) {
                t /= i;
                pr.push_back(i);
            }
        }
        if (t != 1) {
            pr.push_back(t);
        }
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            p[i] = i + 1;
        }
        p[0] = x;
        p[n - 1] = 1;
        for (int i = 0; i < (int)pr.size(); ++i) {
            p[x - 1] = x * pr[i];
            x *= pr[i];
        }
        for (int i = 0; i < n; ++i) {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    return 0;
}