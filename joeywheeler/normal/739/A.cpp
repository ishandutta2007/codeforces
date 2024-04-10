#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m;

int main() {
    scanf("%d %d", &n, &m);
    int x = n;
    FO(i,0,m) {
        int l, r; scanf("%d %d", &l, &r);
        x = min(x, (r-l+1));
    }
    printf("%d\n", x);
    FO(i,0,n) printf("%d%c", i%x, " \n"[i+1==n]);
}