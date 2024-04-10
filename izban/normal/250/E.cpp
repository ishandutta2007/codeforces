#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <ctime>
#include <cassert>

using namespace std;

#define ll long long
#define double long double

const int maxn = 1 << 7;
const int inf = 1000000007;
const int dx[2] = {1, -1};

int n, m;
ll ans = 0;
string s[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i], s[i] = "#" + s[i] + "#";

	int cur = 0, dir = 0, l = 1, r = 1, pos = 1;
	while (cur < n - 1) {
		if (clock() > 1800) {
			cout << "Never" << endl;
			return 0;
		}
		if (s[cur + 1][pos] == '.') {
			cur += 1;
			l = r = pos;
			ans++;
			continue;
		}
		if (s[cur][pos + dx[dir]] == '.') {
			ans++;
			if (dir)
				l--, pos--;
			else
				r++, pos++;
			continue;
		}
		if (s[cur][pos + dx[dir]] == '+') {
			s[cur][pos + dx[dir]] = '.';
			ans++;
			dir ^= 1;
			ans += abs(r - l);
			if (pos == l)
				pos = r;
			else
				pos = l;
			continue;
		}
		if (s[cur][pos + dx[dir]] == '#') {
			ans++;
			dir ^= 1;
			ans += abs(r - l);
			if (pos == l)
				pos = r;
			else
				pos = l;
			continue;
		}
	}

	cout << ans;

	return 0;
}