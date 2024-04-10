#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;
int p[105], s[105];
int hs[105];
bool ch[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=1; i<=n; i++)
		cin >> p[i];
	for (int i=1; i<=n; i++) {
		cin >> s[i];
		hs[s[i]] = max(hs[s[i]], p[i]);
	}
	for (int i=0; i<k; i++) {
		int x;
		cin >> x;
		ch[x] = 1;
	}

	int z = 0;
	for (int i=1; i<=n; i++) {
		if (ch[i] && p[i] != hs[s[i]])
			z++;
	}

	cout << z << '\n';
}