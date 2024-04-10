#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int a[2000][10][2];

int main() {
    scanf("%d", &n);
    FO(i,0,10) FO(j,0,2) {
        vector<int> v;
        FO(k,0,n) if (((k>>i)&1) == j) v.push_back(k);
        if (sz(v) == 0) FO(k,0,n) a[k][i][j] = 2e9;
        else {
            printf("%d\n", sz(v));
            for (int x : v) printf("%d ", x+1);
            printf("\n");
            fflush(stdout);
            FO(k,0,n) scanf("%d", &a[k][i][j]);
        }
    }
    printf("-1\n");
    FO(i,0,n) {
        int res = 2e9;
        FO(j,0,10) if (i&(1<<j)) {
            res = min(res, a[i][j][0]);
        } else {
            res = min(res, a[i][j][1]);
        }
        printf("%d ", res);
    }
    printf("\n");
}