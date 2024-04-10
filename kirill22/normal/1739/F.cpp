#include "bits/stdc++.h"

using namespace std;

int A = 12;
vector<vector<int>> go;
vector<int> suf, term;

void build() {
    go.push_back(vector<int> (A));
    suf.push_back(0);
    term.push_back(0);
}

void add(string s, int i) {
    int v = 0;
    for (auto c : s) {
        if (go[v][c - 'a'] == 0) {
            go[v][c - 'a'] = go.size();
            go.push_back(vector<int> (A));
            suf.push_back(0);
            term.push_back(0);
        }
        v = go[v][c - 'a'];
    }
    term[v] += i;
}

void bfs() {
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (int i = 0; i < A; i++) {
            if (go[v][i] == 0) {
                go[v][i] = go[suf[v]][i];
            }
            else {
                if (v) {
                    suf[go[v][i]] = go[suf[v]][i];
                    term[go[v][i]] += term[suf[go[v][i]]];
                }
                q.push(go[v][i]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    map<string, int> T;
    for (int i = 0; i < n; i++) {
        int c;
        string s;
        cin >> c >> s;
        string t = (string) "" + s[0];
        int uk = 0;
        for (int j = 1; j < (int) s.size(); j++) {
            if (uk + 1 < (int) t.size() && t[uk + 1] == s[j]) {
                uk++;
            } else if (uk - 1 >= 0 && t[uk - 1] == s[j]) {
                uk--;
            } else if (uk == 0) {
                t.insert(t.begin(), s[j]);
            } else if (uk + 1 == (int) t.size()) {
                t.push_back(s[j]);
                uk++;
            } else {
                c = -1;
                break;
            }
        }
        set<char> st(t.begin(), t.end());
        if ((int) st.size() != (int) t.size() || c == -1) {
            continue;
        }
        string t2 = t;
        reverse(t.begin(), t.end());
        if ((int) t.size() <= 1) {
            continue;
        }
        T[min(t, t2)] += c;
    }
    build();
    for (auto [S, x] : T) {
        auto s = S;
        add(s, x);
        reverse(s.begin(), s.end());
        add(s, x);
    }
    bfs();
    int N = (int) go.size();
    //debug(N, term);
    vector<vector<int>> dp(N, vector<int> (1 << 12, -1));
    vector<vector<pair<int, int>>> pr(N, vector<pair<int, int>> (1 << 12));
    dp[0][0] = 0;
    for (int msk = 0; msk < (1 << 12); msk++) {
        for (int i = 0; i < N; i++) {
            if (dp[i][msk] != -1) {
                for (int j = 0; j < 12; j++) {
                    if (!(msk >> j & 1)) {
                        int v = go[i][j], nmsk = msk + (1 << j);
                        int res = dp[i][msk] + term[v];
                        if (dp[v][nmsk] < res) {
                            dp[v][nmsk] = res;
                            pr[v][nmsk] = {i, msk};
                        }
                    }
                }
            }
        }
    }
    int ans = 0, v;
    string res = "abcdefghijkl";
    for (int i = 0; i < N; i++) {
        if (dp[i].back() > ans) {
            ans = dp[i].back();
            v = i;
        }
    }
    if (ans > 0) {
        res = "";
        int msk = (1 << 12) - 1;
        while (msk) {
            auto p = pr[v][msk];
            int j = 0;
            while ((p.second >> j & 1) == 1 || (msk >> j & 1) == 0) {
                j++;
            }
            res.push_back('a' + j);
            v = p.first;
            msk = p.second;
            //debug(msk, v, dp[v][msk]);
        }
    }
    cerr << ans << endl;
    cout << res;
}