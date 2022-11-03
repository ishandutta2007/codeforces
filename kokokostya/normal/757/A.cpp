#include<iostream>
#include<vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	string t = "Bulbasaur";
	vector<int> a(9);
	int ans = 10000000;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < 9; j++)
			if (s[i] == t[j])
				a[j]++;
	}
	a[1] /= 2;
	a[7] /= 2;
	a[4] /= 2;
	a[6] /= 2;
	for (int i = 0; i < 9; i++)
		ans = min(ans, a[i]);
	cout << ans;

	return 0;
}