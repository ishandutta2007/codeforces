#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <deque>

using namespace std;

typedef long long ll;

ll INF = 1e18;

vector<int> a;

bool ans = false;

void rec(int cur, int sum) {
	if (sum == 0 && cur == a.size()) {
		ans = true;
		return;
	}
	else if (cur == a.size()) {
		return;
	}
	else {
		rec(cur + 1, (sum + 360 + a[cur]) % 360);
		if (ans) return;
		rec(cur + 1, (sum + 360 - a[cur]) % 360);
	}
}

int main() {
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	rec(0, 0);
	if (ans) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	//system("pause");
	return 0;
}