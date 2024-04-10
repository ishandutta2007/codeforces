#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

// zero, one, flip, same

int andt[4][4] = {
	{0, 0, 0, 0},
	{0, 1, 2, 3},
	{0, 2, 2, 0},
	{0, 3, 0, 3}
};

int ort[4][4] = {
	{0, 1, 2, 3},
	{1, 1, 1, 1},
	{2, 1, 2, 1},
	{3, 1, 1, 3}
};

int xort[4][4] = {
	{0, 1, 2, 3},
	{1, 0, 3, 2},
	{2, 3, 0, 1},
	{3, 2, 1, 0}
};

int n, m;

map<string, vector<int>> vars;

vector<int> operac(vector<int> a, vector<int> b, string op) {
	vector<int> c(m);

	auto tbl = (op == "AND" ? andt : (op == "OR" ? ort : xort));

	for (int i=0; i<m; i++) {
		c[i] = tbl[a[i]][b[i]];
	}

	return c;
}

vector<int> konst(string s) {
	vector<int> a(m);
	for (int i=0; i<m; i++) {
		a[i] = s[i] == '0' ? 0 : 1;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;

	vector<int> peter(m, 2);

	for (int i=1; i<=n; i++) {
		string nm, asgn, op1;

		cin >> nm >> asgn >> op1;

		if (op1[0] == '0' || op1[0] == '1') {
			vars[nm] = konst(op1);
		} else {
			string operat, op2;
			cin >> operat >> op2;

			vector<int> a, b;
			if (op1 == "?") {
				a = peter;
			} else {
				a = vars[op1];
			}

			if (op2 == "?") {
				b = peter;
			} else {
				b = vars[op2];
			}

			vars[nm] = operac(a, b, operat);
		}
	}

	// nadji najmanjeg tako da bude najmanji zbir
	{
		vector<int> med(m, 0), mot(m, 0);
		for (auto p : vars) {
			for (int i=0; i<m; i++) {
				if (p.second[i] == 2) {
					med[i]++;
				} else if (p.second[i] == 3) {
					mot[i]++;
				}
			}
		}

		// najmanje
		for (int i=0; i<m; i++) {
			if (med[i] >= mot[i]) {
				cout << '0';
			} else {
				cout << '1';
			}
		}
		cout << '\n';

		for (int i=0; i<m; i++) {
			if (med[i] <= mot[i]) {
				cout << '0';
			} else {
				cout << '1';
			}
		}
		cout << '\n';
	}
	
}