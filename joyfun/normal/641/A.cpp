#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

int n;
char str[N];
int d[N], vis[N];

int main() {
    scanf("%d", &n);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
    int s = 1;
    int flag = 1;
    while (1) {
        if (s > n || s < 1) break;
        if (vis[s]) {
            flag = 0;
            break;
        }
        vis[s] = 1;
        if (str[s] == '>') s += d[s];
        else s -= d[s];
    }
    printf("%s\n", flag ? "FINITE" : "INFINITE");
    return 0;
}