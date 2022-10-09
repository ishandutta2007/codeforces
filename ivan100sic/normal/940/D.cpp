#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005];
string b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	cin >> b;

	int l = -1000000000;
	int r = +1000000000;

	for (int i=4; i<n; i++) {
		if (b.substr(i-4, 5) == "00001")
			l = max(l, *max_element(a+i-4, a+i+1) + 1);
		else if (b.substr(i-4, 5) == "11110")
			r = min(r, *min_element(a+i-4, a+i+1) - 1);
	}
	cout << l << ' ' << r << '\n';
}