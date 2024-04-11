#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/STACK:16777216")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <set>
#include <bitset>
#include <stack>
#include <unordered_set>
#include <ctime>
#include <cstring>
#include <map>

using namespace std;

bool comp(pair < long long, long long > a, pair < long long, long long > b) {
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int main() {
	//freopen("three.in", "r", stdin);
	//freopen("three.out", "w", stdout);

	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	long long n, m, d;
	cin >> n >> m >> d;
	vector < pair < long long, long long > > a(n), b(m);
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	for (int i = 0; i < m; i++)
		cin >> b[i].first >> b[i].second;
	sort(a.begin(), a.end(), comp);
	reverse(a.begin(), a.end());
	sort(b.begin(), b.end(), comp);
	reverse(b.begin(), b.end());
	for (int i = 1; i < n; i++) {
		a[i].first += a[i - 1].first;
		a[i].second += a[i - 1].second;
	}
	for (int i = 1; i < m; i++) {
		b[i].first += b[i - 1].first;
		b[i].second += b[i - 1].second;
	}
	int p2 = m - 1;
	long long ans = 0;
	for (int p1 = 0; p1 < n; p1++) {
		if (a[p1].second > d)
			break;
		while (p2 >= 0 && b[p2].second + a[p1].second > d)
			p2--;
		if (p2 >= 0)
			ans = max(ans, a[p1].first + b[p2].first);
	}
	cout << ans;
	return 0;
}