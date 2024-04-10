#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int M = 1'000'000'007;

int n;
string s;
int lcp[5005][5005];
int dp_cnt[5005][5005];
int dp_min[5005][5005];

int cmp(int x, int y, int l) {
	if (x == y)
		return 0;
	int z = lcp[x][y];
	if (z >= l)
		return 0;
	if (x+z == n || y+z == n)
		return x > y ? -1 : 1;
	return s[x+z] < s[y+z] ? -1 : 1;
}

int rb(int i, int j) {
	if (j+(j-i) > n)
		return -1;

	if (cmp(i, j, j-i) <= 0)
		return j+(j-i);

	if (j+(j-i)+1 > n)
		return -1;

	return j+(j-i)+1;
}

void mn(int& x, int y) {
	x = min(x, y);
}

void ad(int& x, int y) {
	x += y;
	if (x >= M)
		x -= M;
}

string binary_add(string s, string p) {
	if (s.size() > p.size())
		swap(s, p);

	s = string(p.size() - s.size() + 1, '0') + s;
	p = string("0") + p;
	for (int i=0; i<(int)s.size(); i++)
		s[i] += p[i] - '0';
	for (int i=s.size()-1; i>=1; i--)
		if (s[i] >= '2')
			s[i] -= 2, s[i-1] += 1;
	int j = 0;
	while (s[j] == '0') j++;
	return s.substr(j);
}

string binary_min(string s, string p) {
	if (s.size() < p.size())
		return s;
	if (s.size() > p.size())
		return p;
	return s < p ? s : p;
}

string itostr(int x) {
	string s;
	while (x) {
		s += (x & 1) + '0';
		x >>= 1;
	}
	reverse(s.begin(), s.end());
	return s;
}

int stoimod(string s) {
	int z = 0;
	for (char x : s) {
		ad(z, z);
		ad(z, x - '0');
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	n = s.size();
	memset(dp_min, 63, sizeof(dp_min));
	for (int i=n-1; i>=0; i--)
		for (int j=n-1; j>=0; j--)
			if (s[i] == s[j])
				lcp[i][j] = 1 + lcp[i+1][j+1];

	dp_min[0][0] = 0;
	dp_cnt[0][0] = 1;
	// propagiraj
	for (int i=0; i<n; i++) {
		for (int j=i; j<n; j++) {
			if (dp_min[i][j] < 1231231 && s[j] == '1') {
				int k = j ? rb(i, j) : 1;
				if (k != -1) {
					// cerr << "dp " << i << ' ' << j << ' ' << k << '\n';
					mn(dp_min[j][k], dp_min[i][j] + 1);
					ad(dp_cnt[j][k], dp_cnt[i][j]);			
				}
			}
			if (j) {
				mn(dp_min[i][j+1], dp_min[i][j]);
				ad(dp_cnt[i][j+1], dp_cnt[i][j]);
			}
		}
	}

	int tot_cnt = 0;
	for (int j=0; j<n; j++)
		ad(tot_cnt, dp_cnt[j][n]);

	cout << tot_cnt << '\n';

	string best = string(n+3, '1');
	for (int j=0; j<n; j++)
		if (dp_min[j][n] < 1231231) {
			string cand = itostr(dp_min[j][n]);
			// cerr << j << ' ' << s.substr(j) << ' ' << dp_min[j][n] << '\n';
			cand = binary_add(cand, s.substr(j));
			best = binary_min(best, cand);
		}
	cout << stoimod(best) << '\n';
}