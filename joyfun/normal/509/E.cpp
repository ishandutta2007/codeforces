#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 500005;

char str[N];

double cal1[N], cal2[N];
int vis[1005];
double ans;

int main() {
    gets(str + 1);
    int n = strlen(str + 1);
    for (int i = 1; i <= n; i++) {
        cal1[i] = cal1[i - 1] + 1.0 / i;
        cal2[i] = cal2[i - 1] + 1.0 / (n - i + 1) * i;
    }
    ans = 0;
    memset(vis, 0, sizeof(vis));
    vis['I'] = vis['E'] = vis['A'] = vis['O'] = vis['U'] = vis['Y'] = 1;
    for (int i = 1; i <= n; i++) {
        if (vis[str[i]]) {
            int c = min(i,  n - i + 1);
            ans += c * (cal1[n - c + 1] - cal1[c]) + c + cal2[c - 1];
        }
    }
    printf("%.10lf\n", ans);
    return 0;
}