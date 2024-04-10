#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> edge[100001];
int sz[100001];

void dfs(int x, int p) {
    sz[x] = 1;
    for (int i : edge[x]) {
        if (i == p) continue;
        dfs(i, x);
        sz[x] += sz[i];
    }
}

vector<int> lst;
long long sum = 0;
void dfs2(int x, int p, int d = 0) {
    lst.push_back(x);
    sum += d;
    for (int i : edge[x]) {
        if (i == p) continue;
        dfs2(i, x, d + 1);
    }
}

int ans[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1, 0);
    int x = 1;
    for (int p = 0, loop = 1; loop; ) {
        loop = 0;
        for (int i : edge[x]) {
            if (i == p) continue;
            if (sz[i] * 2 > n) {
                p = x;
                x = i;
                loop = 1;
                break;
            }
        }
    }
    dfs2(x, 0);
    for (int i = 0; i < n; ++i) {
        ans[lst[i]] = lst[(i + n / 2) % n];
    }
    printf("%lld\n", sum * 2);
    for (int i = 1; i <= n; ++i) {
        printf("%d%c", ans[i], "\n "[i < n]);
    }
    return 0;
}