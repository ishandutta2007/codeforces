#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100005;
int n;
vector<int> g[N];
int dp[N];
int flag;

void dfs(int u, int p) {
    dp[u] = 1;
    int tmp[6];
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        dfs(v, u);
        tmp[dp[v]]++;

    }
   // printf("%d %d %d %d %d %d ", u, tmp[1], tmp[2], tmp[3], tmp[4], tmp[5]);
    if (tmp[5] > 1) flag = 0;
    else if (tmp[5] == 1) {
        if (tmp[4] || tmp[3] || tmp[2]) flag = 0;
        else if (tmp[1] >= 1) flag = 0;
        else dp[u] = 5;
    } else {
        if (tmp[4] > 1) flag = 0;
        else if (tmp[4] == 1) {
            if (tmp[3] || tmp[2]) flag = 0;
            else if (tmp[1] >= 2) flag = 0;
            else dp[u] = 5;
        } else if (tmp[4] == 0) {
            if(tmp[2] > 2) flag = 0;
            else if (tmp[2] == 2) dp[u] = 4;
            else if (tmp[2] == 1) dp[u] = 2;
            else if (tmp[2] == 0) {
                if (tmp[3] >= 1) dp[u] = 2;
                else if (tmp[3] == 0) {
                    if (tmp[1] > 2) dp[u] = 2;
                    else if (tmp[1] == 2) dp[u] = 3;
                    else if (tmp[1] == 0) dp[u] = 1;
                }
            }
        }
    }
  //  printf("%d\n", dp[u]);
}

int main() {
    scanf("%d", &n);
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    flag = 1;
    int one = 0, two = 0, sb = 0;
    int tmp[6];
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < g[1].size(); i++) {
        int v = g[1][i];
        dfs(v, 1);
        tmp[dp[v]]++;
    }
   //  printf("%d %d %d %d %d %d\n", u, tmp[1], tmp[2], tmp[3], tmp[4], tmp[5]);
    if (tmp[5] > 1) flag = 0;
    else if (tmp[5] == 1) {
        if (tmp[4] || tmp[3] || tmp[2]) flag = 0;
        else if (tmp[1] > 1) flag = 0;
    } else if (tmp[5] == 0) {
        if (tmp[4] > 1) flag = 0;
        else if (tmp[4] == 1) {
            if (tmp[3] || tmp[2]) flag = 0;
            else if (tmp[1] > 2) flag = 0;
        } else if (tmp[4] == 0) {
            if (tmp[2] > 2) flag = 0;
        }
    }
    printf("%s\n", flag ? "Yes" : "No");
    return 0;
}