#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 205;
int n;
char str[N];

int main() {
    scanf("%d", &n);
    scanf("%s", str + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int a = 0, b = 0;
        for (int j = i; j <= n; j++) {
            if (str[j] == 'U') a++;
            if (str[j] == 'D') a--;
            if (str[j] == 'L') b++;
            if (str[j] == 'R') b--;
            if (a == 0 && b == 0) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}