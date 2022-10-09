#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[1005], b[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i] >> b[i];
		if (a[i] != b[i]) {
			cout << "rated\n";
			return 0;
		}
	}

	reverse(a, a+n);
	if (is_sorted(a, a+n))
		cout << "maybe\n";
	else
		cout << "unrated\n";

}