#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n, q, m;
int w[12];
int cnt[1 << 12];
int dist[1 << 12];

int getDistance(int x) {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        if (((x >> i) & 1) == 0) ret += w[i];
    }
    return ret;
}

int scanStr() {
    static char s[13];
    cin >> s;
    int x = 0;
    for (int i = 0; i < n; ++i) x = x << 1 | (s[i] - '0');
    return x;
}

int ds[1 << 12][101];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> q;
	for (int i = n; i--; ) cin >> w[i];
	for (int i = 0; i < m; ++i) {
        ++cnt[scanStr()];
	}
	
	for (int i = 0; i < (1 << n); ++i) {
        dist[i] = getDistance(i);
	}
	
	for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            int d = dist[i ^ j];
            if (d > 100) continue;
            ds[i][d] += cnt[j];
        }
	}
	
	for (int i = 0; i < (1 << n); ++i) {
        for (int j = 1; j <= 100; ++j) {
            ds[i][j] += ds[i][j - 1];
        }
	}
	
	for (int i = 0; i < q; ++i) {
        int x = scanStr(), y;
        cin >> y;
        printf("%d\n", ds[x][y]);
	}
	
	return 0;
}