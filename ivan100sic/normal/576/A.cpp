#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
vector<int> b;
int a[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=2; i<=n; i++) {
		if (a[i] == 0) {
			for (int j=2*i; j<=n; j+=i) {
				a[j]++;
			}
		}
	}
	for (int i=2; i<=n; i++)
		if (a[i] <= 1)
			b.push_back(i);
	cout << b.size() << '\n';
	for (int x : b)
		cout << x << ' ';
	cout << '\n';
}