#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 15;
int n;
char str[N];
int x[N], y[N];

int main() {
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            x[(i - 1) * 3 + j] = i;
            y[(i - 1) * 3 + j] = j;
        }
    }
    scanf("%d", &n);
    x[0] = 4; y[0] = 2;
    scanf("%s", str);
    int len = strlen(str);
    int xma = -1, yma = -1;
    int xmi = 100, ymi = 100;
    int f = 0, f2 = 0;
    for (int i = 0; i < len; i++) {
        xma = max(xma, x[str[i] - '0']);
        xmi = min(xmi, x[str[i] - '0']);
        yma = max(yma, y[str[i] - '0']);
        ymi = min(ymi, y[str[i] - '0']);
        if (str[i] == '7' || str[i] == '9') f = 1;
        if (str[i] == '0') f2 = 1;
    }
    int dx = xma - xmi + 1;
    int dy = yma - ymi + 1;
    if (dx == 4 || (!f2 && dx == 3 && dy == 3 && f)) printf("YES\n");
    else printf("NO\n");
    return 0;
}