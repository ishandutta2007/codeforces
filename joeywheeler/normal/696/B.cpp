#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int p[100005];
int ss[100005];
int pl[100005];
int n;

int main() {
    scanf("%d", &n);
    pl[1] = 1;
    FO(i,2,n+1) {
        scanf("%d", p+i);
        pl[i] = pl[p[i]]+1;
    }
    for (int i = n; i >= 1; i--) {
        ss[i]++;
        ss[p[i]] += ss[i];
    }
    FO(i,1,n+1) {
        printf("%.4lf ", 0.5 * pl[i] + 0.5 * (n - ss[i]) + 0.5);
    }
    printf("\n");
}