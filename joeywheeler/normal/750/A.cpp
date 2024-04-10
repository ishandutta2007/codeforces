#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, k;

int main() {
    scanf("%d %d", &n, &k);
    k = 240-k;
    int res = 0;
    FO(i,1,n+1) if (k >= 5*i) {
        k -= 5*i;
        res = i;
    }
    printf("%d\n", res);
}