#include <iostream>
#include <set>

using namespace std;

int main() {
	string s;
	cin >> s;
	set<char> m;
	for (int i = 0; i < s.length(); i++)
		m.insert(s[i]);
	cout << (m.size()%2?"IGNORE HIM!":"CHAT WITH HER!") << endl;
	return 0;
}