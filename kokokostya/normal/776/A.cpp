#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s, t;
	cin >> s >> t;
	int n;
	cin >> n;
	cout << s << ' ' << t << '\n';
	for (int i = 0; i < n; i++) {
		string k, l;
		cin >> k >> l;
		if (k == s)
			s = l;
		else
			t = l;
		cout << s << ' ' << t << '\n';
	}
	return 0;
}