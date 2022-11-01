#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int d;
int mn = -2e9;
int mx = 2e9;

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        int c, dv; scanf("%d %d", &c, &dv);
        if (dv == 1) {
            // init >= 1900-d
            mn = max(mn, 1900-d);
        } else {
            // init <= 1899-d
            mx = min(mx, 1899-d);
        }
        d += c;
    }
    if (mn > mx) printf("Impossible\n");
    else if (mx > 1e9) printf("Infinity\n");
    else printf("%d\n", mx+d);
}