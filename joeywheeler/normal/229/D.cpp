#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int h[100005],dp[100005];
int n;

int main() {
    scanf("%d",&n);
    FO(i,0,n) {
        scanf("%d",h+i+1);
        h[i+1]+=h[i];
    }
    dp[0]=-1;
    FO(i,1,n+1) {
        for (int j=i-1;j>=0;j--) if (dp[j]<=h[i]-h[j]) {
            dp[i]=h[i]-h[j];
            break;
        }
    }
    int r=0;
    int i = n;
    int l = 0;
    while (i > 0) {
        if (l == 0) {
            r++; l = dp[i];
        }
        l -= h[i]-h[i-1];
        i--;
    }
    printf("%d\n", n-r);
}