#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int c[100000];

int main() {
    int n; scanf("%d", &n);
    n = (1<<(n+1))-1;
    FO(i,2,n+1) {
        scanf("%d", &c[i]);
    }
    int res = 0;
    for (int i = n; i >= 1; i--) {
        int l = c[2*i], r = c[2*i+1];
        res += max(l,r) - min(l,r);
        c[i] += max(l,r);
    }
    printf("%d\n", res);
}