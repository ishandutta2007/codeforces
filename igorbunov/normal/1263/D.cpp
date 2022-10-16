#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <random>
#include <string>
#include <random>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

#define int long long
#define endl '\n'

vector<int> g[200000];
vector<bool> used(200000);
void dfs(int v) {
    used[v] = true;
    for (auto u: g[v]) {
        if (used[u]) {
            continue;
        }
        dfs(u);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    vector<vector<int>> inds(26);
    for (int _ = 0; _ < n; _++) {
        string s;
        cin >> s;
        vector<int> cnt(26);
        for (int i = 0; i < s.size(); i++) {
            if (cnt[s[i] - 'a'] == 0) {
                cnt[s[i] - 'a']++;
                inds[s[i] - 'a'].push_back(_);
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < (int)inds[i].size() - 1; j++) {
            g[inds[i][j]].push_back(inds[i][j + 1]);
            g[inds[i][j + 1]].push_back(inds[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            ans++;
            dfs(i);
        }
    }
    cout << ans << endl;
    return 0;
}