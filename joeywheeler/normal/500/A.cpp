#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int main() {
    int n, t;
    scanf("%d%d", &n,&t);
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        if (i==t) {
            if (cur == t) printf("YES\n");
            else printf("NO\n");
            return 0;
        }
        int a; scanf("%d", &a);
        if (cur == i) cur += a;
    }
}