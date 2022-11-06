#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

void fail() {
    printf("NO\n");
    exit(0);
}

int n, m;
vector<pii> edge[100001];
bool vis[100001];

int a[100001], y[100001], b[100001];
vector<int> lst[100001];
void dfs(int x) {
    lst[y[x]].push_back(x);
    vis[x] = 1;
    for (auto [i, c] : edge[x]) {
        if (vis[i]) continue;
        a[i] = -a[x];
        y[i] = y[x];
        b[i] = c - b[x];
        dfs(i);
    }
}

bool ch[100001];
int ans[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].emplace_back(b, c);
        edge[b].emplace_back(a, c);
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        a[i] = 1;
        y[i] = i;
        b[i] = 0;
        dfs(i);
    }
    for (int i = 1; i <= n; ++i) {
        for (auto [j, c] : edge[i]) {
            int A = a[i] + a[j];
            int Y = y[i];
            int B = b[i] + b[j];
            //AY + B = c;
            if (A) {
                int v = 2 * (c - B) / A;
                if (ch[Y] && v != ans[Y]) fail();
                ch[Y] = 1;
                ans[Y] = v;
            }
            else if (B != c) fail();
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (lst[i].empty()) continue;
        if (ch[i]) {
            for (int j : lst[i]) {
                if (i == j) continue;
                ans[j] = a[j] * ans[i] + 2 * b[j];
            }
        }
        else {
            vector<int> mid;
            for (int j : lst[i]) {
                mid.push_back(-b[j] / a[j]);
            }
            sort(mid.begin(), mid.end());
            int x = mid[mid.size() / 2];
            for (int j : lst[i]) {
                ans[j] = 2 * (a[j] * x + b[j]);
            }
        }
    }
    printf("YES\n");
    for (int i = 1; i <= n; ++i) {
        if (ans[i] < 0) printf("-");
        printf("%d.%d%c", abs(ans[i]) / 2, 5 * (ans[i] & 1), "\n "[i < n]);
    }
    return 0;
}