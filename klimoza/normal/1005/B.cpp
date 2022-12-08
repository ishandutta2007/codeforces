#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	string s, t;
	cin >> s >> t;
	int ans = 0;
	ans = s.length() + t.length();
	for (int i = 1; i <= min(s.length(), t.length()); i++) {
		if (s[s.length() - i] != t[t.length() - i]) break;
		ans -= 2;
	}
	cout << ans << "\n";
	//system("pause");
	return 0;
}