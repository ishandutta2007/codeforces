#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 500005;

int n, m, p;
char str[N], op[N];
int st[N], top;
int g[N];

struct Node {
    int pre, suf, id;
} node[N];

int main() {
    scanf("%d%d%d", &n, &m, &p);
    scanf("%s", str + 1);
    scanf("%s", op + 1);
    node[0].suf = 1;
    for (int i = 1; i <= n; i++) {
        node[i].id = i;
        node[i].pre = i - 1;
        node[i].suf = i + 1;
        if (str[i] == '(') st[top++] = i;
        else {
            top--;
            g[i] = st[top];
            g[st[top]] = i;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (op[i] == 'L') {
            if (node[p].pre != 0)
                p = node[p].pre;
        } else if (op[i] == 'R') {
            if (node[p].suf != n + 1)
                p = node[p].suf;
        } else {
            int l = g[node[p].id];
            int r = node[p].id;
            if (l > r) swap(l, r);
            l = node[l].pre;
            r = node[r].suf;
            node[l].suf = r;
            node[r].pre = l;
            p = r;
            if (p == n + 1) p = node[p].pre;
        }
    }
    int s = node[0].suf;
    while (s != n + 1) {
        printf("%c", str[s]);
        s = node[s].suf;
    }
    printf("\n");
    return 0;
}