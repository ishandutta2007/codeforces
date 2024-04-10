#include <bits/stdc++.h>
using namespace std;

using Point = pair<int, int>;

auto count(vector<Point>& points) {
    sort(points.begin(), points.end());
    deque<Point> dq(points.begin(), points.end());
    sort(points.begin(), points.end(), [](auto p, auto q) {
        return p.second < q.second;
    });
    
    auto cnt = 0LL;
    int n = points.size();
    if (n < 4)
        return cnt;
    int begin = points.front().second;
    int end = points.back().second;
    int min_x = points[0].first;
    int max_x = points[0].first;
    int last = 0;
    for (int i = begin; i <= end; i++) {
        if ((i & 1) == (begin & 1)) {
            while (last + 1 < n && points[last + 1].second == i) {
                last++;
                min_x = min(min_x, points[last].first);
                max_x = max(max_x, points[last].first);
            }
        } else {
            while (dq.front().second < i) {
                dq.pop_front();
            }
            while (dq.back().second < i) {
                dq.pop_back();
            }
            int left = max(min_x, dq.front().first);
            int right = min(max_x, dq.back().first);
            if (right > left) {
                cnt += (right - left) / 2;
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Point> points_odd, points_even;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if ((x + y) & 1)
            points_odd.emplace_back(x + y, x - y);
        else
            points_even.emplace_back(x + y, x - y);
    }
    
    cout << count(points_odd) + count(points_even) << endl;
}