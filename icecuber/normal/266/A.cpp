#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	char last = ' ';
	int c = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == last) c++;
		last = s[i];
	}
	cout << c << endl;
	return 0;
}