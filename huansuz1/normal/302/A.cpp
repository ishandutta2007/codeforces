#include <bits/stdc++.h>

#define llong long long
using namespace std;

const int INF = (int) 1e9 + 7;
const int MXN = (int) 1e5 + 7;

int n, m, a, b;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        if (x == 1) a++;
        else b++;
    }
    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        if ((r - l) & 1) {
            int h = (r - l + 1) / 2;
            if (a >= h && b >= h) puts("1");
            else puts("0");
        }
        else puts("0");
    }
    return 0;
}