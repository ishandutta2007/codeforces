#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct stvar {
	int len;
	char x;
	stvar() {}
	stvar(char c) : len(1), x(c) {}
};

void dodaj(vector<stvar>& a, stvar b) {
	if (a.size() && a.back().x == b.x) {
		a.back().len += b.len;
	} else {
		a.push_back(b);
	}
}

stvar extr(vector<stvar>& a) {
	stvar t = a.back();
	a.pop_back();
	return t;
}

template<class T>
vector<pair<int, int>> solve_greedy(T u, T v) {
	vector<pair<int, int>> sol;

	while (1) {
		int x = u.size(), y = v.size(), d = u.back().x == v.back().x;
		if (d == 0) {
			if (x == y) {
				if (x == 1)
					break;
				runswap(1, 1, u, v, sol);
			} else if (x > y) {
				runswap((x-y)/2+1, 1, u, v, sol);
			} else {
				runswap(1, (y-x)/2+1, u, v, sol);
			}
		} else if (x > y) {
			runswap(1, 0, u, v, sol);
		} else {
			runswap(0, 1, u, v, sol);
		}
	}

	return sol;
}

template<class T, class U>
void runswap(int x, int y, T&u, T& v, U& sol) {
	if (x == 0 && y == 0)
		return;
	vector<stvar> p, q;
	while (x--)
		p.push_back(extr(u));
	while (y--)
		q.push_back(extr(v));
	reverse(p.begin(), p.end());
	reverse(q.begin(), q.end());
	int a = 0, b = 0;
	for (stvar z : p)
		dodaj(v, z), a += z.len;
	for (stvar z : q)
		dodaj(u, z), b += z.len;
	sol.emplace_back(a, b);
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	vector<stvar> u, v;

	for (char x : a)
		dodaj(u, stvar(x));
	for (char x : b)
		dodaj(v, stvar(x));

	int rev = 0;
	if (u.size() < v.size()) {
		swap(u, v);
		rev = 1;
	}

	vector<pair<int, int>> naj = solve_greedy(u, v);

	{
		int x = u.size(), y = v.size();
		for (int i=1+(x-y)/2-6; i<=1+(x-y)/2+6; i++) {
			if (i < 0 || i >= x)
				continue;

			vector<pair<int, int>> mali;
			auto uu = u, vv = v;
			runswap(i, y > 1, uu, vv, mali);
			auto sol = solve_greedy(uu, vv);
			mali.insert(mali.end(), sol.begin(), sol.end());

			if (mali.size() < naj.size()) {
				swap(naj, mali);
			}
		}
	}

	cout << naj.size() << '\n';
	for (auto [x, y] : naj) {
		if (rev)
			swap(x, y);
		cout << x << ' ' << y << '\n';
	}
}