#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

bool vis[N];

int counter, m, n;
int minR[N], in[N];

std::string s, a, b;

std::pair<int, int> r[N];

std::vector<int> essay;
std::vector<int> adj[N];

std::map<std::string, int> Ind;

std::priority_queue<std::pair<std::pair<int, int>, int> > q;

int getInd(string s) {
    string t;
    for (int i = 0; i < s.size(); ++i) {
        t.push_back(s[i] >= 'A' && s[i] <= 'Z' ? s[i] + 'a' - 'A' : s[i]);
    }
    if (Ind[t]) return Ind[t];
    Ind[t] = ++counter;
    int rn = 0;
    for (int i = 0; i < s.size(); ++i) rn += t[i] == 'r';
    r[Ind[t]] = std::make_pair(-rn, -t.size());
    q.push(std::make_pair(std::make_pair(-rn, -t.size()), Ind[t]));
    return Ind[t];
}

int main() {
    std::cin >> m;
    for (int i = 0; i < m; ++i) std::cin >> s, essay.push_back(getInd(s));
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a >> b, adj[getInd(b)].push_back(getInd(a));
    }
    while (!q.empty()) {
        int cur = q.top().second;
        q.pop();
        if (vis[cur]) continue;
        vis[cur] = 1;
        for (int j = 0; j < adj[cur].size(); ++j) {
            int to = adj[cur][j];
            if (r[cur] > r[to]) {
                r[to] = r[cur];
                q.push(std::make_pair(r[to], to));
            }
        }
    }
    long long ansr = 0, anslen = 0;
    for (int i = 0; i < essay.size(); ++i) {
        ansr -= r[essay[i]].first;
        anslen -= r[essay[i]].second;
    }
    std::cout << ansr << ' ' << anslen << '\n';
    return 0;
}