#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int maxn = 105;

int a[maxn][maxn];
int e, o;
int n;
int A, b;

int main() {
    cin >> n;
    cin >> A >> b;
    e = 2;
    o = 1;
    forn(i, A) forn(j, b) {
        if ((i+j)%2 == 1) {
            if (e <= n) a[i][j] = e, e += 2;
        } else {
            if (o <= n) a[i][j] = o, o += 2;
        }
    }
    if (o > n && e > n) {
        forn(i, A) {
            forn(j, b) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}