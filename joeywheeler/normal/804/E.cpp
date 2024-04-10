#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
bool act;
bool sd[1005];
int a[1005];

void pswp(int i, int j) {
    if (i > j) swap(i,j);
    printf("%d %d\n", i, j);
}

void swp(int i, int j) {
    i++; j++;

    if (act && !sd[i] && !sd[j]) {
        pswp(n+1, i);
        pswp(i, j);
        pswp(n+1, j);
    } else {
        pswp(i, j);
    }
    sd[i] = sd[j] = true;
}

void doit(int i, int j) {
    swp(i, j+1);
    swp(i+1, j);
    swp(i, j);
    swp(i+1,j+1);
}

int main() {
    scanf("%d", &n);
    if (n%4 > 1) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    if (n % 4 == 1) {
        act = true;
        n--;
    }
    for (int i = 0; i < n; i += 2) swp(i,i+1);
    FO(i,0,n/2) FO(j,i+1,n/2) doit(2*i, 2*j);
}