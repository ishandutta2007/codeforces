#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int t[4];

string sol[1005][1005];
int cs[2005], b[1005];

basic_string<int> pq[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			string s;
			cin >> s;
			int x = (s[0] - '0') + (s[1] - '0');
			t[x]++;
		}
	}

	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (t[2])
				t[2]--, sol[i][j] = "11", cs[2*j]++, cs[2*j+1]++;

	for (int j=0; j<m; j++)
		for (int i=0; i<n; i++)
			if (sol[i][j].empty()) {
				b[j] = i;
				break;
			}

	for (int j=0; j<m; j++) {
		if (b[j] < n) {
			pq[cs[2*j]] += 2*j;
			pq[cs[2*j+1]] += 2*j+1;
		}
	}

	for (int p=0; p<=n && t[1]; p++) {
		while (pq[p].size() && t[1]) {
			int j = pq[p].back();
			pq[p].pop_back();
			int& i = b[j >> 1]; // provera?
			if (i >= n)
				continue;
			// cerr << "pop " << p << ' ' << j << ' ' << i << '\n';
			if ((j & 1) == 0) {
				sol[i][j >> 1] = "10";
				cs[j]++;
				if (b[j] < n) pq[cs[j]] += j;
				i++;
			} else {
				sol[i][j >> 1] = "01";
				cs[j]++;
				if (b[j] < n) pq[cs[j]] += j;
				i++;
			}
			t[1]--;
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (sol[i][j].empty())
				sol[i][j] = "00";
			cout << sol[i][j] << ' ';
		}
		cout << '\n';
	}
}