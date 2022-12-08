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

int main() {
	string s;
	cin >> s;
	string st;
	for (int i = 0; i < 5; i++) {
		cin >> st;
		if (st[0] == s[0] || st[1] == s[1]) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	//system("pause");
	return 0;
}