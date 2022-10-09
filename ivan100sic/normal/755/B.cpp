#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	set<string> a, b, c;
	int n, m, k;

	cin >> n >> m;
	while (n--) {
		string s;
		cin >> s;
		a.insert(s);
	}

	while (m--) {
		string p;
		cin >> p;
		b.insert(p);
		if (a.count(p)) {
			c.insert(p);
		}
	}

	n = a.size();
	m = b.size();
	k = c.size();

	cerr << n << ' ' << m << ' ' << k << '\n';

	int turn = 1;

	while (1) {
		if (n == 0 && turn == 1) {
			cout << "NO";
			break;
		}
		if (m == 0 && turn == 2) {
			cout << "YES";
			break;
		}

		if (turn == 1) {
			if (k > 0) {
				m--;
				k--;
				n--;
			} else {
				n--;
			}
		} else {
			if (k > 0) {
				m--;
				k--;
				n--;
			} else {
				m--;
			}
		}

		turn = 3 - turn;
	}


}