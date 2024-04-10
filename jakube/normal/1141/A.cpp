#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int cnt2 = 0;
    int cnt3 = 0;
    while (n % 2 == 0) {
        cnt2--;
        n /= 2;
    }
    while (m % 2 == 0) {
        cnt2++;
        m /= 2;
    }
    while (n % 3 == 0) {
        cnt3--;
        n /= 3;
    }
    while (m % 3 == 0) {
        cnt3++;
        m /= 3;
    }
    if (n == m && cnt2 >= 0 && cnt3 >= 0) {
        cout << cnt2 + cnt3 << '\n';
    } else {
        cout << -1 << '\n';
    }
}