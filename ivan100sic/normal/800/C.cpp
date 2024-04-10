#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int gcd(int a, int b) {
	int t;
	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int eea(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	int u, v;
	int r = eea(b, a % b, u, v);
	x = v;
	y = u - (a/b) * v;
	return r;
}

bool ok[200005];
vector<int> klase[200005];
set<int> postoji;
vector<int> x;
vector<int> dp;
vector<int> izb;

vector<int> odabrani;

int k;
int eulerphi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;
	fill(ok, ok+m, true);
	while (n--) {
		int x;
		cin >> x;
		ok[x] = false;
	}

	if (m == 1) {
		// n je bilo 0
		cout << "1\n0";
		return 0;
	}

	for (int i=0; i<m; i++) {
		int g = gcd(i, m);
		if (ok[i]) {
			klase[g].push_back(i);
			postoji.insert(g);
		}
		if (g == 1) {
			eulerphi++;
		}
	}

	x = vector<int>(postoji.begin(), postoji.end());
	k = x.size();
	dp.resize(k, 0);
	izb.resize(k, -1);

	for (int i=0; i<k; i++) {
		for (int j=0; j<i; j++) {
			if (x[i] % x[j] == 0) {
				if (dp[j] > dp[i]) {
					izb[i] = j;
					dp[i] = dp[j];
				}
			}
		}
		dp[i] += klase[x[i]].size();
	}

	int maxv=-1, maxp=0;
	for (int i=0; i<k; i++) {
		if (dp[i] > maxv) {
			maxp = i;
			maxv = dp[i];
		}
	}

	cout << maxv << '\n';

	// krecemo od klase na poziciji i
	{
		int p = maxp;
		while (p != -1) {
			for (int a : klase[x[p]]) {
				odabrani.push_back(a);
			}
			p = izb[p];
		}
	}

	reverse(odabrani.begin(), odabrani.end());

	/*
	for (int x : odabrani) {
		cerr << x << ' ';
	}
	cerr << '\n';
	*/

	int p = 1;
	for (int x : odabrani) {
		int t1, t2;
		int g = eea(p, m, t1, t2);
		t1 = (t1 * 1ll * (x / g)) % m;
		if (t1 < 0) {
			t1 += m;
		}
		cout << t1 << ' ';
		p = (p * 1ll * t1) % m;
	}
}