#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
vector<int> g[MAXN];
int c[MAXN];

map<int, int> dfs(int v, int l) {
    int ls = l;
    map<int, int> arr;
    for (auto u : g[v]) {
        auto now = dfs(u, l);
        l += now.size();
        for (auto elem : now) {
            if (elem.second == -1) {
                arr.clear();
                arr[1] = -1;
                return arr;
            }
            arr[elem.first] = elem.second;
        }
    }
    if (c[v] > arr.size()) {
        arr.clear();
        arr[1] = -1;
        return arr;
    }
    for (int i = l; i >= c[v] + 1 + ls; --i) {
        arr[i] = arr[i - 1];
    }
    arr[c[v] + ls] = v;
    return arr;
}

main() {
    int n;
    cin >> n;
    int rt = -1;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p >> c[i];
        p--;
        if (p == -1) {
            rt = i;
        } else {
            g[p].push_back(i);
        }
    }
    auto arr = dfs(rt, 1);
    if (arr[1] == -1) {
        cout << "NO";
        return 0;
    }
    vector<int> ans(n);
    for (auto elem : arr) {
        int x = elem.first;
        int v = elem.second;
        ans[v] = x;
    }
    cout << "YES" << endl;
    for (auto elem : ans) {
        cout << elem << " ";
    }
    return 0;
}