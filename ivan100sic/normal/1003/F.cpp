#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string s[305];
bool eq[305][305];
int n;

int nointersect(vector<int>& a, int k) {
	int j = -1, c = 0;
	for (int i : a) {
		if (i > j) {
			c++;
			j = i+k;
		}
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> s[i];

	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			eq[i][j] = s[i] == s[j];

	int l0 = 0;
	for (int i=1; i<=n; i++)
		l0 += s[i].size();
	l0 += n-1;

	int sol = 0;

	for (int i=1; i<=n; i++) {
		vector<int> pos;
		for (int j=1; j<=n; j++)
			if (eq[i][j])
				pos.push_back(j);

		int k = 0;
		int tlen = 0;
		while (pos.size() > 1) {
			// ubaci res

			// cerr << i << ' ' << k << ' ' << nointersect(pos, k) << '\n';
			// cerr << ":: ";
			// for (int x : pos)
			// 	cerr << x << ' ';
			// cerr << '\n';

			tlen += s[i+k].size();
			int noice = nointersect(pos, k);
			if (noice > 1) {
				int usteda = nointersect(pos, k) * (tlen - 1);
				sol = max(sol, usteda);
			}
			// prosiri
			k++;
			vector<int> tmp;
			for (int p : pos) {
				if (i+k <= n && p+1 <= n && eq[i+k][p+1])
					tmp.push_back(p+1);
			}
			swap(pos, tmp);
		}
	}

	cout << l0 - sol << '\n';
}

/*
A A A A A A A 
AA AA AA aa
AAA AAA aa

*/