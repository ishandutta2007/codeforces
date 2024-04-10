#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int p = 1e9+7;
ll dp[2020][1010];
int main() {
    int n;
    scanf("%d", &n);

    dp[0][0] = 1;
    dp[1][1] = 1;

    for (int i=2; i<=2*n; i++) {
        if (i%2==0) dp[i][0] = dp[i-1][1];
        for (int j=1; j<=n; j++) {
            if (i%2==0 && j%2==0) dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1])%p;
            if (i%2==1 && j%2==1) dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1])%p;
        }
    }

//    for (int i=0; i<=2*n; i++) {
//        for (int j=0; j<=n; j++) {
//            printf("%lld ", dp[i][j]);
//        }
//        printf("\n");
//    }

    ll cnt = 0;
    for (int i=0; i<=n; i++) {
        if (i%2==1) {
            for (int j=0; j<=i; j++) cnt = (cnt+dp[i][j])%p;
        }
    }

    for (int i=n+1; i<2*n; i++) {
        if (i%2==1) {
            for (int j=0; j<=2*n-i; j++) cnt = (cnt+dp[i][j])%p;
        }
    }

    printf("%lld", cnt);
}