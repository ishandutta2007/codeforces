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

	string s;
	int n;
	cin >> n >> s;
	int sol = 0;
	for (int i=1; i<s.size(); i++) {
		if (s[i] == s[i-1]) {
			sol++;
		}
	}

	cout << sol;
}