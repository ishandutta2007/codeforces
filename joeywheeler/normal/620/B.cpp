#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int m[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int g(int x) {
    if (x == 0) return m[0];
    else {
        int r = 0;
        while (x) {
            r += m[x%10];
            x /= 10;
        }
        return r;
    }
}

int main() {
    int a, b; scanf("%d%d", &a, &b);
    int r = 0;
    FO(i,a,b+1) r += g(i);
    printf("%d\n", r);
}