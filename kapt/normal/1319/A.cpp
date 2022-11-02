#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int a[MAXN], b[MAXN];

main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int cnt = 0; int k = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] > a[i]) {
            cnt++;
        }
        if (a[i] > b[i]) {
            k++;
        }
    }
    if (k == 0) {
        cout << -1;
    } else {
        cout << (cnt + k) / k;
    }
    return 0;
}