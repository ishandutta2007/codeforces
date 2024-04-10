#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, q;
char str[300005];
int l[300005], r[300005];

int main() {
    while (~scanf("%d%d", &n, &q)) {
        scanf("%s", str + 1);
        int len = strlen(str + 1);
        int cnt = 0;
        for (int i = 1; i <= len; i++) {
            l[i] = l[i - 1];
            if (str[i] == '.') {
                cnt++;
                if (cnt > 1) l[i]++;
            } else {
                cnt = 0;
            }
        }
        cnt = 0;
        for (int i = len; i >= 1; i--) {
            r[i] = r[i + 1];
            if (str[i] == '.') {
                cnt++;
                if (cnt > 1) r[i]++;
            } else {
                cnt = 0;
            }
        }
        int v;
        char op[2];
        int ans = l[len];
        while (q--) {
            scanf("%d%s", &v, op);
            if (op[0] == '.') {
                if (str[v] != '.') {
                    if (str[v - 1] == '.' && str[v + 1] == '.') ans += 2;
                    else if (str[v - 1] == '.') ans++;
                    else if (str[v + 1] == '.') ans++;
                }
            }
            else {
                if (str[v] == '.') {
                    if (str[v - 1] == '.' && str[v + 1] == '.') ans -= 2;
                    else if (str[v - 1] == '.') ans--;
                    else if (str[v + 1] == '.') ans--;
                }
            }
            str[v] = op[0];
            printf("%d\n", ans);
        }
    }
    return 0;
}