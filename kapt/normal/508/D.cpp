#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
vector<int> g[MAXN];
map<pair<char, char>, int> num;
pair<char, char> str[MAXN];
unordered_map<int, int> used[MAXN];
vector<int> ans;
int now[MAXN];

void inline_dfs(int u) {
    vector<int> st;
    st.push_back(u);
    while (!st.empty()) {
        int v = st.back();
        // cout << v << endl;
        while (now[v] < g[v].size() && used[v][g[v][now[v]]] == 0) {
            now[v]++;
        }
        if (now[v] == g[v].size()) {
            ans.push_back(v);
            st.pop_back();
        } else {
            st.push_back(g[v][now[v]]);
            used[v][g[v][now[v]]]--;
        }
    }
}

int degin[MAXN], degout[MAXN];

main() {
    int n;
    cin >> n;
    int cnt = 1;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        char a = s[0], b = s[1], c = s[2];
        if (num[{a, b}] == 0) {
            str[cnt] = {a, b};
            num[{a, b}] = cnt++;
        }
        if (num[{b, c}] == 0) {
            str[cnt] = {b, c};
            num[{b, c}] = cnt++;
        }
        g[num[{a, b}]].push_back(num[{b, c}]);
        used[num[{a, b}]][num[{b, c}]]++;
        degout[num[{a, b}]]++;
        degin[num[{b, c}]]++;
    }
    pair<int, int> stfn = {-1, -1};
    for (int i = 1; i < cnt; ++i) {
        if (degin[i] > degout[i] + 1 || degin[i] + 1 < degout[i]) {
            cout << "NO";
            return 0;
        }
        if (degin[i] > degout[i]) {
            if (stfn.second != -1) {
                cout << "NO";
                return 0;
            }
            stfn.second = i;
        }
        if (degin[i] < degout[i]) {
            if (stfn.first != -1) {
                cout << "NO";
                return 0;
            }
            stfn.first = i;
        }
    }
    if (stfn.first != -1) {
        g[stfn.second].push_back(stfn.first);
        used[stfn.second][stfn.first]++;
    }
    inline_dfs(1);
    reverse(ans.begin(), ans.end());
    if (stfn.first != -1) {
        ans.pop_back();
        /*cout << ans.size() << endl;
        for (auto elem : ans) {
            cout << elem;
        }
        cout << endl;*/
        if (ans.size() != n + 1) {
            cout << "NO";
            return 0;
        }
        int ind = 0;
        int x = ans.size();
        for (int i = 0; i < x; ++i) {
            if (ans[i] == stfn.first && ans[(i - 1 + x) % x] == stfn.second) {
                ind = i;
            }
        }
        cout << "YES" << endl;
        cout << str[stfn.first].first;
        for (int i = ind; i < ans.size(); ++i) {
            cout << str[ans[i]].second;
        }
        for (int i = 0; i < ind; ++i) {
            cout << str[ans[i]].second;
        }
    } else {
        /*cout << ans.size() << endl;
        for (auto elem : ans) {
            cout << str[elem].second;
        }
        cout << endl;*/
        if (ans.size() != n + 1) {
            cout << "NO";
            return 0;
        }
        cout << "YES" << endl;
        cout << str[ans[0]].first;
        for (auto elem : ans) {
            cout << str[elem].second;
        }
    }
    return 0;
}