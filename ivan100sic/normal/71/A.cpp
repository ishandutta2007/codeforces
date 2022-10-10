#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s.size() <= 10) {
			cout << s << '\n';
		} else {
			cout << s[0] << to_string(s.size()-2) << s[s.size()-1] << '\n';
		}
	}
}