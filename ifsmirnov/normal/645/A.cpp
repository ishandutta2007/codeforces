#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef vector<int> vi;

char buf[10];

int R[2];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    forn(I, 2) {
        int c = 0;
        int a[3] = {0,0,0};
        forn(i, 2) {
            scanf("%s", buf);
            forn(j, 2) {
                if (buf[j] == 'X') c += i;
                else {
                    int x = buf[j] - 'A';
                    for (int k = 0; k < x; ++k) if (!a[k]) ++c;
                    ++a[x];
                }
            }
        }
        R[I] = c % 2;
    }
    cout << (R[0] == R[1] ? "YES" : "NO") << endl;

    return 0;
}