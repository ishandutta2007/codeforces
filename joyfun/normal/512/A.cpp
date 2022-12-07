#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using namespace std;

int n, flag = 0, du[30];
char str[105][105];
vector<int> g[30];
int out[30], on = 0;

void gao() {
    queue<int> Q;
    for (int i = 0; i < 26; i++)
        if (!du[i]) Q.push(i);
    while (!Q.empty()){
        int u = Q.front();
        out[on++] = u;
        Q.pop();
        for (int j = 0; j < g[u].size(); j++) {
            int v = g[u][j];
            du[v]--;
            if (du[v] == 0) Q.push(v);
        }
    }
    for (int i = 0; i < 26; i++)
        if (du[i]) flag = 1;
    if (flag) printf("Impossible\n");
    else {
        for (int i = 0; i < on; i++)
            printf("%c", out[i] + 'a');
        printf("\n");
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
        if (i == 0) continue;
        int len1 = strlen(str[i - 1]);
        int len2 = strlen(str[i]);
        int u1 = 0, u2 = 0;
        while (u1 != len1 && u2 != len2) {
            if (str[i - 1][u1] == str[i][u2]) {
                u1++; u2++;
            } else {
                g[str[i - 1][u1] - 'a'].push_back(str[i][u2] - 'a');
                du[str[i][u2] - 'a']++;
                break;
            }
        }
        if (u2 == len2 && len1 > len2) flag = 1;
    }
    gao();
    return 0;
}