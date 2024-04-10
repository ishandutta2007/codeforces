#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for (int idx = 0; idx < n; idx++)
        cin >> a[idx];
    
    long long L = 0;
    long long R = accumulate(a.begin(), a.end(), 0LL) + n;

    while (L + 1 < R) {
        long long M = (L + R) / 2;

        long long persons = 0;
        long long resources = 0;
        bool impossible = false;
        for (int i = n-1; i >= 0; i--) {
            long long todo = a[i];
            if (resources > todo) {
                resources -= todo;
                todo = 0;
            } else {
                todo -= resources;
                resources = 0;
            }

            if (todo > 0) {
                // (i + 1) * n + todo <= n * M
                // todo <= n * (M - i - 1)
                // n >= todo / (M - i - 1)
                long long tmp = M - i - 1;
                if (tmp <= 0) {
                    impossible = true;
                    break;
                }
                long long cnt = (todo + tmp - 1) / tmp;
                persons += cnt;

                if (persons > m) {
                    impossible = true;
                    break;
                }

                resources += cnt * M - todo - (i + 1) * cnt;
            }
        }

        if (!impossible) {
            R = M;
        } else {
            L = M;
        }
    }

    cout << R << endl;

    return 0;
}