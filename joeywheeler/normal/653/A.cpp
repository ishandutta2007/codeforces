#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int c[1005];

int main() {
    int n; scanf("%d", &n);
    FO(i,0,n) {
        int x; scanf("%d", &x);
        c[x]++;
        FO(i,0,1001) if (c[i] && c[i+1] && c[i+2]) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}