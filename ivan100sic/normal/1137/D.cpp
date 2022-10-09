#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool e[10][10];

void citaj() {
	int k;
	cin >> k;
	memset(e, 0, sizeof(e));
	while (k--) {
		string s;
		cin >> s;
		for (char x : s)
			for (char y : s)
				e[x-'0'][y-'0'] = 1;
	}
}

void pomeri(string s) {
	cout << "next";
	for (char x : s)
		cout << ' ' << x;
	cout << '\n' << flush;
	citaj();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int x = 0, t = 0, c = 0;
	while (1) {
		pomeri("01");
		pomeri("1");
		x++;
		if (e[0][1])
			break;
	}

	// nadji c
	while (1) {
		pomeri("13");
		if (e[0][1])
			break;
	}

	while (1) {
		pomeri("23456789");
		if (e[2][3])
			break;
	}

	while (!e[0][2]) {
		pomeri("01");
	}

	cout << "done\n" << flush;
}