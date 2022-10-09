#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n;
ll v[100005];
ll t[100005], tz[100005];
ll zfull[100005], samo[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> v[i];
	}
	for (int i=1; i<=n; i++) {
		cin >> t[i];
		tz[i] = tz[i-1] + t[i];
	}

	for (int i=1; i<=n; i++) {
		auto it = lower_bound(tz+i, tz+n+1, tz[i-1] + v[i]) - tz;
		zfull[i]++;
		zfull[it]--;
		if (it <= n)
			samo[it] += (tz[i-1] + v[i]) - tz[it-1];
	}

	for (int i=1; i<=n; i++)
		zfull[i] += zfull[i-1];

	for (int i=1; i<=n; i++)
		cout << zfull[i] * t[i] + samo[i] << " \n"[i == n];
}