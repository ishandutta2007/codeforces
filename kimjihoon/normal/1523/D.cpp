#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <time.h>
using namespace std;

int n, m, p, nn, c[1000009], rc[1000009], cb[1000009], mx = -1;
long long a[200009];
vector<int> v;
string ans = "";

void ps(int l)
{
	vector<int> bv;
	for (int i = 0; i < m; i++)
		if ((1LL << i) & a[l])
			bv.push_back(i);
	int bn = bv.size();
	cb[0] = 0;
	for (int i = 0; i < (1 << bn); i++) {
		c[i] = rc[i] = 0;
		if (i > 0) cb[i] = cb[i - (i & (-i))] + 1;
	}
	for (int i = 0; i < n; i++) {
		int s = 0;
		for (int j = 0; j < bn; j++)
			if ((1LL << bv[j]) & a[i])
				s += (1 << j);
		c[s]++;
	}
	cb[(1 << bn) - 1] = bn;
	for (int i = (1 << bn) - 1; i >= 0; i--) {
		if (c[i]) {
			for (int j = i; j > 0; j = (j - 1) & i)
				rc[j] += c[i];
			rc[0] += c[i];
		}
		if (rc[i] >= nn) {
			if (mx < cb[i]) {
				mx = cb[i];
				ans = "";
				for (int j = 0; j < m; j++)
					ans += "0";
				for (int j = 0; j < bn; j++)
					if ((1 << j) & i)
						ans[m - bv[j] - 1] = '1';
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> p;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++)
			a[i] = (a[i] * 2) + (long long)(s[j] - '0');
	}
	nn = (n + 1) / 2;
	srand(time(NULL));
	for (int i = 0; i < 50; i++) {
		int t = (1LL * rand() * (RAND_MAX + 1) + 1LL * rand()) % (1LL * n);
		ps(t);
	}
	cout << ans << '\n';
	return 0;
}