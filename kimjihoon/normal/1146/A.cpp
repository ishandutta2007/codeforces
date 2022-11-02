#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int a = 0, b = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a') a++;
		else b++;
	}
	while (a <= b) b--;
	cout << a + b << '\n';
	return 0;
}