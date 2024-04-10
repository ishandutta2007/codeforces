#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;

	vector<int> u;
	for (int n=1; n<=9; n++)
		for (int k=1; k<=9; k++)
			u.push_back(stoi(string(n, '0'+k)));

	while (t--) {
		int x, z=0;
		cin >> x;
		for (int y : u)
			z += x >= y;
		cout << z << '\n';
	}
}