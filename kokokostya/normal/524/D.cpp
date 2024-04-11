

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long long ll;
const ll md = 1e9 + 7;

int f(string s) {
    int ret = 0;
    ret += 10 * (s[0] - '0');
    ret += (s[1] - '0');
    ret *= 60;
    ret += 10 * (s[3] - '0');
    ret += (s[4] - '0');
    ret *= 60;
    ret += 10 * (s[6] - '0');
    ret += (s[7] - '0');
    return ret;
}

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n, m, t;
    cin >> n >> m >> t;

    vector<vector<int>> sum(86400);
    vector<int> times, ans(n);
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int cur = f(s);
        sum[cur].push_back(i);
        times.push_back(cur);
    }

    set<int> inds;
    map<int,int> cn;
    int best = 0;
    int mx = 0;
    int last = -1;

    for (int i = 0; i < t; i++) {
        for (int j: sum[i]) {
            if (inds.size() < m) {
                ans[j] = ++mx;
                inds.insert(ans[j]);
                cn[ans[j]]++;
                last = ans[j];
            } else {
                ans[j] = last;
                cn[ans[j]]++;
            }
        }
        best = max(best, (int)inds.size());
    }

    for (int i = t; i < 86400; i++) {
        for (int j : sum[i - t]) {
            cn[ans[j]]--;
            if (cn[ans[j]] == 0) {
                inds.erase(ans[j]);
            }
        }
        for (int j: sum[i]) {
            if (inds.size() < m) {
                ans[j] = ++mx;
                inds.insert(ans[j]);
                cn[ans[j]]++;
                last = ans[j];
            } else {
                ans[j] = last;
                cn[ans[j]]++;
            }
        }
        best = max(best, (int)inds.size());
    }

    if (best < m) {
        cout << "No solution\n";
    } else {
        cout << mx << '\n';
        for (int i: ans) {
            cout << i << '\n';
        }
    }

    return 0;
}