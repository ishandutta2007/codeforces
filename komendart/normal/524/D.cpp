#include <bits/stdc++.h>

using namespace std;

int time2int(string s) {
    int h1 = s[0] - '0', h2 = s[1] - '0', m1 = s[3] - '0', m2 = s[4] - '0', s1 = s[6] - '0', s2 = s[7] - '0';
    return (h1 * 10 + h2) * 3600 + (m1 * 10 + m2) * 60 + (s1 * 10 + s2);
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, M, T;
    cin >> n >> M >> T;

    vector<int> times;
    times.reserve(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        times.push_back(time2int(s));
    }

    vector<int> result;
    result.reserve(n);
    set< pair<int, int> > q;
    int max_users = 0, id = 1;
    for (int i = 0; i < n; i++) {
        int t = times[i];
        while (!q.empty() && q.begin()->first + T - 1 < t) {
            q.erase(q.begin());
        }
        if (q.size() == M) {
            result.push_back(q.rbegin()->second);
            int id0 = q.rbegin()->second;
            q.erase(*q.rbegin());
            q.insert(make_pair(t, id0));
        } else {
            result.push_back(id);
            q.insert(make_pair(t, id++));
        }
        max_users = max(max_users, (int) q.size());
    }

    if (max_users < M) {
        cout << "No solution" << '\n';
    } else {
        cout << id - 1 << '\n';
        for (auto i: result) {
            cout << i << '\n';
        }
    }

}