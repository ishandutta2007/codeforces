#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;
typedef long long ll;

template<class T> T abs(T x) { return x > 0 ? x : (-x); }
template<class T> T sqr(T x) { return x * x; }

vector<string> a;
int n, m;

bool u[57][57];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void dfs(int x, int y) {    
    u[x][y] = true;
    for (int dir = 0; dir < 4; ++dir) {
        int xx = x + dx[dir];
        int yy = y + dy[dir];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && !u[xx][yy] && a[xx][yy] == '#') dfs(xx, yy);
    }
}

int main() {
    cin >> n >> m;
    a.resize(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < m; ++j)
            if (a[i][j] == '#') ++cnt;
    }
    if (cnt <= 2) {
        printf("-1\n");
        return 0;
    }
    int res = 2;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) if (a[i][j] == '#') {
            a[i][j] = '.';
            memset(u, 0, sizeof(u));
            int s = 0;
            for (int x = 0; x < n; ++x)
                for (int y = 0; y < m; ++y) 
                    if (a[x][y] == '#' && !u[x][y]) {
                        dfs(x, y);
                        ++s;
                    }
            if (s > 1) res = 1;
            a[i][j] = '#';
        }
    cout << res << "\n";
    return 0;
}