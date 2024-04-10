#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 205;

int n[3];
llint dp[MAXN][MAXN][MAXN];
vector <llint> v[3];

int f (int x, int y, int z) {
    if (dp[x][y][z] != -1) return dp[x][y][z];
    llint res = 0;
    if (x > 0 && y > 0) res = max(res, f(x - 1, y - 1, z) + v[0][x] * v[1][y]);
    if (x > 0 && z > 0) res = max(res, f(x - 1, y, z - 1) + v[0][x] * v[2][z]);
    if (y > 0 && z > 0) res = max(res, f(x, y - 1, z - 1) + v[1][y] * v[2][z]);
    return dp[x][y][z] = res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n[0] >> n[1] >> n[2];
    for (int i = 0; i < 3; i++) {
        v[i].push_back(0);
        for (int j = 0; j < n[i]; j++) {
            int x; cin >> x;
            v[i].push_back(x);
        }
        sort(v[i].begin(), v[i].end());
    }
    cout << f(n[0], n[1], n[2]);
    return 0;
}