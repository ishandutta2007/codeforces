#include<bits/stdc++.h>
 
using namespace std;

#define point pair<int, int>
#define x first
#define y second

long long sin(point a, point b) {
    return a.x * 1ll * b.y - a.y * 1ll * b.x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<point> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    long long ans = 1ll * n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 4 / 3 / 2;
    for (int i = 0; i < n; i++) {
        vector<point> b;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                b.push_back(point(a[j].x - a[i].x, a[j].y - a[i].y));
            }
        }
        sort(b.begin(), b.end(), [&] (const point& x, const point& y) {
            if (x.y >= 0 && y.y < 0) {
                return true;
            }
            if (x.y < 0 && y.y >= 0) {
                return false;
            }
            return sin(x, y) > 0;
        });
        int uk = 0, cnt = 0;
        for (int j = 0; j + 1 < n; j++) {
            if (uk == j) {
                uk = (uk + 1) % (n - 1);
                cnt = 0;
            }
            while (sin(b[j], b[uk]) > 0) {
                cnt++;
                uk = (uk + 1) % (n - 1);
            }
            ans -= 1ll * cnt * (cnt - 1) * (cnt - 2) / 2 / 3;
            cnt--;
        }
    }
    cout << ans;
}