#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, a, b;
int c0 = 2, c1 = 1;

int main() {
    scanf("%d%d%d", &n, &a, &b);
    if (a*b >= n) {
        FO(y,0,a) FO(x,0,b) {
            int v = 0;
            if ((y^x)&1) {
                v = c0;
                c0 += 2;
            } else {
                v = c1;
                c1 += 2;
            }
            if (v > n) v = 0;
            printf("%d%c", v, " \n"[x+1==b]);
        }
    } else {
        printf("-1\n");
    }
}