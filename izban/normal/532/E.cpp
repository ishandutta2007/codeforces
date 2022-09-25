#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

const int maxn = -1;

bool check(string a, string b) {
	int i = 0;
	while (i < (int)b.length()) {
		if (a[i] != b[i]) {
			break;
		}
		else {
			i++;
		}
	}
	bool ok = 1;
	while (i < (int)b.length()) {
		ok &= a[i + 1] == b[i];
		i++;
	}
	return ok;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("task.in", "r", stdin);
#endif

	int n;
	string a, b;
	while (cin >> n >> a >> b) {
		int i = 0;
		while (a[i] == b[i]) i++;
		
		int ans = 0;
		string s1 = "";
		s1 += a.substr(0, i);
		s1 += b[i];
		s1 += a.substr(i);
		if (check(s1, b)) ans++;

		s1 = "";
		s1 += b.substr(0, i);
		s1 += a[i];
		s1 += b.substr(i);
		if (check(s1, a)) ans++;

		cout << ans << endl;
	}

	return 0;
}