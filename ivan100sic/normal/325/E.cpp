#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

namespace brut {
	bool inst[1005];
	basic_string<int> st;
	basic_string<int> st2;
	int n;

	void dfs(int x, int k) {
		if (k == n && x == 0) {
			for (int x : st)
				cout << x << ' ';
			cout << "0\n";
			for (int x : st2)
				cout << x;
			cout << "\n";
			// exit(0);
			return;
		}

		if (k == n)
			return;

		if (inst[x])
			return;

		inst[x] = true;
		st += x;

		st2 += 0;
		dfs(2*x%n, k+1);
		st2.pop_back();
		st2 += 1;
		dfs((2*x+1)%n, k+1);
		st2.pop_back();

		st.pop_back();
		inst[x] = false;
	}

	void run() {
		cin >> n;
		dfs(0, 0);
	}
}

namespace sol {
	int n;
	basic_string<int> e[100005];

	list<pair<int, int>> euler(int x) {
		basic_string<int> u;
		list<pair<int, int>> v;
		while (e[x].size()) {
			u += x;
			int y = e[x].back();
			e[x].pop_back();
			v.emplace_back(x, y);
			x = y;
		}
		auto it = v.begin();
		for (int i=0; i<(int)u.size(); i++) {
			v.splice(it, euler(u[i]));
			++it;
		}
		return v;
	}

	void run() {
		cin >> n;
		if (n == 2) {
			cout << "0 1 0\n";
			return;
		}
		if (n % 2) {
			cout << "-1\n";
			return;
		}

		n /= 2;

		for (int i=0; i<n; i++) {
			e[i] += 2*i%n;
			e[i] += (2*i+1)%n;
		}
		auto v = euler(0);
		int x = 0;
		for (auto [a, b] : v) {
			cout << x << ' ';
			if (2*a%n == b)
				x = 2*x%(2*n);
			else
				x = (2*x+1)%(2*n);
		}
		cout << "0\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	sol::run();
	// brut::run();
}