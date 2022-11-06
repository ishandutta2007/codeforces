#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int r = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            j++;
        }
        if (r == j) cnt++;
        else if (j > r) {
            r = j;
            cnt = 1;
        }
    }

    cout << (1 << r) << ' ' << cnt << '\n';
}