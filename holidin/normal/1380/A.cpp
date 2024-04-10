#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 1;


void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n - 1; ++i) {
        int ps = -1, sc = -1;
        for (int j = 0; j < n; ++j)
        if (a[j] < a[i]) {
            if (j < i)
                ps = j;
            else
                sc = j;
        }
        if (ps >= 0 && sc >= 0) {
            cout << "YES\n" << ps + 1 << ' ' << i + 1 << ' ' << sc + 1 << "\n";
            return;
        }

    }
    cout << "NO\n";
}


int main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test;
    cin >> test;
    for (; test > 0; test--)
        solve();
}