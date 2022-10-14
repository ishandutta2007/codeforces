#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	set<array<int, 2>> L, R;
	for(int i = 0; i < n; i++) R.insert({a[i], i});
	for(int i = 0; i < n; i++) {
		R.erase({a[i], i});
		if(R.size() && L.size() && L.begin()->at(0) < a[i] && R.begin()->at(0) < a[i]) {
			cout << "YES\n";
			cout << L.begin()->at(1)+1 << " " << i+1 << " " << R.begin()->at(1)+1 << '\n';
			return;
		}
		L.insert({a[i], i});
	}
	cout << "NO\n";
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
}