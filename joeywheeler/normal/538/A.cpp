#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char b[105];
char c[] = "CODEFORCES";
char s[105];

int main() {
    scanf(" %s", b);
    int n = strlen(b);
    FO(i,0,n) FO(j,i,n+1) {
        FO(k,0,105) s[k] = 0;
        FO(k,0,i) s[k] = b[k];
        FO(k,j,n) s[i+k-j] = b[k];
        if (strcmp(s,c) == 0) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}