#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005], o[2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		o[a[i] % 2]++;
	}
	if (o[0] && o[1])
		sort(a, a+n);
	for (int i=0; i<n; i++)
		cout << a[i] << ' ';

}