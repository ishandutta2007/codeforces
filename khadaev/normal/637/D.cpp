#include <iostream>
#include <algorithm>

using namespace std;

int b[200005], e[200005];

int a[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    for (int i = 1; i <= n; i++)  {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    a[0] = -1;

    int k = 1;

    for (int i = 1; i <= n; i++) {
        if (a[i] - a[i - 1] >= s + 2) {
            e[k - 1] = i - 1;
            b[k] = i;
            k++;
        }
    }

    k--;

    e[k] = n;

    bool w = 1;

    if (b[1] != 1) {
        w = 0;
    }

    int i = 1;

    while (w && (i <= k)) {
        if (a[e[i]] - a[b[i]] > d - 2) {
            w = 0;
        }
        i++;
    }

    if (w == 0) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (i = 1; i <= k; i++) {
            cout << "RUN " << (a[b[i]] - a[e[i - 1]] - 2) << "\n";
            cout << "JUMP " << (a[e[i]] - a[b[i]] + 2) << "\n";
        }
        if (a[e[k]] + 1 < m) {
            cout << "RUN " << (m - a[e[k]] - 1) << "\n";
        }
    }


}