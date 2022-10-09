#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int d[105][105];
int v[1000005], m;
int p[1000005], q[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		for (int j=0; j<n; j++)
			d[i][j] = s[j] == '0' ? 123123123 : 1;
	}

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			for (int k=0; k<n; k++)
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);

	cin >> m;
	for (int i=0; i<m; i++) {
		cin >> v[i];
		v[i]--;
	}
	
	p[0] = 1;
	for (int i=1; i<m; i++) {
		p[i] = 123123123;
		for (int j=max(0, i-n-1); j<i; j++) {
			if (d[v[j]][v[i]] == i-j && v[j] != v[i]) {
				if (p[i] > p[j] + 1) {
					p[i] = p[j] + 1;
					q[i] = j;
				}
			}
		}
	}

	cout << p[m-1] << '\n';
	vector<int> r;
	for (int x=m-1; x; x=q[x])
		r.push_back(x);
	r.push_back(0);
	reverse(r.begin(), r.end());
	for (int x : r)
		cout << v[x]+1 << ' ';
}