#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	cout << (s[(int)s.length() - 1] - '0') % 2 << '\n';
	return 0;
}