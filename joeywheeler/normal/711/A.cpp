#include <bits/stdc++.h>

#define FO(i,a,b) for (int i=a;i<b;i++)

using namespace std;

int n;
char g[1005][6];

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        scanf(" %s", &g[i][0]);
    }
    FO(i,0,n) {
        if (g[i][0] == 'O' && g[i][1] == 'O') {
            g[i][0] = '+';
            g[i][1] = '+';
            goto yes;
        }

        if (g[i][3] == 'O' && g[i][4] == 'O') {
            g[i][3] = '+';
            g[i][4] = '+';
            goto yes;
        }
    }

    printf("NO\n");
    return 0;
yes:
    printf("YES\n");
    FO(i,0,n) printf("%s\n", g[i]);
}