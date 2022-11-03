#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>

using namespace std;

#define LOCAL

const int MX = 1e6 + 13;
const long long INF = 1e13;

int main() {
	ios_base::sync_with_stdio(false);
#ifndef LOCAL
	freopen("testbrain.in", "r", stdin);
	freopen("testbrain.out", "w", stdout);
#endif
	int n, m, k;
	cin >> n >> m >> k;
	vector< vector< pair<int, int> > > in(n + 1), out(n + 1);
	while (m--) {
		int d, a, b, c;
		cin >> d >> a >> b >> c;
		if (a)
			in[a].push_back({ c, d });
		if (b)
			out[b].push_back({ c, d });
	}
	vector< vector< pair<int, int> > > ain(MX), aout(MX);
	vector<long long> dpin(MX, INF), dpout(MX, INF);
	for (int i = 0; i <= n; i++) {
		for (pair<int, int> j : in[i])
			ain[j.second].push_back({ i , j.first });
		for (pair<int, int> j : out[i])
			aout[j.second].push_back({ i , j.first });
	}
	vector<long long> now(n + 1, INF);
	long long sum = INF * n;
	for (int i = 0; i < MX; i++) {
		for (pair<int, int> j : ain[i]) {
			if (j.second < now[j.first]) {
				sum -= now[j.first] - j.second;
				now[j.first] = j.second;
			}
		}
		dpin[i] = sum;
	}
	now.assign(n + 1, INF);
	sum = INF * n;
	for (int i = MX - 1; i >= 0; i--) {
		for (pair<int, int> j : aout[i]) {
			if (j.second < now[j.first]) {
				sum -= now[j.first] - j.second;
				now[j.first] = j.second;
			}
		}
		dpout[i] = sum;
	}
	long long ans = INF;
	for (int i = 0; i + k + 1 < MX; i++)
		ans = min(ans, dpin[i] + dpout[i + k + 1]);
	if (ans == INF)
		cout << -1;
	else
		cout << ans;
	return 0;
}