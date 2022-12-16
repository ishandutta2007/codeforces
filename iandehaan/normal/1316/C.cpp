#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, p;
    cin >> n >> m >> p;

    int a[n];
    int b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int aptr = 0;
    int bptr = 0;
    while (true) {
        if ((a[aptr] % p != 0) && (b[bptr] % p != 0)) {
            cout << aptr + bptr << endl;
            return 0;
        }

        if (a[aptr]%p == 0) aptr++;
        if (b[bptr]%p == 0) bptr++;
    }
}