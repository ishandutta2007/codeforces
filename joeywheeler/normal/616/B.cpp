#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m;

int main() {
    scanf("%d %d", &n, &m);
    int res = -1;
    FO(i,0,n) {
        int t = 1e9+10;
        FO(j,0,m) {
            int x; scanf("%d", &x);
            t = min(t,x);
        }
        res = max(res, t);
    }
    printf("%d\n", res);
}