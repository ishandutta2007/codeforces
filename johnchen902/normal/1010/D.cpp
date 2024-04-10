#include <cstdio>
#include <numeric>
using namespace std;

struct Node {
    char type[4];
    int u, v;

    int val, ans;
} nodes[1000000];

void dfs1(int i) {
    int u = nodes[i].u;
    int v = nodes[i].v;

    if (u >= 0)
        dfs1(u);
    if (v >= 0)
        dfs1(v);

    switch (nodes[i].type[0]) {
    case 'A':
        nodes[i].val = nodes[u].val & nodes[v].val;
        break;
    case 'O':
        nodes[i].val = nodes[u].val | nodes[v].val;
        break;
    case 'X':
        nodes[i].val = nodes[u].val ^ nodes[v].val;
        break;
    case 'N':
        nodes[i].val = !nodes[u].val;
        break;
    }
}

void dfs2(int i, int val1, int val0) {
    int u = nodes[i].u, v = nodes[i].v;

    switch (nodes[i].type[0]) {
    case 'A':
        dfs2(u, nodes[v].val ? val1 : val0, val0);
        dfs2(v, nodes[u].val ? val1 : val0, val0);
        break;
    case 'O':
        dfs2(u, val1, nodes[v].val ? val1 : val0);
        dfs2(v, val1, nodes[u].val ? val1 : val0);
        break;
    case 'X':
        dfs2(u, nodes[v].val ? val0 : val1,
                nodes[v].val ? val1 : val0);
        dfs2(v, nodes[u].val ? val0 : val1,
                nodes[u].val ? val1 : val0);
        break;
    case 'N':
        dfs2(u, val0, val1);
        break;
    case 'I':
        nodes[i].ans = (!nodes[i].val) ? val1 : val0;
        break;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", nodes[i].type);
        switch (nodes[i].type[0]) {
        case 'A':
        case 'O':
        case 'X':
            scanf("%d%d", &nodes[i].u, &nodes[i].v);
            nodes[i].u--;
            nodes[i].v--;
            break;
        case 'N':
            scanf("%d", &nodes[i].u);
            nodes[i].u--;
            nodes[i].v = -1;
            break;
        case 'I':
            scanf("%d", &nodes[i].val);
            nodes[i].u = nodes[i].v = -1;
            break;
        }
    }

    dfs1(0);
    dfs2(0, 1, 0);

    for (int i = 0; i < n; i++)
        if (nodes[i].type[0] == 'I')
            putchar('0' + nodes[i].ans);
    putchar('\n');
}