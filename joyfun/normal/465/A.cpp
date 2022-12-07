#include <cstdio>
#include <cstring>

int n, num[105], sb[105];
char s[105];

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        num[i] = s[i] - '0';
        sb[i] = num[i];
    }
    num[0]++;
    for (int i = 0; i < n; i++) {
        if (num[i] == 2) {
            num[i] = 0;
            num[i + 1]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (sb[i] != num[i])
            ans++;
    printf("%d\n", ans);
    return 0;
}