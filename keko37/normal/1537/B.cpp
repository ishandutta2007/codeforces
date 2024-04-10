#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <llint, llint> pi;

const llint INF = 1000000000000000000;

llint t, n, m, sx, sy;
vector <pi> v;

llint dist (pi a, pi b) {
    llint ax = a.first, ay = a.second;
    llint bx = b.first, by = b.second;
    return abs(ax - bx) + abs(ay - by);
}

llint f (pi a, pi b, pi c) {
    return min(dist(a, b) * 2 + dist(a, c) * 2, dist(a, b) + dist(b, c) + dist(a, c));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m >> sx >> sy;
        v.clear();
        v.push_back({1, 1});
        v.push_back({1, m});
        v.push_back({n, 1});
        v.push_back({n, m});
        llint mn = -1, x = -1, y = -1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                llint val = f({sx, sy}, v[i], v[j]);
                if (val > mn) {
                    mn = val;
                    x = i; y = j;
                }
            }
        }
        cout << v[x].first << " " << v[x].second << " ";
        cout << v[y].first << " " << v[y].second << " ";
        cout << '\n';
    }
    return 0;
}