#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

#define sz(x) ((int) (x).size())

const int maxn = 2005;

int n;
vector<int> graph[maxn];
int c[maxn];

void fail() {
    cout << "NO\n";
    exit(0);
}

vector<int> dfs(int v) {
    vector<int> ans;
    for (auto to: graph[v]) {
        for (auto it: dfs(to)) {
            if (sz(ans) == c[v]) {
                ans.push_back(v);
            }
            ans.push_back(it);
        }
    }
    if (sz(ans) == c[v]) {
        ans.push_back(v);
    }
    if (sz(ans) < c[v]) {
        fail();
    }
    return ans;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n;
    int root = -1;
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p >> c[i];
        if (p == 0) {
            root = i;
        } else {
            graph[p].push_back(i);
        }
    }
    
    vector<int> vec = dfs(root);
    vector<int> ans(n + 1);
    for (int i = 0; i < n; ++i) {
        ans[vec[i]] = i + 1;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}