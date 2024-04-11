#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector< vector<int> > a(n, vector<int>(n, 0));
    int cnt = n * n / 2 + 1;
    for (int i = 0; i < n; i++) {
        a[n / 2][i] = 1; cnt--;
        if (i != n / 2) a[i][n / 2] = 1; cnt--;
    }
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            int tmp;
            if (cnt > 0) tmp = 1, cnt -= 4;
            else tmp = 0;
            a[i][j] = a[n - 1 - i][j] = tmp;
            a[i][n - 1 - j] = a[n - 1 - i][n - 1 - j] = tmp;
        }
    }

    int odd = 1, even = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j]) {
                cout << odd << ' ';
                odd += 2;
            } else {
                cout << even << ' ';
                even += 2;
            }
        }
        cout << '\n';
    }

}