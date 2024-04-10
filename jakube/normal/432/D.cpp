#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> cnt;

int f(int cur) {
    int c = 0;
    for (int next : adj[cur])
        c += f(next);

    cnt[cur] = c;
    return c + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;

    int n = s.size();
    vector<int> prefix(n);
    prefix[0] = 0;

    int border = 0;
    for (int i = 1; i < n; i++) {
        while (border > 0 && s[border] != s[i])
        {
            border = prefix[border-1];
        }

        if (s[border] == s[i])
            border++;

        prefix[i] = border;
    }

    adj.resize(n+1);
    cnt.assign(n+1, 0);

    for (int i = 0; i < n; i++) {
        adj[prefix[i]].push_back(i+1);
    }
    f(0);

    vector<pair<int, int>> res;
    border = s.size();
    while (border > 0) {
        res.push_back({border, cnt[border] + 1});
        border = prefix[border-1];
    }

    cout << res.size() << endl;
    for (auto rit = res.rbegin(); rit != res.rend(); ++rit) {
        cout << rit->first << ' ' << rit->second << '\n';
    }
    cout << flush;


    return 0;
}