#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char s[205];
int n;

int main() {
    scanf("%d %s", &n, s);
    int res = 0;
    FO(i,0,n) {
        int a = 0, b = 0;
        FO(j,i,n) {
            if (s[j] == 'U') a++;
            if (s[j] == 'D') a--;
            if (s[j] == 'L') b++;
            if (s[j] == 'R') b--;
            if (a==0 && b==0) res++;
        }
    }
    printf("%d\n", res);
}