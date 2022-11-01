#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int nf[1005];

int main() {
    for (int i = 2; i < 1005; i++) if (!nf[i]) {
        for (int j = i; j < 1005; j += i) nf[j]++;
    }
    int n; scanf("%d", &n);
    int k = 0;
    FO(i,0,n+1) if (nf[i] == 1) k++;
    printf("%d\n", k);
    FO(i,0,n+1) if (nf[i] == 1) printf("%d%c", i, " \n"[--k==0]);
}