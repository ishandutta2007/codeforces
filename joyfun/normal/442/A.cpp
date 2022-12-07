#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const char c[15] = {'1', '2', '3', '4', '5', 'B', 'Y', 'W', 'G', 'R'};

int n, vis[105][2];
char card[105][5];

int bitcount(int x) {
    if (x == 0) return 0;
    return bitcount(x>>1) + (x&1);
}

bool judge(int s) {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < 10; i++) {
    if (s&(1<<i)) {
        for (int j = 0; j < n; j++) {
        for (int k = 0; k < 2; k++) {
            if (card[j][k] == c[i])
            vis[j][k] = 1;
        }
        }
    }
    }
    for (int i = 0; i < n; i++) {
    if (vis[i][0] && vis[i][1]) continue;
    for (int j = i + 1; j < n; j++) {
        if (strcmp(card[i], card[j]) == 0) continue;
        if (vis[j][0] && vis[j][1]) continue;
        if (!vis[i][0] && !vis[i][1] && !vis[j][0] && !vis[j][1]) return false;
        if (!vis[i][0] && !vis[j][0] && card[i][1] == card[j][1]) return false;
        if (!vis[i][1] && !vis[j][1] && card[i][0] == card[j][0]) return false;
    }
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    scanf("%s", card[i]);
    int ans = 10;
    for (int i = 0; i < (1<<10); i++) { 
    if (judge(i)) {
        ans = min(ans, bitcount(i));
    }
    }
    printf("%d\n", ans);
    return 0;
}