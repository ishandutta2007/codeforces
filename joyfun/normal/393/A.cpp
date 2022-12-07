#include <stdio.h>
#include <string.h>

char str[105];
int num[26];
int main() {
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++) {
        num[str[i] - 'a']++;
    }
    int ans = 0; num['n' - 'a']--;
    while (num['n' - 'a'] >= 2 && num['e' - 'a'] >= 3 && num['t' - 'a'] >= 1 && num['i' - 'a'] >= 1) {
        num['n' - 'a'] -= 2; num['e' - 'a'] -= 3; num['t' - 'a'] -= 1; num['i' - 'a'] -= 1;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}