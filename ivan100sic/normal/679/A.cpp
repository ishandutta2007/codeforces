#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<int> p = {
	 2,  3,  5,  7, 11,
	13, 17, 19, 23, 29,
	31, 37, 41, 43, 47,
	53, 59, 61, 67, 71,
	73, 79, 83, 89, 97
};

void ans(string s) {
	cout << s << '\n' << flush;
	exit(0);
}

bool ask(int x) {
	cout << x << '\n' << flush;
	string s;
	cin >> s;
	return s == "yes";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int c = 0;
	int deljiv_sa = -1;

	for (int x : p) {
		if (deljiv_sa != -1 && x * deljiv_sa > 100)
			continue;

		if (deljiv_sa == -1 && x > 10)
			continue;

		if (ask(x)) {
			if (c == 1)
				ans("composite");
			deljiv_sa = x;
			c = 1;
		}
	}

	if (deljiv_sa != -1 && deljiv_sa < 10)
		if (ask(deljiv_sa * deljiv_sa))
			ans("composite");

	ans("prime");
}