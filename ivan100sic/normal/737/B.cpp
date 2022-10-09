#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n, a, b, k;
	string s;
	vector<pair<int, int>> g;

	cin >> n >> a >> b >> k >> s;

	s += '1';
	{
		int sl = 0, i = 1;
		for (char x : s) {
			if (x == '0') {
				sl++;
			} else if (sl > 0) {
				g.push_back({i-sl, sl});
				sl = 0;
			}
			i++;
		}
	}

	int fit = 0;
	for (auto p : g) {
		fit += p.second / b;
	}

	int shoot = fit - a + 1;
	cout << shoot << '\n';
	for (auto p : g) {
		for (int rep=p.first+b-1; rep<p.first+p.second; rep+=b) {
			if (shoot > 0) {
				cout << rep << ' ';
				shoot--;
			}
		}
	}
}