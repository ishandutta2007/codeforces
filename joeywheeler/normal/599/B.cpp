#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int fi[100005];
int f[100005];
int b[100005];

int main() {
    memset(fi,-1,sizeof fi);
    int n,m; scanf("%d%d", &n, &m);
    FO(i,0,n) {
        scanf("%d", f+i);
        if (fi[f[i]] != -1) fi[f[i]] = -2;
        else fi[f[i]] = i;
    }
    FO(i,0,m) {
        scanf("%d", b+i);
        if (fi[b[i]] == -1) {
            printf("Impossible\n");
            return 0;
        }
    }
    FO(i,0,m) {
        if (fi[b[i]] == -2) {
            printf("Ambiguity\n");
            return 0;
        }
    }
    printf("Possible\n");
    FO(i,0,m) {
        printf("%d ", fi[b[i]]+1);
    }
    printf("\n");
    return 0;
}