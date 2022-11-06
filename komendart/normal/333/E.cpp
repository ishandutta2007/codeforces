#include <bits/stdc++.h>

using namespace std;

const int maxn = 3005;

#define X first
#define Y second
typedef pair<int, int> point;

int dist(const point &a, const point &b) {
    return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
}

int n;
point a[maxn];
bitset<maxn> mark[maxn];
pair<int, pair<int, int> > v[maxn * maxn];
int pairs = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].X >> a[i].Y;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            v[pairs++] = {-dist(a[i], a[j]), {i, j}};
        }
    }
    sort(v, v + pairs);

    for (auto it: v) {
        int r = -it.first;
        int a, b; tie(a, b) = it.second;
        if ((mark[a] & mark[b]).any()) {
            cout << fixed; cout.precision(12);
            cout << sqrt(r) / 2 << '\n';
            return 0;
        }
        mark[a][b] = mark[b][a] = true;
    }
}