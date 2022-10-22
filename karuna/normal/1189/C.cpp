#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, arr[101010], q, tmp, cnt;
pii qry[101010];
pii dp[101010][20];

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &arr[i]);
    scanf("%d", &q);
    for (int i=0; i<q; i++) scanf("%d%d", &qry[i].va, &qry[i].vb);

    for (int j=0; j<20; j++) {
        for (int i=0; i<n; i++) {
            if (j==0) {
                dp[i][j].va = arr[i];
                dp[i][j].vb = 0;
                continue;
            }

            if (i+(1<<j-1)>=n) continue;

            dp[i][j].va = dp[i][j-1].va + dp[i+(1<<j-1)][j-1].va;
            dp[i][j].vb = (dp[i][j].va>=10) + dp[i][j-1].vb + dp[i+(1<<j-1)][j-1].vb;
            dp[i][j].va%=10;
        }

    }

    for (int i=0; i<q; i++) {
        tmp = qry[i].vb-qry[i].va+1;
        cnt=-1;

        while (tmp) {
            tmp/=2;
            ++cnt;
        }

        printf("%d\n", dp[qry[i].va-1][cnt].vb);
    }
}