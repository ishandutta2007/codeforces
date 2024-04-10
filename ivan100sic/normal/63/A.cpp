#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string a[105], b[105];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i] >> b[i];

	for (int i=0; i<n; i++)
		if (b[i] == "rat")
			cout << a[i] << '\n';
	for (int i=0; i<n; i++)
		if (b[i] == "woman" || b[i] == "child")
			cout << a[i] << '\n';
	for (int i=0; i<n; i++)
		if (b[i] == "man")
			cout << a[i] << '\n';
	for (int i=0; i<n; i++)
		if (b[i] == "captain")
			cout << a[i] << '\n';
}