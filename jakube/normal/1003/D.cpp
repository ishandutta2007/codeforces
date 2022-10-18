#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> a(30, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[32 - __builtin_clz(x) - 1]++;
    }
    
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        int cnt = 0;
        for (int b = 29; b >= 0; b--) {
            int t = min(a[b], x >> b);
            x -= t << b;
            cnt += t;
        }
        cout << (x ? -1 : cnt) << '\n';
    }
}