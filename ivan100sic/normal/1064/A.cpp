#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a, b, c;

bool istri(vector<int> a) {
	sort(a.begin(), a.end());
	return a[0] + a[1] > a[2];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> a >> b >> c;
	int sol = 123123123;
	for (int i=a; i<=123; i++)
		for (int j=b; j<=123; j++)
			for (int k=c; k<=123; k++)
				if (istri({i, j, k})) {
					sol = min(sol, i+j+k);
				}

	cout << sol-a-b-c;
}