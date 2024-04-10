#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m, a;
    cin >> n >> m >> a;
    
    vector<int> b(n);
    for (int idx = 0; idx < n; idx++)
        cin >> b[idx];
    
    vector<int> p(m);
    for (int idx = 0; idx < m; idx++)
        cin >> p[idx];
    
    sort(b.begin(), b.end());
    sort(p.begin(), p.end());

    int L = 0;
    int R = n + 1;

    int total_best = 0;
    while (L + 1 < R) {
        int M = (L + R) / 2;

        int s = a;
        int total = 0;
        for (int i = 0; i < M; i++) {
            int price = p[i];
            int money = b[n - M + i];

            if (price > money) {
                int diff = price - money;
                if (diff > s) {
                    s = -1;
                    break;
                }
                s -= diff;
                total += money;
            }
            else
                total += price;
        }

        if (s >= 0) {
            total = max(0, total - s);
            total_best = total;
            L = M;
        }
        else 
            R = M;
    }

    cout << L << " " << total_best << endl;

    return 0;
}