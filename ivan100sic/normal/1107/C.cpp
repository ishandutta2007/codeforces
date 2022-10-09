#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[200005];
ll sol;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	cin >> s;
	s = string(" ") + s;

	for (int i=1; i<=n; i++) {
		int j = i;
		while (j+1 <= n && s[j+1] == s[i])
			j++;
		sort(a+i, a+j+1, greater<int>());
		for (int l=i; l<=min(i+k-1, j); l++)
			sol += a[l];
		i = j;
	}

	cout << sol << '\n';
}