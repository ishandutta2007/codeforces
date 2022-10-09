#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int M = 1'000'000'007;

int& ad(int& x, int y) {
	if ((x += y) >= M)
		x -= M;
	return x;
}

int dp[105][2666];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	dp[0][0] = 1;
	for (int i=0; i<=100; i++)
		for (int j=0; j<=2600; j++)
			for (int k=0; k<26; k++)
				ad(dp[i+1][j+k], dp[i][j]);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size(), z = 0;
		for (char x : s) {
			z += x - 'a';
		}
		cout << (dp[n][z] + M - 1) % M << '\n';
	}
}