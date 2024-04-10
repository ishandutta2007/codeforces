#include <bits/stdc++.h>
using namespace std;

const int MAXN=2e5, MAXK=1e6;
int n, k, d, a[MAXN], c[MAXK];

void solve() {
	cin >> n >> k >> d;
	memset(c, 0, 4*k);
	for(int i=0; i<n; ++i) {
		cin >> a[i], --a[i];
	}
	int ans=k, ca=0;
	for(int i=0; i<d-1; ++i) {
		if(!c[a[i]]) {
			++ca;
		}
		++c[a[i]];
	}
	for(int i=d-1; i<n; ++i) {
		if(!c[a[i]]) {
			++ca;
		}
		++c[a[i]];
		ans=min(ca, ans);
		--c[a[i-d+1]];
		if(!c[a[i-d+1]]) {
			--ca;
		}
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}