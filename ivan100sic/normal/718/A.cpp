#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

char buff[500005];
char* s = buff + 1;

int n, k;

set<int> pos[11];

int dot;

int kraj(int) {
	int p = 1e9;
	for (int i = 5; i<10; i++) {
		if (pos[i].size()) p = min(p, *pos[i].begin());
	}
	return p;
}

int kraj() {
	int p = 0;
	for (int i = 1; i<10; i++) {
		if (pos[i].size()) p = max(p, *pos[i].rbegin());
	}
	return p;
}

void modify(int p, int x) {
	if (p > dot) {
		int old = s[p] - 48;
		pos[old].erase(p);

		s[p] = x + 48;
		pos[x].insert(p);
	} else {
		s[p] = x + 48;
	}
}

bool dotremoved;

void seci(int p) {

	if (p <= dot) {
		dotremoved = true;
		return;
	}

	// sve od p do kraja zameni nulama
	// p-1 zameni sa jednom vecom (kaskadiraj ako treba)
	int kr = kraj();

	for (int i = p; i <= kr; i++) {
		modify(i, 0);
	}

	int q = p - 1;
	if (s[q] == '.') {
		q--;
		dotremoved = true;
	}
	modify(q, s[q] - 48 + 1);
	while (s[q] == 48 + 10) {
		modify(q, 0);
		q--;
		if (s[q] == '.') {
			q--;
			dotremoved = true;
		}
		modify(q, s[q] - 48 + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k >> s;
	s[-1] = '0';

	dot = -1;

	for (int i = 0; i<n; i++) {
		if (s[i] == '.') dot = i;
	}

	for (int i = dot + 1; i<n; i++) {
		pos[s[i] - 48].insert(i);
	}

	if (dot == -1) {
		cout << s << endl;
		return 0;
	}

	while (k--) {
		int p = kraj(5);
		if (p < dot || p > n) break;
		if (!dotremoved) {
			seci(p);
		} else {
			break;
		}
	}

	if (s[-1] != '0') cout << s[-1];

	if (dotremoved) {
		for (int i = 0; i<dot; i++) cout << s[i];
	} else {
		int k = kraj();
		for (int i = 0; i <= k; i++) cout << s[i];
	}
	cout << endl;

	return 0;
}