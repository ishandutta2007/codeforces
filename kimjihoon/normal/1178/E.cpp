#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	string ans = "";
	for (int i = 0; (int)s.length() - i * 2 >= 4; i += 2) {
		ans += " ";
		for (int li = i; li <= i + 1; li++)
			for (int ri = (int)s.length() - i - 2; ri <= (int)s.length() - i - 1; ri++)
				if (s[li] == s[ri]) ans.back() = s[li];
	}
	int p = ans.length();
	if ((int)s.length() % 4 != 0) 
		ans += s[(int)s.length() / 2];
	for (int i = p - 1; i >= 0; i--)
		ans += ans[i];
	cout << ans << '\n';
	return 0;
}