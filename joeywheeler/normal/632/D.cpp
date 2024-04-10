#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m;
int a[1000005];
int c[1000005];
int d[1000005];

int main() {
    scanf("%d%d", &n, &m);
    FO(i,0,n) {
        scanf("%d", a+i);
        if (a[i] <= m) c[a[i]]++;
    }
    FO(i,1,m+1) {
        for (int j = i; j <= m; j += i) d[j] += c[i];
    }
    int mx = 0, mxi = 0;
    FO(i,1,m+1) if (d[i] > mx) {
        mx = d[i];
        mxi = i;
    }
    printf("%d %d\n", max(mxi,1), mx);
    if (mx) {
        FO(i,0,n) {
            if (mxi%a[i] == 0) printf("%d ", i+1);
        }
    }
    printf("\n");
}