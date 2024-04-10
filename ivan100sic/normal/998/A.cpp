#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[25];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	
	if (n == 1 || (n == 2 && a[0] == a[1])) {
		cout << -1;
		return 0;
	}

	int j = min_element(a, a+n) - a;

	cout << "1 " << j+1;
}