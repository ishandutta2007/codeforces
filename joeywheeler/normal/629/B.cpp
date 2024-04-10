#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int b[420], g[420];
int n;

int main() {
    scanf("%d", &n);
    int res = 0;
    FO(z,0,n) {
        char t; int i, j; scanf(" %c %d %d", &t, &i, &j);
        j++;
        if (t == 'F') {
            FO(k,i,j) g[k]++;
        } else {
            FO(k,i,j) b[k]++;
        }
    }
    FO(i,0,420) res = max(res, min(b[i],g[i]));
    printf("%d\n", 2*res);
}