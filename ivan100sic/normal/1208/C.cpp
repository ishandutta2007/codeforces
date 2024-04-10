#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[4][4] = {
	{8, 9 ,  1, 13},
	{3, 12,  7,  5},
	{0, 2 ,  4, 11},
	{6, 10, 15, 14}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			int b = a[i&3][j&3];
			b += 16*((i>>2)*(n/4) + (j>>2));
			cout << b << " \n"[j == n-1];
		}
	}
}