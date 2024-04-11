#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <cstring>
#include <bitset>
#include <random>

typedef long long ll;

using namespace std;

const int MX = 1e6 + 7;
multiset<int> s[MX];

int get(int i) {
    if(s[i].empty()) return 0;
    else return *(--s[i].end());
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);

    int n, w;
    cin >> n >> w;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        a[i].resize(l + 2);
        for (int j = 0; j < l; j++)
            cin >> a[i][j + 1];
    }

    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)a[i].size(); j++) {
            events.push_back({j - 1, i + 1});
            events.push_back({w + 1 - j, -(i + 1)});
        }
    }
    sort(events.begin(), events.end());
    ll now = 0;
    vector<int> ans(w);
    int pos = 0;
    for (int x = -1; x < w; x++) {
        while (events[pos].first == x) {
            int i = abs(events[pos].second) - 1;
            now -= get(i);
            if (events[pos].second > 0) {
                int pos = x + 1;
                s[i].insert(a[i][pos]);
            } else {
                int pos = (int)a[i].size() - 1 + (x - (w + 1));
                s[i].erase(s[i].find(a[i][pos]));
            }
            now += get(i);

            pos++;
        }
        if (x != -1)
        cout << now << ' ';
    }

    return 0;
}