#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int N = 100005;

int n;
char str[N * 8];
int ch[N * 8][26];
int sz;
vector<int> val[2][N * 8];
int vis[2][N];

int match[N];

void insert(int tp, int id) {
    int n = strlen(str);
    int u = 0;
    val[tp][u].push_back(id);
    for (int i = 0; i < n; i++) {
        int c = str[i] - 'a';
        if (!ch[u][c]) {
            if (tp == 1) return;
            ch[u][c] = sz++;
        }
        u = ch[u][c];
        val[tp][u].push_back(id);
    }
}

int tot;

void dfs(int u, int d) {
    for (int i = 0; i < 26; i++) {
        if (ch[u][i] && val[0][ch[u][i]].size() && val[1][ch[u][i]].size()) {
            dfs(ch[u][i], d + 1);
        }
    }
    int i = 0, j = 0;
    int sz0 = val[0][u].size();
    int sz1 = val[1][u].size();
    while (i < sz0 && j < sz1) {
        while (i < sz0 && vis[0][val[0][u][i]]) i++;
        while (j < sz1 && vis[1][val[1][u][j]]) j++;
        if (i == sz0 || j == sz1) break;
        int a = val[0][u][i];
        int b = val[1][u][j];
        vis[0][a] = vis[1][b] = 1;
        tot += d;
        match[a] = b;
    }
}

int main() {
    scanf("%d", &n);
    sz = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%s", str);
        insert(0, i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%s", str);
        insert(1, i);
    }
    dfs(0, 0);
    printf("%d\n", tot);
    for (int i = 1; i <= n; i++)
        printf("%d %d\n", i, match[i]);
    return 0;
}