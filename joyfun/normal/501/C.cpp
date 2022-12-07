#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

const int N = (1<<16) + 5;
int n, du[N], s[N];

vector<pii> ans;

int main() {
    scanf("%d", &n);
    queue<int> Q;
    for (int i = 0; i < n; i++) {
    scanf("%d%d", &du[i], &s[i]);
    if (du[i] == 1) Q.push(i);
    }
    while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    if (du[u] != 1) continue;
    ans.push_back(make_pair(u, s[u]));
    s[s[u]] ^= u;
    du[s[u]]--;
    if (du[s[u]] == 1) Q.push(s[u]);
    }
    int tot = ans.size();
    printf("%d\n", tot);
    for (int i = 0; i < tot; i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}