#include <bits/stdc++.h>
using namespace std;

bool flag;
string ans, str;

void dfs() {
	if (cin >> str) {
		ans += str;
		if (str == "pair") {
			ans += "<", dfs();
			ans += ',';
			dfs(), ans += '>';
		}
	} else {
		flag = 1;
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios :: sync_with_stdio(0);
	cin >> str;
	dfs();
	if (flag || cin >> str) {
		puts("Error occurred");
		return 0;
	}
	cout << ans;
	return 0;
}