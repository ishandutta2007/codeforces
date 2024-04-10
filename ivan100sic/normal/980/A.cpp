#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;
	int a = count(s.begin(), s.end(), '-');
	int b = count(s.begin(), s.end(), 'o');

	if (b == 0 || a % b == 0) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	// system("pause");
}