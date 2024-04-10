#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[3][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			cin >> a[i][j];

	for (int k=1; k<=100000; k++) {
		a[0][0] = k;
		int z = a[0][0] + a[0][1] + a[0][2];
		a[1][1] = z - a[1][0] - a[1][2];
		a[2][2] = z - a[2][0] - a[2][1];

		if (a[0][0] + a[1][0] + a[2][0] == z)
		if (a[0][1] + a[1][1] + a[2][1] == z)
		if (a[0][2] + a[1][2] + a[2][2] == z)
		if (a[0][0] + a[1][1] + a[2][2] == z)
		if (a[2][0] + a[1][1] + a[0][2] == z)
		{
			for (int i=0; i<3; i++)
				for (int j=0; j<3; j++)
					cout << a[i][j] << " \n"[j == 2];
			return 0;
		}
	}
}