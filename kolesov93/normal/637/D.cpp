#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, s, d;
    scanf("%d%d%d%d", &n, &m, &s, &d);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(begin(a), end(a));

    if (s > a[0] - 1) {
        puts("IMPOSSIBLE");
        return 0;
    }

    vector<pair<int, int>> museum;
    museum.reserve(4 * n);

    for (int i = 0; i < n; ++i) {
        museum.emplace_back(a[i] - 1, -1);
        museum.emplace_back(a[i] + 1, 1);
        if (i + 1 < n && (a[i + 1] - 1) - (a[i] + 1) < s) {
            museum.emplace_back(a[i], -1);
            museum.emplace_back(a[i + 1], 1);
        }
    }
    sort(begin(museum), end(museum));
    
    vector<pair<int, int>> segments;

    int sum = 0;
    int left = -1;
    for (int i = 0; i < museum.size(); ++i) {
        sum -= museum[i].second;
        if (sum == 1 && museum[i].second == -1) { // new opened
            left = museum[i].first;
        } else if (sum == 0) { // closed
            segments.emplace_back(left, museum[i].first);
            if (segments.back().second - segments.back().first > d) {
                puts("IMPOSSIBLE");
                return 0;
            }
        }
    }

    int position = 0;
    for (auto&& segment : segments) {
        printf("RUN %d\n", segment.first - position);
        printf("JUMP %d\n", segment.second - segment.first);
        position = segment.second;
    }
    if (position < m) {
        printf("RUN %d\n", m - position);
    }

    return 0;
}