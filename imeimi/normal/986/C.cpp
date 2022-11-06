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

int n, m, mx;
int visited[1 << 23];
int arr[1 << 22];

void dfs(int x) {
    visited[x] = 1;
    if (x < mx) {
        if (!visited[x | mx]) dfs(x | mx);
    }
    else {
        for (int j = 1; j < mx; j <<= 1) {
            if (x == (x | j)) continue;
            if (visited[x | j]) continue;
            dfs(x | j);
        }
        int y = ((x ^ ((mx << 1) - 1)));
        if (arr[y] && !visited[y]) dfs(y);
    }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	mx = (1 << n);
	for (int i = 0; i < m; ++i) {
        cin >> n;
        arr[n] = 1;
	}
	
	int ret = 0;
	for (int i = 0; i < mx; ++i) {
        if (!arr[i]) continue;
        if (visited[i]) continue;
        dfs(i);
        ++ret;
	}
	printf("%d\n", ret);
	return 0;
}