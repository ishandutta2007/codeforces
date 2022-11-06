#include <bits/stdc++.h>

using namespace std;

#define int long long
const int INF = 1e17;

struct cmp {
    bool operator ()(const pair<int, int> a, const pair<int, int> b) {
        return a.first > b.first;
    }
};

main() {
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    priority_queue<int, vector<int>, greater<int> > on_server;
    priority_queue< pair<int, int>, vector< pair<int, int> >, cmp> q;

    vector<int> result(n, 0);
    for (int i = 0; i <= n; i++) {
        int s, m;
        if (i < n) {
            cin >> s >> m;
        } else {
            s = INF;
        }
        while (true) {
            bool flag = false;
            int s2 = s;
            if (!on_server.empty() && on_server.top() <= s) {
                s2 = on_server.top();
                on_server.pop();
                flag = true;
            }
            while (on_server.size() < k && !q.empty()) {
                int j = q.top().first, mj = q.top().second;
                q.pop();
                on_server.push(s2 + mj);
                result[j] = s2 + mj;
                flag = true;
            }
            if (!flag) break;
        }
        if (i < n) {
            if (on_server.size() < k) {
                on_server.push(s + m);
                result[i] = s + m;
            } else {
                q.push(make_pair(i, m));
            }
        }
    }

    for (auto i: result) {
        cout << i << '\n';
    }
}