#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	long long res = 0;
	for (int i = 1; i < s.length(); i++) {
		if (((int(s[i - 1])-int('0')) * 10 + (int(s[i]) - int('0'))) % 4 == 0) { res += i; }
		if (s[i] == '0' || s[i] == '4' || s[i] == '8') { res++; }
	}
	if (s[0] == '0' || s[0] == '4' || s[0] == '8') { res++; }
	cout << res;
	return 0;
}