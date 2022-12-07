#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 300005;

char s[N];
long long cnt[N][4];

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int c = s[i] - '0';
        cnt[i][c % 4]++;
        for (int j = 0; j < 4; j++) {
            cnt[i][(j * 10 + c) % 4] += cnt[i - 1][j];
        }
        ans += cnt[i][0];
    }
    printf("%lld\n", ans);
    return 0;
}