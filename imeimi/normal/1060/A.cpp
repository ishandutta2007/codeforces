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

int n, m;
char in[1000];
int cnt[10];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> in;
	for (int i = 0; i < n; ++i) if (in[i] == '8') ++m;
	int s = 0, e = 100;
	while (s < e) {
        int md = (s + e + 1) / 2;
        if (md <= m && 10 * md <= n - md) s = md;
        else e = md - 1;
	}
	printf("%d\n", s);
	return 0;
}