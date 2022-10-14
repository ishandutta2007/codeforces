#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 105;

llint t, n, U, V;
int a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> U >> V;
        bool ok = 1, isti = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (i > 1 && abs(a[i] - a[i - 1]) > 1) ok = 0;
            if (i > 1 && a[i] != a[i - 1]) isti = 0;
        }
        if (ok == 0) {
            cout << "0\n";
        } else if (isti) {
            cout << V + min(U, V) << '\n';
        } else {
            cout << min(U, V) << '\n';
        }
    }
    return 0;
}