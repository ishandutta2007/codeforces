#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

const int N = 1005;

int64 n, s, k, qwq;
int64 a[N];

inline void dfs(int64 x, int64 y) {
    if (x == n) {
        if (qwq) return;
        a[n] = y;
        int64 flag = 0;
        for (int64 i = 1; i <= n; i++) {
            int64 s = 0;
            for (int64 j = i; j <= n; j++) {
                s += a[j];
                if (s == k) flag = 1;
            }
        }
        if (!flag) {
            for (int64 i = 1; i <= n; i++) cout << a[i] << "*";
            cout << "\n";
            qwq = 1;
        }
        return;
    }
    if (qwq) return;
    for (int64 i = 1; i <= y - (n - x); i++) {
        a[x] = i, dfs(x + 1, y - i);
    }
}

int main() {
    int64 T;
    cin >> T;
    while (T--) {
        cin >> s >> n >> k;
        qwq = 0;
        int64 qaq = n / k * (k * 2) + n % k;
        int64 ans1, ans2;
        if (k > s) {
            cout << "NO\n";
            ans1 = 0;
        } else if (k == s) {
            cout << "YES\n";
            ans1 = 1;
        } else if (s >= qaq) {
            cout << "NO\n";
            ans1 = 0;
        } else {
            cout << "YES\n";
            ans1 = 1;
        }
    }
    return 0;
}