#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	int l = 0, r = (int)s.length() - 1;
	while (true) {
		while (l < s.length() && s[l] == ')')
			l++;
		while (r >= 0 && s[r] == '(')
			r--;
		if (l > r) break;
		ans.push_back(l); ans.push_back(r);
		l++; r--;
	}
	if (ans.size() == 0)
		cout << 0 << '\n';
	else {
		cout << 1 << '\n';
		cout << ans.size() << '\n';
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] + 1 << " ";
		cout << '\n';
	}
	return 0;
}