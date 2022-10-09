#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string a;
	cin >> a;
	vector<string> names = {"Danil", "Olya", "Slava", "Ann", "Nikita"};

	int c = 0;

	for (string nm : names) {

		for (size_t i=0; i+nm.size() <= a.size(); i++) {
			if (a.substr(i, nm.size()) == nm) {
				c++;
			}
		}
	}

	if (c == 1) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}