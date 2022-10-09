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
	cin >> s;

	auto a1 = s.find("1111111");
	auto a2 = s.find("0000000");
	auto a3 = s.find("x");
	if (a1 == a3 && a2 == a3) {
		cout << "NO";
	} else {
		cout << "YES";
	}

}