#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int p = -1, ph = -1, res = 0;
    FO(i,0,m) {
        int x, h;
        scanf("%d %d", &x, &h);
        if (p == -1) {
            res = max(res, (x-1)+h);
        } else {
            if (abs(h-ph) > x-p) {
                printf("IMPOSSIBLE\n");
                return 0;
            } else {
                res = max(res, ((x-p)+h+ph)/2);
            }
        }
        p = x; ph = h;
    }
    res = max(res, ph+(n-p));
    printf("%d\n", res);
}