#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int p[200005], q[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string a, b;
	cin >> a >> b;
	int n = a.size(), m = b.size();

	int j = 0;
	for (int i=0; i<m; i++) {
		while (a[j] != b[i])
			j++;
		j++;
		p[i+1] = j;
	}

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	j = 0;
	for (int i=0; i<m; i++) {
		while (a[j] != b[i])
			j++;
		j++;
		q[i+1] = j;
	}

	int z = 0;
	for (int i=0; i<=m; i++)
		z = max(z, n-p[i]-q[m-i]);
	cout << z << '\n';
}