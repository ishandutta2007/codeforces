#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int t = 0;
	for (int i = 0; i < s.length(); i += t) {
		cout << s[i];
		t++;
	}
	cout << '\n';
	return 0;
}