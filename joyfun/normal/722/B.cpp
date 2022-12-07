#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 105;

int n, p[N];

char str[105];
char tmp[105], tn;
int vis[555];

int get() {
    int cnt = 0;
    for (int i = 0; i < tn ;i++) {
        if (vis[tmp[i]]) cnt++;
    }
    if (cnt == 0) return 0;
    return cnt;
}

bool judge(int x) {
    int len = strlen(str);
    tn = 0;
    str[len] = ' ';
    int ans = 0;
    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ') {
            ans += get();
            tn = 0;
        } else tmp[tn++] = str[i];
    }
   // printf("%d %d\n", ans, x);
    return ans == x;
}

int main() {
    vis['a'] = vis['e'] = vis['i'] = vis['o'] = vis['u'] = vis['y'] = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    int f = 1;
    getchar();
    for (int i = 0; i < n; i++) {
        gets(str);
        if (!judge(p[i])) f = 0;
    }
    printf("%s\n", f ? "YES" : "NO");
    return 0;
}