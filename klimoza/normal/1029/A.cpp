#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string s;
	int n, f;
	cin >> n >> f;
	cin >> s;
	vector<int> p(n);
	int k = 0;
	for (int i = 1; i < n; i++) {
		k = p[i - 1];
		while (k > 0 && s[k] != s[i]) {
			k = p[k - 1];
		}
		p[i] = k + (s[k] == s[i]);
	}
	int ind = p[n - 1];
	string t = "";
	for (int i = ind; i < n; i++) {
		t += s[i];
	}
	cout << s;
	for (int i = 0; i < f - 1; i++) {
		cout << t;
	}
	cout << "\n";
	//system("pause");
	return 0;
}