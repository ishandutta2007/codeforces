#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int a[105];
int n;

bool s[105][5];
int c[105][5];

int go(int i, int pd) {
    if (s[i][pd]) return c[i][pd];
    s[i][pd] = true;
    int &res = c[i][pd];

    res = 1e9;

    if (i == n) {
        res = 0;
    } else {
        FO(j,0,3) {
            if (a[i] & (1<<j)) {
                if (j == 2 || j != pd) {
                    res = min(res, go(i+1, j) + (j == 2));
                }
            }
        }
    }

    return res;
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        scanf("%d", a+i);
        a[i] |= 4;
    }

    printf("%d\n", go(0,2));
}