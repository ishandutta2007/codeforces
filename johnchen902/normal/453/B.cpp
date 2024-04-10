#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int dp[100][1 << 16];
int bac[100][1 << 16];
int masks[59];

int main(){
    for(int i = 1; i <= 58; i++)
        for(int j = 0; j < 16; j++)
            if(i % primes[j] == 0)
                masks[i] |= 1 << j;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        for(int j = 0; j < 1 << 16; j++)
            dp[i][j] = 123456789;
        for(int j = 0; j < 1 << 16; j++)
            for(int k = 1; k <= 58; k++)
                if((j & masks[k]) == 0)
                    if(dp[i][j | masks[k]] > dp[i - 1][j] + abs(a - k)) {
                        dp[i][j | masks[k]] = dp[i - 1][j] + abs(a - k);
                        bac[i][j | masks[k]] = k;
                    }
    }
    vector<int> ans;

    for(int i = n - 1, m = min_element(dp[i], dp[i] + (1 << 16)) - dp[i];
        ~i; m &= ~masks[bac[i][m]], i--)
        ans.push_back(bac[i][m]);
    for(int i = 0; i < n; i++)
        printf("%d%c", ans[n - 1 - i], i == n - 1 ? '\n' : ' ');
}