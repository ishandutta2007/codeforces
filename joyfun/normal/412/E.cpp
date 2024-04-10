#include <stdio.h>
#include <string.h>

const int N = 1000005;
char str[N];
__int64 ans = 0, l, r, i, j, k; 

bool islettle(char c) {
    if (c >= 'a' && c <= 'z' || (c >= 'A' && c <= 'Z'))
        return true;
    return false;
}
int main() {
    scanf("%s", str);
    int n = strlen(str);
    for (i = 0; i < n; i++) {
        if (str[i] == '@') {
            l = 0;
            for (j = i - 1; j >= 0; j--) {
                if (str[j] == '@' || str[j] == '.') {
                    break;
                }
                if (str[j] == '_' || !islettle(str[j])) continue;
                else l++;
            }
            for (j = i + 1; j < n; j++) {
                if (str[j] == '_' || str[j] == '@') {
                    break;
                }
                if (str[j] == '.') {
                    if (j == i + 1) break;
                    for (k = j + 1; k < n; k++) {
                        if (!islettle(str[k]))
                            break;
                    }
                    ans += (k - j - 1) * l;
                    i = j;
                    break;
                }
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}