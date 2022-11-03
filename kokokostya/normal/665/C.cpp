#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == s[i - 1]) {
			if ('a' != s[i - 1] && (i == s.length() - 1 || 'a' != s[i + 1])) { s[i] = 'a'; }
			else {
				if ('b' != s[i - 1] && (i == s.length() - 1 || 'b' != s[i + 1])) { s[i] = 'b'; }
				else {
					if ('c' != s[i - 1] && (i == s.length() - 1 || 'c' != s[i + 1])) { s[i] = 'c'; }
				}
			}
		}
	}
	cout << s;
	return 0;
}