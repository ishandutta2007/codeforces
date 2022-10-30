#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
char g[105][105];
int c[105];
int a[105];

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf(" %s", g[i]);
    FO(i,0,n) scanf("%d", a+i);
    vector<int> res;
    while (1) {
        bool changed = false;
        FO(i,0,n) {
            if (a[i] == c[i]) {
                changed = true;
                res.push_back(i+1);
                FO(j,0,n) if (g[i][j] == '1') {
                    c[j]++;
                }
            }
        }
        if (!changed) {
            printf("%d\n", sz(res));
            for (int x : res) printf("%d ", x);
            printf("\n");
            return 0;
        }
    }
}