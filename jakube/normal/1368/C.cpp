#include "bits/stdc++.h"
using namespace std;

struct P
{
    int x, y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<P> points;
    auto f = [&points](int sx, int dir) {
        points.push_back({sx, dir});
        points.push_back({sx, 2*dir});
        points.push_back({sx+1, 2*dir});
        points.push_back({sx+2, 2*dir});
        points.push_back({sx+2, dir});
        points.push_back({sx+2, 0});
        points.push_back({sx+1, 0});
    };

    points.push_back({0, 0});
    for (int i = 0; i <= n; i++) {
        f(2*i, (i % 2) ? 1 : -1);
    }

    cout << points.size() << '\n';
    for (auto P : points) {
        cout << P.x << " " << P.y << '\n';
    }
}