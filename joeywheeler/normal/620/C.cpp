#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

set<int> s;
int l;

int g[300005][2];

int main() {
    int n; scanf("%d", &n);
    int k = 0;
    l = 1;
    FO(i,1,n+1) {
        int x;
        scanf("%d", &x);
        if (s.count(x)) {
            g[k][0] = l;
            g[k][1] = i;
            l = i+1;
            k++;
            s.clear();
        } else s.insert(x);
    }
    if (l == 1) {
        printf("-1\n");
        return 0;
    }
    if (l <= n) {
        g[k-1][1] = n;
    }
    printf("%d\n", k);
    FO(i,0,k) printf("%d %d\n", g[i][0], g[i][1]);
}