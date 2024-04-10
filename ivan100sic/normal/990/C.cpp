#include <bits/stdc++.h>
using namespace std;

struct bra {
	int sum, dip;
};

bra proc(string s) {
	bra b = {0, 0};
	for (char x : s) {
		if (x == '(')
			b.sum++;
		else
			b.sum--;
		b.dip = min(b.dip, b.sum);
	}
	return b;
}

int n;
bra a[300005];
map<int, vector<int>> e;

long long sol = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// ja sam

	cin >> n;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		a[i] = proc(s);
	}

	for (int i=0; i<n; i++)
		e[a[i].sum].push_back(a[i].dip);

	// 0
	{
		int c = count(e[0].begin(), e[0].end(), 0);
		sol += c * 1ll * c;
	}

	// != 0
	for (int i=1; i<=300000; i++) {
		int c1 = count(e[i].begin(), e[i].end(), 0);
		int c2 = count_if(e[-i].begin(), e[-i].end(), 
			[&](int x) { return x >= -i; }
		);
		sol += c1 * 1ll * c2;
	}

	cout << sol << '\n';
}