#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <set>
#include <map>
using namespace std;

char color(map<char, int> m) {
	int x = m['R'];
	int y = m['G'];
	int z = m['B'];

	if (y == 0 && z == 0) {
		return 'R';
	}

	if (x == 0 && z == 0) {
		return 'G';
	}

	if (x == 0 && y == 0) {
		return 'B';
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s[105];
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> s[i];
	}

	bool ok = false;

	{
		if (n % 3 == 0) {
			map<char, int> m2;

			{
				map<char, int> m1;

				for (int i=0; i<n/3; i++) {
					for (int j=0; j<m; j++) {
						m1[s[i][j]]++;
					}
				}

				m2[color(m1)]++;
			}

			{
				map<char, int> m1;

				for (int i=n/3; i<2*n/3; i++) {
					for (int j=0; j<m; j++) {
						m1[s[i][j]]++;
					}
				}

				m2[color(m1)]++;
			}
		

			{
				map<char, int> m1;

				for (int i=2*n/3; i<n; i++) {
					for (int j=0; j<m; j++) {
						m1[s[i][j]]++;
					}
				}

				m2[color(m1)]++;
			}

			if (m2['R'] == 1 && m2['G'] == 1 && m2['B'] == 1) {
				ok = true;
			}
		}
	}

	{
		if (m % 3 == 0) {
			map<char, int> m2;

			{
				map<char, int> m1;

				for (int i=0; i<n; i++) {
					for (int j=0; j<m/3; j++) {
						m1[s[i][j]]++;
					}
				}

				m2[color(m1)]++;
			}

			{
				map<char, int> m1;

				for (int i=0; i<n; i++) {
					for (int j=m/3; j<2*m/3; j++) {
						m1[s[i][j]]++;
					}
				}

				m2[color(m1)]++;
			}
		

			{
				map<char, int> m1;

				for (int i=0; i<n; i++) {
					for (int j=2*m/3; j<m; j++) {
						m1[s[i][j]]++;
					}
				}

				m2[color(m1)]++;
			}

			if (m2['R'] == 1 && m2['G'] == 1 && m2['B'] == 1) {
				ok = true;
			}
		}
	}

	cout << (ok ? "YES" : "NO");

}