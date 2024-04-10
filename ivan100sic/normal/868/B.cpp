#include <bits/stdc++.h>
using namespace std;

set<int> banned;
int start, endd;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int h, m, s;
	cin >> h >> m >> s;

	h %= 12;
	/*
	banned.insert(s);
	banned.insert(m + s / 60);
	banned.insert(5*h + m / 60 + s / 3600);
	*/
	banned.insert(s * 3600);
	banned.insert(m * 3600 + s * 60);
	banned.insert(5*h * 3600 + m * 60 + s);

	cin >> start >> endd;
	start = start % 12 * 5 * 3600;
	endd = endd % 12 * 5 * 3600;

	// fwd?
	{
		int pos = start;
		while (1) {
			if (pos == endd) {
				cout << "YES";
				return 0;
			}
			pos++;
			if (pos == 3600*60) {
				pos = 0;
			}
			if (banned.count(pos)) {
				break;
			}
		}
	}
	// bck
	{
		int pos = start;
		while (1) {
			if (pos == endd) {
				cout << "YES";
				return 0;
			}
			pos--;
			if (pos == -1) {
				pos = 3600*60 - 1;
			}
			if (banned.count(pos)) {
				break;
			}
		}
	}
	cout << "NO";
}