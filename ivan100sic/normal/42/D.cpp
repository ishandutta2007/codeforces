#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// this was brute-forced
int a[20] = {0, 48, 495, 256, 16, 416, 44, 497, 455, 137,
	47, 370, 26, 361, 154, 104, 397, 484, 221, 213};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cout << (i == j ? 0 : a[i] + a[j]) << " \n"[j == n-1];		
}