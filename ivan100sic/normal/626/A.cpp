#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef complex<int> ci;

ci ord(char x) {
	if (x == 'U')
		return {1, 0};
	else if (x == 'R')
		return {0, 1};
	else if (x == 'L')
		return {0, -1};
	else if (x == 'D')
		return {-1, 0};
	return 0;
}

ci a[205];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, z=0;
	string s;
	cin >> n >> s;
	for (int i=0; i<n; i++)
		a[i+1] = a[i] + ord(s[i]);
	for (int i=0; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			if (a[i] == a[j])
				z++;
	cout << z << '\n';
}