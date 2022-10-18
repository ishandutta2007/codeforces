#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> b(2*n), a(2*n, 0);
    for (auto& x : b)
        cin >> x;
    for (int i = 0; i < n; i++) {
        b[i + n] = b[i];
    }
    b.push_back(b[0]);


    for (int i = n; i < 2*n; i++) {
        if (b[i] > b[i-1]) {
            // TODO: what with other cases

            // assume this one is fixed
            a[i] = b[i];
            for (int j = i-1; j + n > i; j--) {
                a[j] = b[j];
                if (a[j] <= b[j-1]) {
                    long long x = b[j-1] - a[j];
                    x += a[j+1];
                    x /= a[j+1];
                    a[j] += x * a[j+1];
                }
                // while (a[j] <= b[j-1])
                //     a[j] += a[j+1];
            }

            cout << "YES" << '\n';
            for (int i = 0; i < n; i++) {
                cout << a[i] + a[i+n] << " ";
            }
            cout << endl;
            return 0;
        }
    }

    if (*max_element(b.begin(), b.end()) == 0) {
        cout << "YES" << '\n';
        for (int i = 0; i < n; i++) {
            cout << 1 << " ";
        }
        cout << endl;
        return 0;
    }

    cout << "NO" << '\n';
}