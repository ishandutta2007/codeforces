#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
char s[100005];

bool x[256];

int main() {
    scanf("%d", &n);
    if (n > 26) {
        printf("-1\n");
    } else {
        scanf(" %s", s);
        int res = 0;
        FO(i,0,n) if (x[s[i]]) res++;
        else x[s[i]] = true;
        printf("%d\n", res);
    }
}