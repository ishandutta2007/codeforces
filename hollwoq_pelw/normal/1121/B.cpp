#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) cin >> i;

	vector<int> f((int)2e5 + 5);
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			++f[a[i]+a[j]];

	cout << *max_element(f.begin(), f.end());

	return 0;
}