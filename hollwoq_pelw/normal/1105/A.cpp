#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; ++i)
		cin >> a[i];
	array<int, 2> ans={INT_MAX};
	for(int t=1; t<=100; ++t) {
		int ca=0;
		for(int i=0; i<n; ++i)
			ca+=max(abs(a[i]-t)-1, 0);
		ans=min(array<int, 2>{ca, t}, ans);
	}
	cout << ans[1] << " " << ans[0];
	return 0;
}