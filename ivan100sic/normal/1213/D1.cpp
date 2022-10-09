#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<int> b[200005];
int n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		int x, c = 0;
		cin >> x;
		do {
			b[x].push_back(c);
			c++;
			x >>= 1;
		} while (x != 0);
	}
	int z = 1e9;
	for (int i=0; i<200005; i++) {
		if ((int)b[i].size() < k)
			continue;
		nth_element(b[i].begin(), b[i].begin()+k, b[i].end());
		z = min(z, accumulate(b[i].begin(), b[i].begin()+k, 0));
	}
	cout << z << '\n';
}