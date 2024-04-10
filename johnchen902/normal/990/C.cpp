#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

char buf[300001];

int sum[300000], low[300000];

int main() {
    int n;
    scanf("%d", &n);

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        scanf("%s", buf);
        
        for (int j = 0; buf[j]; j++)
            if (buf[j] == '(') {
                sum[i]++;
            } else { // buf[j] == ')'
                sum[i]--;
                low[i] = min(low[i], sum[i]);
            }

        if (low[i] >= sum[i])
            mp[sum[i]]++;
    }

    long long int ans = 0;
    for (int i = 0; i < n; i++)
        if (low[i] >= 0)
            ans += mp[-sum[i]];
    printf("%lld\n", ans);
}