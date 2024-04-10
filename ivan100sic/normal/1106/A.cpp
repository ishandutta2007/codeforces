#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, z;
string a[505];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	for (int i=1; i<n-1; i++)
		for (int j=1; j<n-1; j++) 
			if (a[i][j] == 'X' && a[i-1][j-1] == 'X' &&
				a[i-1][j+1] == 'X' && a[i+1][j-1] == 'X' && a[i+1][j+1] == 'X')
			{
				z++;
			}

	cout << z << '\n';
}