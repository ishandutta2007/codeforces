#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;


bool key(string x, string y) {
	if (x.length() < y.length()) return true;
	return false;
}

bool check(string s1, string s2) {
	string s;
	for (int i = 0; i < s2.length() - s1.length() + 1; i++) {
		s = "";
		for (int j = i; j < i + s1.length(); j++) {
			s += s2[j];
		}
		if (s == s1) return true;
	}
	return false;
}


int main() {
	int n;
	cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end(), key);
	bool fl = true;
	for (int i = 0; i < n - 1; i++) {
		if (!check(a[i], a[i + 1])) {
			fl = false;
		}
	}
	if (fl) {
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			cout << a[i] << "\n";
		}
	}
	else {
		cout << "NO\n";
	}
	//system("pause");
	return 0;
}