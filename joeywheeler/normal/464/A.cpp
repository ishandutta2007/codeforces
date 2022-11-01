#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char s[1005];
char r[1005];
int p, n;

bool solve(int i, bool dif) {
    if (i == n) return dif;
    for (r[i] = dif?'a':s[i]; r[i] < 'a'+p; r[i]++) {
        if (i <= 0 || r[i] != r[i-1]) {
            if (i <= 1 || r[i] != r[i-2]) {
                if (solve(i+1,dif||r[i]!=s[i])) return true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d %d", &n, &p); scanf(" %s", s);
    if (solve(0,false)) printf("%s\n", r);
    else printf("NO\n");
}