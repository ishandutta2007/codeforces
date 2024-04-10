#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        while (i != a[i]) {
            cnt += 1;
            swap(a[i], a[a[i]]);
        }
    }
    // cout << cnt << '\n';
    
    // cnt + 2*x = 3*y
    if ((3 * n - cnt) % 2 == 0) {
        cout << "Petr" << '\n';
    }
    else {
    // cnt + 2*x = 7*y + 1
    // if ((7 * n + 1 - cnt) % 2 == 0) {
        cout << "Um_nik" << '\n';
    }
}