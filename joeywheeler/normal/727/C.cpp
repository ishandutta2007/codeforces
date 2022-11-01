#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;


int n;
int a[5005];

int main() {
    scanf("%d", &n);
    FO(i,1,n) {
        printf("? %d %d\n", 1, i+1);
        fflush(stdout);
        scanf("%d", a+i);
    }
    int x;
    printf("? 2 3\n");
    fflush(stdout);
    scanf("%d", &x);
    a[0] = (a[1]+a[2]-x)/2;
    FO(i,1,n) a[i] -= a[0];
    printf("!");
    FO(i,0,n) printf(" %d", a[i]);
    printf("\n");
}