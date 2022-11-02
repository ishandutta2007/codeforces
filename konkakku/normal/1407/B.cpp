#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, te, a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> te;
    while (te--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            pair<int, int> mx = {0, 0};
            for (int j = 1; j <= n; j++) {
                if (a[j] != -1) {
                    mx = max(mx, {__gcd(cur, a[j]), j});
                }
            }
            int ind = mx.second;
            cur = mx.first;
            cout << a[ind] << " \n"[i == n];
            a[ind] = -1;
        }
    }
}