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

string cc(int x) {
	string s;
	int s1 = 0;
	int s2 = 0;
	for (int i=0; i<6; i++) {
		s += '0' + x % 10;
		if (i < 3) {
			s1 += x % 10;
		} else {
			s2 += x % 10;
		}
		x /= 10;
	}
	if (s1 != s2) {
		return string();
	}
	return s;
}

int diff(string a, string b) {
	int t = 0;
	for (int i=0; i<6; i++) {
		t += (a[i] != b[i] ? 1 : 0);
	}
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;

	int sol = 6;
	for (int i=0; i<1000000; i++) {
		string p = cc(i);
		if (p.size()) {
			sol = min(sol, diff(p, s));
		}
	}

	cout << sol;

}