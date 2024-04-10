#include <cstdio>
#include <algorithm>
#include <bitset>
using namespace std;
int n, k;
double p[20];
double sum[1 << 20];
double dp[1 << 20];
int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%lf", p + i);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < (1 << i); j++)
            sum[j + (1 << i)] = sum[j] + p[i];
    
    for(int j = 0; j < n; j++) {
        if(p[j] == 0) {
            printf("0%c", j == n - 1 ? '\n' : ' ');
            continue;
        }
            
        for(int i = 0; i < (1 << n); i++) {
            if(!(i & (1 << j)))
                continue;
            if((int) bitset<32>(i).count() == n - k + 1)
                dp[i] = p[j] / sum[i];
            else if((int) bitset<32>(i).count() > n - k + 1) {
                dp[i] = p[j] / sum[i];
                for(int l = 0; l < n; l++)
                    if((i & (1 << l)) && j != l)
                        dp[i] += p[l] / sum[i] * dp[i & ~(1 << l)];
            }
        }

        printf("%.16f%c", dp[(1 << n) - 1], j == n - 1 ? '\n' : ' ');
    }
}