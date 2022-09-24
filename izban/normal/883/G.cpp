#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n, m, s;
    while (scanf("%d%d%d", &n, &m, &s) == 3) {
        s--;
        vector<pair<pair<int, int>, int> > ed(m);
        vector<vector<int> > e(n);
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &ed[i].second, &ed[i].first.first, &ed[i].first.second);
            ed[i].first.first--;
            ed[i].first.second--;
            e[ed[i].first.first].push_back(i);
            if (ed[i].second == 2) e[ed[i].first.second].push_back(i);
        }
        vector<int> num(m, -1);
        int cur = 0;
        for (int i = 0; i < m; i++) {
            if (ed[i].second == 2) {
                num[i] = cur++;
            }
        }

        auto solve1 = [&]() {
            queue<int> q;
            vector<char> was(n);
            string ans = string(cur, '?');
            q.push(s);
            was[s] = 1;
            int cnt = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                cnt++;
                for (int id : e[v]) {
                    int to = ed[id].first.first ^ ed[id].first.second ^ v;
                    if (ed[id].second == 2 && ans[num[id]] == '?') {
                        if (ed[id].first.first == v) ans[num[id]] = '+';
                        else ans[num[id]] = '-';
                    }
                    if (!was[to]) {
                        was[to] = 1;
                        q.push(to);
                    }
                }
            }
            for (int i = 0; i < cur; i++) if (ans[i] == '?') ans[i] = '+';
            return make_pair(cnt, ans);
        };

        auto solve2 = [&]() {
            queue<int> q;
            vector<char> was(n);
            string ans = string(cur, '?');
            q.push(s);
            was[s] = 1;
            int cnt = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                cnt++;
                for (int id : e[v]) {
                    int to = ed[id].first.first ^ ed[id].first.second ^ v;
                    if (ed[id].second == 2) {
                        if (ed[id].first.first == v) ans[num[id]] = '-';
                        else ans[num[id]] = '+';
                    } else {
                        if (!was[to]) {
                            was[to] = 1;
                            q.push(to);
                        }
                    }
                }
            }
            for (int i = 0; i < cur; i++) if (ans[i] == '?') ans[i] = '+';
            return make_pair(cnt, ans);
        };

        auto o1 = solve1();
        auto o2 = solve2();
        cout << o1.first << endl << o1.second << endl << o2.first << endl << o2.second << endl;
    }
    
    return 0;
}