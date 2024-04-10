#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    vector<int> cnt_a(5, 0), cnt_b(5, 0);
    for (int i : a)
        cnt_a[i - 1]++;
    for (int i : b)
        cnt_b[i - 1]++;

    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        if ((cnt_a[i] + cnt_b[i]) % 2) {
            cout << -1 << endl;
            return 0;
        }

        cnt += abs(cnt_a[i] - cnt_b[i]) / 2;
    }

    cout << cnt / 2 << endl;
}