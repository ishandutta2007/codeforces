// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

bool isopen(char x) {
	return string("<([{").find(x) != string::npos;
}

char to_closed(char x) {
	return ">)]}"[string("<([{").find(x)];
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	string s;
	cin >> s;

	int c = 0;

	string t;
	for (char x : s) {
		if (isopen(x)) {
			t += x;
		} else {
			if (t.empty()) {
				cout << "Impossible\n";
				return 0;
			}
			if (to_closed(t.back()) != x) {
				c++;
			}
			t.pop_back();
		}
	}

	if (t.size()) {
		cout << "Impossible\n";
		return 0;
	}

	cout << c << '\n';
}