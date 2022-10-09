// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int a[1000005], n, m;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=n%2?n-2:n-1; i>=0; i-=2)
		a[m++] = i;
	for (int i=1; i<n; i+=2)
		a[m++] = i;

	for (int i=n%2?n-1:n-2; i>=2; i-=2)
		a[m++] = i;
	m++;
	for (int i=2; i<n; i+=2)
		a[m++] = i;
	m++;

	for (int i=0; i<m; i++)
		cout << n-a[i] << " \n"[i == m-1];
}