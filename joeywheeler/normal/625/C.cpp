#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, k;
int a[505][505];

int main() {
    scanf("%d%d", &n, &k); k--;
    int c = 1;
    FO(i,0,n) FO(j,0,k) a[i][j] = c++;
    FO(i,0,n) FO(j,k,n) a[i][j] = c++;
    int s = 0;
    FO(i,0,n) s += a[i][k];
    printf("%d\n", s);
    FO(i,0,n) FO(j,0,n) printf("%d%c", a[i][j], " \n"[j+1==n]);
}