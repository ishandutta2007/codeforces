#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int a[1000];

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", a+i);
    int l = n-a[0];
    FO(i,0,n) if (i&1) {
        a[i] = (n+a[i]-l)%n;
    } else a[i] = (a[i]+l)%n;
    FO(i,0,n) if (a[i] != i) {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
}