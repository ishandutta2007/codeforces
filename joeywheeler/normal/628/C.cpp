#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, k;
char s[100005];
char t[100005];

int main() {
    scanf("%d%d", &n, &k);
    scanf(" %s", s);
    FO(i,0,n) {
        int c = s[i];
        int d = max(c-'a','z'-c);
        d = min(d,k);
        if ('a' <= c-d) t[i] = c-d;
        else t[i] = c+d;
        k -= d;
    }
    if (k == 0) {
        printf("%s\n", t);
    } else printf("-1\n");
}