#include <bits/stdc++.h>
using namespace std;

bool is_perm(vector<int> p) {
	int n = p.size();
	vector<int> c(n, 0);
	for (int x : p) {
		if (x < 0 || x >= n) {
			return false;
		}
		c[x]++;
		if (c[x] == 2) {
			return false;
		}
	}
	return true;
}

vector<int> inverz(vector<int> p) {
	int n = p.size();
	vector<int> q(n);
	for (int i=0; i<n; i++) {
		q[p[i]] = i;
	}
	return q;
}

map<pair<int, int>, int> cache;

int ask(int x, int y) {
	auto it = cache.find({x, y});

	if (it != cache.end()) {
		return it->second;
	}

	int& sol = cache[{x, y}];

	cout << "? " << x << ' ' << y << '\n' << flush;
	cin >> sol;

	return sol;
}

void ans(int x, vector<int> v) {
	cout << "!\n" << x << '\n';
	for (int y : v) {
		cout << y << ' ';
	}
	cout << '\n' << flush;
	exit(0);
}

int n;

int p[5005], q[5005];

vector<int> sol;
vector<int> inv;
vector<int> gud;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		p[i] = ask(0, i);
		q[i] = ask(i, 0);
	}

	int lzc = 0;
	{
		int t = n;
		while (t % 2 == 0) {
			t /= 2;
			lzc++;
		}
	}

	int valid = 0;
	// 0 se slika u temp
	for (int bag=0; bag<n; bag++) {
		inv.resize(n);

		for (int i=0; i<n; i++) {
			inv[i] = p[i] ^ bag;
		}
		
		/*
		for (int x : inv) {
			cerr << x << ' ';
		}
		cerr << '\n';
		*/

		if (!is_perm(inv)) {
			continue;
		}

		sol = inverz(inv);

		/*
		for (int x : sol) {
			cerr << x << ' ';
		}
		cerr << '\n';
		*/
		// validacija

		bool ok = true;

		for (int i=0; i<n; i++) {
			if (q[i] != (sol[i] ^ inv[0])) {
				ok = false;
			}
		}

		for (int i=0; i<n; i++) {
			if (p[i] != (sol[0] ^ inv[i])) {
				ok = false;
			}
		}

		if (ok) {
			gud = sol;
			valid++;
		}
	}

	ans(valid, gud);
}

/*
3 5 6 7 0 1 2 4 
4 5 6 0 7 1 2 3

7
6
1
5
2
3
3
4
4
2
5
1
6
0
0

*/