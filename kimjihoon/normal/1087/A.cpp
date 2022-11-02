#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	string s; cin >> s;
	int r = (s.length() - 1) / 2;
	for (int i = 0; i < s.length(); i++) {
		cout << s[r];
		if (i % 2 == 0) r += i + 1;
		else r -= i + 1;
	}
	cout << '\n';
	return 0;
}