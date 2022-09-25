#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //[x * x, x * x + x]
    int n, m = 2000000;
    cin >> n;
    //n = 1000000;
    vector<int> a(n), p(m + 1), s(m + 1);
    for (int& ai : a) {
        cin >> ai;
        //ai = rand() % m + 1;
        p[ai] = 1;
    }
    for (int i = m; i >= 0; i -= 1) {
        s[i] = i == m ? m + 1 : s[i + 1];
        if (p[i]) s[i] = i;
    }
    for (LL x = 1; x <= m; x += 1) {
        for (LL y = 0; y <= x; y += 1) {
            LL k = x * x + y - a[0];
            if (k < 0) continue;
            int ok = 1;
            for (LL i = x; i * i + i + 1 <= a.back() + k; i += 1) {
                LL z = s[i * i + i + 1 - k];
                if (z + k <= i * i + 2 * i) {
                    y += i * i + 2 * i - (z + k);
                    ok = 0;
                    break;
                }
            } 
            if (ok) {
                cout << k;
                return 0;
            }
        }
    }
    return 0;
}