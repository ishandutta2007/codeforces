#include <bits/stdc++.h>
using namespace std;

int n;
long long k;
int w[100000], p[100000][34], m[100000][45];
long long s[100000][34];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> p[i][0];
	}
	for (int i=0; i<n; i++) {
		cin >> w[i];
		s[i][0] = m[i][0] = w[i];
	}
	for (int j=1; j<34; j++) {
		for (int i=0; i<n; i++) {
			s[i][j] = s[i][j-1] + s[p[i][j-1]][j-1];
			m[i][j] = min(m[i][j-1], m[p[i][j-1]][j-1]);
			p[i][j] = p[p[i][j-1]][j-1];
		}
	}
	for (int i=0; i<n; i++) {
		long long sum = 0;
		int mn = 123123123;
		int t = i;
		for (long long j=33; j>=0; j--) {
			if (k & (1ll << j)) {
				sum += s[t][j];
				mn = min(mn, m[t][j]);
				t = p[t][j];
			}
		}
		cout << sum << ' ' << mn << '\n';
	}
	
}