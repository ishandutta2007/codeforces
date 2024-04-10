#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;

const int N = 505;

int n, k, c[N];
bitset<1005> dp[N][N];
vector<int> ans;

int main() {
    bitset<1005> s;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    for (int i = 0; i <= k; i++) s[i] = 1;
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j - c[i] >= 0)
                dp[i][j] = dp[i - 1][j - c[i]];
            dp[i][j] |= (dp[i - 1][j]|((dp[i - 1][j]<<c[i])&s));
        }
    }
    for (int i = 0; i <= k; i++) {
        if (dp[n][i][k - i]) ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]); printf("\n");
    return 0;
}