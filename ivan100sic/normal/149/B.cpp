#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int digit(char x) {
	if (isdigit(x))
		return x-'0';
	return x-'A'+10;
}

int parse(string s, int base) {
	int z = 0;
	for (char x : s) {
		int y = digit(x);
		if (y >= base)
			return -1;
		z = base * z + y;
	}
	return z;
}

bool singledigit(string s, int ub) {
	for (int i=0; i<(int)s.size()-1; i++)
		if (s[i] != '0')
			return false;
	return digit(s.back()) < ub;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	int sk = s.find(':');
	string a = s.substr(0, sk);
	string b = s.substr(sk+1);

	set<int> sol;

	for (int i=2; i<=77; i++) {
		int x = parse(a, i);
		int y = parse(b, i);
		if (0 <= x && x < 24 && 0 <= y && y < 60)
			sol.insert(i);
	}
	if (sol.size() == 0) {
		cout << "0\n";
		return 0;
	}

	if (singledigit(a, 24) && singledigit(b, 60)) {
		cout << "-1\n";
		return 0;
	}

	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}