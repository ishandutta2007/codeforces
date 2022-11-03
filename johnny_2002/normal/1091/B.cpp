#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define X first
#define Y second

ii operator + (ii a, ii b) {
    return ii(a.X + b.X, a.Y + b.Y);
}
ii operator - (ii a, ii b) {
    return ii(a.X - b.X, a.Y - b.Y);
}
set<ii> ma;
const int N = 1e3 + 10;
int n;
ii a[2][N];
bool check(ii cur) {
    for(int i = 1; i <= n; i++) 
        if (!ma.count(cur - a[0][i])) return 0;
    return 1;
}
void solve() {
    for(int use = 1; use <= n; use++) {
        ii cur = a[0][1] + a[1][use];
        if (check(cur)) {
            cout << cur.X << " " << cur.Y;
            break;
        }
    }
}
int main() {
    cin >> n;
    for(int i = 0; i <= 1; i++) 
        for(int j = 1; j <= n; j++) cin >> a[i][j].X >> a[i][j].Y;
    for(int j = 1; j <= n; j++) 
        ma.insert(a[1][j]);
    solve();
}