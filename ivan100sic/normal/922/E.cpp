#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll w, b, x;
int c[1005];
ll cost[1005];
ll d[2][10005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> w >> b >> x;
	for (int i=0; i<n; i++)
		cin >> c[i];
	for (int i=0; i<n; i++)
		cin >> cost[i];

	memset(d, 128, sizeof d);
	d[0][0] = w;

	for (int i=0; i<n; i++) {
		auto ol = d[i%2];
		auto nu = d[(i+1)%2];
		memset(nu, 128, sizeof(d[0]));
		for (int j=0; j<10005; j++) {
			if (ol[j] < 0)
				continue;
			int hi = c[i];
			if (cost[i])
				hi = min<ll>(hi, ol[j] / cost[i]);
			for (int k=0; k<=hi; k++)
				nu[j+k] = max(nu[j+k], min(ol[j] - k*cost[i] + x, w + (j+k)*b));
		}
	}

	for (int i=10004; i>=0; i--)
		if (d[n%2][i] >= 0)
			return cout << i << '\n', 0;
}