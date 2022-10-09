// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const int W = 100'000'000;
const int B = 3200;

int ask(int x, int y) {
	cout << "0 " << x << ' ' << y << '\n' << flush;
	int z;
	cin >> z;
	if (z == -1) exit(0);
	return z;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	vector<pair<int, int>> init;
	for (int i=-W; i<=W; i+=B) {
		int z = ask(i, i);
		init.emplace_back(z, i);
	}

	int q = R::max_element(init)->second;

	vector<int> sol[2];
	// find first set of lines
	{
		int w = -W;
		while (w <= W) {
			int z = ask(w, q);
			if (z == 0) {
				sol[0].push_back(w);
				w += 1;
			} else {
				w += z;
			}
		}
	}

	int bestgap = 0, pos = 0;
	bestgap = sol[0][0] + W;
	pos = -W;

	if (W - sol[0].back() > bestgap) {
		bestgap = W - sol[0].back();
		pos = W;
	}

	for (int i : ra(1, ssize(sol[0]))) {
		int g = sol[0][i] - sol[0][i-1];
		if (g/2 > bestgap) {
			bestgap = g/2;
			pos = sol[0][i-1] + g/2;
		}
	}

	// find second set of lines recursively
	auto solve = [&](int l, int r, auto self) {
		if (l > r) return;

		int m = midpoint(l, r);
		int z = ask(pos, m);
		if (z == 0) sol[1].push_back(m);

		if (z == 0) {
			self(l, m-1, self);
			self(m+1, r, self);
		} else {
			self(l, m-z, self);
			self(m+z, r, self);
		}
	};

	solve(-W, W, solve);

	cout << "1 " << size(sol[0]) << ' ' << size(sol[1]) << '\n';
	for (auto& s : sol) {
		for (int x : s) {
			cout << x << ' ';
		}
		cout << '\n';
	}
	cout << flush;
}