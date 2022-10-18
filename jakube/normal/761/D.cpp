#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, l, r;
    cin >> n >> l >> r;
    
    vector<int> a(n);
    for (int idx = 0; idx < n; idx++)
        cin >> a[idx];

    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        order[tmp-1] = i;
    }

    vector<int> c(n), b(n);
    int lower_bound = numeric_limits<int>::min() / 2;
    for (int i = 0; i < n; i++) {
        // c = b - a => b = c + a
        // c >= lower_bound
        // b >= l
        // => b = max(lower_bound + a, l);
        int idx = order[i];
        b[idx] = max(lower_bound + a[idx], l);
        if (b[idx] > r) {
            cout << -1 << endl;
            return 0;
        }
        lower_bound = b[idx] - a[idx] + 1;
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << ' ';
    }
    cout << endl;

    return 0;
}