#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int resi(string s, int moves) {
	map<char, int> mp;
	for (char x : s)
		mp[x]++;

	vector<int> f;
	for (auto p : mp)
		f.push_back(p.second);

	sort(f.begin(), f.end(), greater<int>());

	int razno = accumulate(f.begin() + 1, f.end(), 0);

	if (moves <= razno)
		return f[0] + moves;
	else {
		// resenje je zbir ili zbir-1
		// ako postoji slovo cija je frekvencija dobra na parnost
		// i dostizna onda je zbir

		int zbir = razno + f[0];

		if (moves >= razno+2)
			return zbir; // tricikl

		if (razno > 0)
			return zbir;

		return zbir - 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	string a, b, c;
	cin >> n >> a >> b >> c;
	int x, y, z;
	x = resi(a, n);
	y = resi(b, n);
	z = resi(c, n);

	cerr << x << '\n';
	cerr << y << '\n';
	cerr << z << '\n';

	int mx = max({x, y, z});
	int cc = 0;
	if (x == mx)
		cc++;
	if (y == mx)
		cc++;
	if (z == mx)
		cc++;

	if (cc >= 2)
		cout << "Draw\n";
	else if (x == mx)
		cout << "Kuro\n";
	else if (y == mx)
		cout << "Shiro\n";
	else
		cout << "Katie\n";
}