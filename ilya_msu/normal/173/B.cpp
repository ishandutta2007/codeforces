#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>

using std::pair;
using std::stringstream;
using std::next_permutation;
using std::sqrt;
using std::priority_queue;
using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;
using std::set;
using std::swap;
using std::random_shuffle;
using std::queue;
using std::sin;
using std::cos;
using std::make_pair;
using std::cos;

typedef long long ll; 
typedef pair<ll, ll> pll;
const long double PI = 3.14159265358979323846;  


int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int ok(int a, int b) {
	return a / gcd(a, b) * b;
}

int check(char c1, char c2) {
	if (c1 == c2)
		return 0;
	if (c1 == 'R') {
		if (c2 == 'S')
			return 1;
		else
			return -1;
	}
	if (c1 == 'P') {
		if (c2 == 'R')
			return 1;
		else
			return -1;
	}
	if (c1 == 'S') {
		if (c2 == 'P')
			return 1;
		else
			return -1;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<bool> > data(n, vector<bool> (m));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			data[i][j] = (s[j] == '#');
		}
	}
	vector<int> stroki(n, -1);
	vector<bool> usedStroki(n, false);
	vector<bool> usedStolb(m, false);
	vector<int> stolb(m, -1);
	stroki[n - 1] = 0;
	usedStroki[n - 1] = true;
	queue<pair<int, int> > trav;
	trav.push(make_pair(n - 1, 0));
	while (!trav.empty()) {
		pair<int, int> cur = trav.front();
		trav.pop();
		if (cur.second == 0) {
			for (int i = 0; i < m; ++i) {
				if (data[cur.first][i]) {
					if (!usedStolb[i]) {
						usedStolb[i] = true;
						trav.push(make_pair(i, 1));
						stolb[i] = stroki[cur.first] + 1;
					}
				}
			}
		}
		else {
			for (int i = 0; i < n; ++i) {
				if (data[i][cur.first]) {
					if (!usedStroki[i]) {
						usedStroki[i] = true;
						trav.push(make_pair(i, 0));
						stroki[i] = stolb[cur.first] + 1;
					}
				}
			}
		}
	}
	cout << stroki[0] << endl;

	return 0;
}