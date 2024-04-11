#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, te, a[3][N], b[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> te;
    while (te--) {
        cin >> n;
        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < n; i++) {
                cin >> a[j][i];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                if (a[j][i] != b[(i + n - 1) % n] && a[j][i] != b[(i + 1) % n]) {
                    b[i] = a[j][i];
                    break;
                }
            }
            cout << b[i] << " \n"[i == n - 1];
        }
    }
}