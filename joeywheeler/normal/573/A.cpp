#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int a[100005];

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        scanf("%d", &a[i]);
        while (a[i]%2 == 0) a[i] /= 2;
        while (a[i]%3 == 0) a[i] /= 3;
    }
    FO(i,0,n-1) if (a[i] != a[i+1]) {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
}