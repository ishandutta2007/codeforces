#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	long long res = 0;;
	string s;
	cin >> s;
	int n = (int)s.length();
	vector<long long> v(128);
	for (int i = 0; i < n; i++) {
		++v[s[i]];
	}
	for (int i = 0; i < 128; i++) {
		res += v[i] * v[i];
	}
	cout << res << endl;
	return 0;
}