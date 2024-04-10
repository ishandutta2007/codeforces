#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int p[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=2; i<=n; i++)
		cin >> p[i];
	basic_string<int> sol;
	for (int x=n; x!=1; x=p[x])
		sol += x;
	reverse(sol.begin(), sol.end());
	cout << "1 ";
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}