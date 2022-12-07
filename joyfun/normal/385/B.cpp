#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char str[5005];
__int64 i, j, x, y;
__int64 ans = 0;

int main() {
    scanf("%s", str);
    __int64 len = strlen(str);
    x = 0;
    for (i = 0; i < len - 3; i++) {
        if (str[i] == 'b' && str[i + 1] == 'e' && str[i + 2] == 'a' && str[i + 3] == 'r') {
            ans += (i + 1) * (len - i - 3) - (len - i - 3) * x;
            x = i + 1;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}