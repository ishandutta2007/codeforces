

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

ll seed;
ll rnd() {
    ll ret = seed;
    seed = (7 * seed + 13) % md;
    return ret;
}
int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int m, k;
    cin >> m >> k;

    set<int> all;
    unordered_map<int,unordered_map<int,bool>> edges;

    while (m--) {
        int x, y;
        cin >> x >> y;
        all.insert(x);
        all.insert(y);
        edges[x][y] = edges[y][x] = 1;
    }

    for (int x : all) {
        vector<int> fr;
        for (int y : all) {
            if (y == x || edges[x].count(y)) {
                continue;
            }
            int cn = 0;
            for (auto z : edges[x]) {
                if (edges[z.first].count(y)) {
                    cn++;
                }
            }
            if (cn * 100 >= edges[x].size() * k) {
                fr.push_back(y);
            }
        }
        sort(fr.begin(), fr.end());
        cout << x << ": " << fr.size() << ' ';
        for (int y : fr) {
            cout << y << ' ';
        }
        cout << '\n';
    }

    return 0;
}