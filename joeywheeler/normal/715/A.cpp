#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    printf("2\n");
    for (long long i = 2; i <= n; i++) {
        printf("%lld\n", (i+1)*(i+1)*i - (i-1));
    }
}