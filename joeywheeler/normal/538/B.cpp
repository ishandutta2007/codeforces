#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int main() {
    char b[10];
    scanf("%s", b);
    int l = strlen(b);
    int r = 0;
    FO(i,0,l) r = max(r, b[i]-'0');
    printf("%d\n", r);
    FO(Z,0,r) {
        char c[50] = {};
        FO(i,0,l) {
            c[i] = (b[i]-'0'>Z)+'0';
        }
        int x;
        sscanf(c, "%d", &x);
        printf("%d", x);
        if (Z+1 == r) printf("\n");
        else printf(" ");
    }
}