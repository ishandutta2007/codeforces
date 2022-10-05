#include <cstdio>
#include <algorithm>
using namespace std;

struct beacon{
    int x;
    int power;
    bool operator<(const beacon &a) const {
        return x < a.x;
    }
}a[100010];

int n, q, w, xlist[100010], dp[100010];
int ans;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &q, &w);
        a[i] = {q, w};
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) xlist[i] = a[i].x;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[lower_bound(xlist + 1, xlist + 1 + n, a[i].x - a[i].power) - xlist - 1] + 1;
        ans = max(ans, dp[i]);
    }
    printf("%d", n - ans);
}