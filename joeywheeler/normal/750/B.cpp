#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
char d[50];

int main() {
    scanf("%d", &n);
    int y = 10000;
    FO(z,0,n) {
        int t; scanf("%d %s", &t, d);
        if (d[0] == 'N') {
            y += t;
        } else if (d[0] == 'S') {
            y -= t;
        } else if (y == -10000 || y == 10000) {
            printf("NO\n");
            return 0;
        }
        if (y < -10000 || y > 10000) {
            printf("NO\n");
            return 0;
        }
    }
    if (y != 10000) printf("NO\n");
    else printf("YES\n");
}