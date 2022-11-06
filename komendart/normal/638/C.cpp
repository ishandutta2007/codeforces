#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

vector<int> number[maxn];
vector<int> graph[maxn];
vector<int> answer[maxn];

void dfs(int v, int p=-1, int c=maxn) {
    int it = 0;
    for (int i = 0; i < graph[v].size(); i++) {
        int u = graph[v][i];
        if (u != p) {
            int nc = (it < c) ? it: it + 1;
            answer[nc].push_back(number[v][i]);
            dfs(u, v, nc);
            it++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        number[a].push_back(i + 1);
        number[b].push_back(i + 1);
    }

    dfs(0);

    int ans_size = 0;
    for (int i = 0; i < n; i++) {
        ans_size = max(ans_size, (int) graph[i].size());
    }

    cout << ans_size << '\n';
    for (int i = 0; i < ans_size; i++) {
        cout << answer[i].size() << ' ';
        for (auto j: answer[i]) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}