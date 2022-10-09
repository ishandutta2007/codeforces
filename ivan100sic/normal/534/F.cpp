#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int pw[6] = {1, 11, 121, 1331, 14641};

int n, m;
int b[20];
int len[32];
int tgt;

bitset<32> v[22][161051];
basic_string<int> st;

void dfs(int k, int ch, int last) {
	if (k == m && ch == tgt) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				cout << (((st[j] >> i) & 1) ? '*' : '.');
			}
			cout << '\n';
		}
		exit(0);
	} else if (k == m) {
		return;
	}

	if (v[k][ch][last])
		return;

	v[k][ch][last] = 1;

	for (int curr=0; curr<(1<<n); curr++) {
		if (len[curr] != b[k])
			continue;
		int s = curr & (curr ^ last), chnu = ch;
		for (int j=0; j<n; j++)
			if (s & (1 << j))
				chnu += pw[j];
		st += curr;
		dfs(k+1, chnu, curr);
		st.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<32; i++)
		len[i] = __builtin_popcount(i ^ (i << 1)) >> 1;

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		tgt += pw[i] * x;
	}

	for (int j=0; j<m; j++)
		cin >> b[j];

	dfs(0, 0, 0);
}