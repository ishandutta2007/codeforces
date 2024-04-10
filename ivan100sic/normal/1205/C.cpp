#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[55][55];
int b[55][55];

map<vector<int>, int> kes;

int ask(int a, int b, int c, int d) {
	vector<int> v = {a, b, c, d};
	if (kes.count(v))
		return kes[v];
	cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << '\n' << flush;
	cin >> a;
	return kes[v] = a;
}

template<class T>
void dfs(T s, int a, int b, int c, int d, string t, bool& ok) {
	t += (char)s[a][b];
	if (a == c && b == d) {
		string r = t;
		reverse(r.begin(), r.end());
		if (r == t)
			ok = true;
		return;
	}

	if (a+1 <= c)
		dfs(s, a+1, b, c, d, t, ok);
	if (b+1 <= d)
		dfs(s, a, b+1, c, d, t, ok);
}

template<class T>
bool ask_manual(T s, int a, int b, int c, int d) {
	bool ok = false;
	dfs(s, a, b, c, d, "", ok);
	return ok;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	memset(a, 0xff, sizeof(a));

	cin >> n;
	a[1][1] = 1;
	a[2][1] = 0;
	a[n][n] = 0;
	{
		a[2][2] = ask(1, 1, 2, 2);
		// pretpostavimo da je (2,1) = 0
		a[2][3] = ask(2, 1, 2, 3) ^ 1;
		a[1][2] = ask(1, 2, 2, 3) ^ a[2][3] ^ 1;
	}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (a[i][j] == -1) {
				int x = i, y = j;
				if (i >= 3)
					x -= 2;
				else if (j >= 3)
					y -= 2;
				else
					x--, y--;
				a[i][j] = ask(x, y, i, j) ^ a[x][y] ^ 1;
			}
		}
	}

	// da li sam pogresio sa a[2][1]?
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			b[i][j] = a[i][j];
			if ((i+j)%2)
				b[i][j] ^= 1;
		}
	}

	for (int i=1; i<=n; i+=2) {
		if (a[i][i] != a[i+2][i+2]) {
			bool oka = true;
			if (ask(i, i, i+1, i+2) != ask_manual(a, i, i, i+1, i+2))
				oka = false;
			if (oka && ask(i, i, i+2, i+1) != ask_manual(a, i, i, i+2, i+1))
				oka = false;
			if (oka && ask(i+1, i, i+2, i+2) != ask_manual(a, i+1, i, i+2, i+2))
				oka = false;

			// valjda su dovoljna ova tri?
			if (!oka)
				memcpy(a, b, sizeof(a));

			break;
		}
	}


	// zavrsi
	cout << "!\n";
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++)
			cout << a[i][j];
		cout << '\n';
	}
	cout << flush;
}