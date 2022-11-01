#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int f[200005];
bool s[200005];
int nb;
int n;

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        scanf("%d", &f[i]);
        f[i]--;
    }
    FO(i,0,n) {
        int x; scanf("%d", &x);
        nb ^= x;
    }
    int nc = 0;
    FO(i,0,n) if (!s[i]) {
        nc++;
        s[i] = true;
        for (int j = f[i]; j != i; j = f[j]) s[j] = true;
    }
    if (nc == 1) nc = 0;
    if (nb == 0) nc++;
    printf("%d\n", nc);
}