// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[100005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	if (a[0] == a[2]) {
		int x = count(a, a+n, a[0]);
		cout << x*(x-1ll)*(x-2) / 6 << '\n';
	} else if (a[0] == a[1]) {
		cout << count(a, a+n, a[2])<< '\n';
	} else if (a[1] == a[2]) {
		int x = count(a, a+n, a[1]);
		cout << x*(x-1ll) / 2 << '\n';
	} else {
		cout << count(a, a+n, a[2])<< '\n';
	}
}