#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char s[1005][6];
int n;

int main() {
    scanf("%d", &n);
    int k = 6;
    FO(i,0,n) {
        scanf(" %s", s[i]);
        FO(j,0,i) {
            int r = 0;
            FO(t,0,6) r += s[j][t] != s[i][t];
            k = min(k,(r+1)/2-1);
        }
    }
    printf("%d\n", k);
}