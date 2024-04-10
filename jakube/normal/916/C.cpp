#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int mstw = 1299721;
    cout << mstw << " " << mstw << '\n';
    auto print = [](int u, int v, int w) { cout << u << " " << v << " " << w << '\n'; };

    for (int i = 1; i <= n - 2; i++) {
        print(i, i+1, 1);
    }
    print(n-1, n, mstw - (n - 2));

    m -= n - 1;
    for (int i = 1; i <= n && m > 0; i++) {
        for (int j = i + 2; j <= n && m > 0; j++) {
            print(i, j, mstw + 1);
            m--;
        }
    }
}