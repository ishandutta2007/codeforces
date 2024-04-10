#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

string s, t;
int n, m;

char g(int i) {
	if (i < 0 || i >= n)
		return '.';
	return s[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s >> t;
	int z = 234234;

	n = s.size();
	m = t.size();

	for (int i = -5555; i <= 5555; i++) {
		int y = 0;
		for (int j = 0; j < m; j++) {
			if (t[j] != g(i + j)) {
				y++;
			}
		}
		z = min(z, y);
	}

	cout << z << '\n';
}