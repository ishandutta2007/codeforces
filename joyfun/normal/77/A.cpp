#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

const int N = 10;

map<string, int> h;

const char s[7][100] = {
    "Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"
};

int g[N][N];
int x[3];
int p[7];

pair<int ,int> ans;

void gao() {
    int aa = 0, bb = 0;
    vector<int> c[3];
    for (int i = 0; i < 7; i++)
        c[p[i]].push_back(i);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < c[i].size(); j++) {
            for (int k = 0; k < c[i].size(); k++) {
                bb += g[c[i][j]][c[i][k]];
            }
        }
    }

    for (int i = 0; i < 3; i++) if (c[i].size() == 0) return;
    int Max = 0, Min = 2000000000;
    for (int i = 0; i < 3; i++) {
        Max = max(Max, x[i] / (int)c[i].size());
        Min = min(Min, x[i] / (int)c[i].size());
    }
    aa = Max - Min;
    ans = min(ans, make_pair(aa, -bb));
}

void dfs(int u) {
    if (u == 7) {
        gao();
        return;
    }
    for (int i = 0; i < 3; i++) {
        p[u] = i;
        dfs(u + 1);
    }
}

int main() {
    for (int i = 0; i < 7; i++) h[s[i]] = i;
    int n;
    int u, v;
    scanf("%d", &n);
    char a[100], b[100], c[100];
    while (n--) {
        scanf("%s%s%s", a, b, c);
        g[h[a]][h[c]]++;
    }
    for (int i = 0; i < 3; i++) scanf("%d", &x[i]);
    ans.first = 2000000001;
    dfs(0);
    printf("%d %d\n", ans.first, -ans.second);
    return 0;
}