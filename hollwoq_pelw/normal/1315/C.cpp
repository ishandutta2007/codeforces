#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	int b[n];
	for (int i = 0; i < n; ++i) cin >> b[i];
	int a[2 * n];
	set<int> s;
	for (int i = 1; i <= 2 * n; ++i) s.insert(i);
	for (int i = 0; i < n; ++i) s.erase(b[i]);
	for (int i = 0; i < n; ++i) {
		auto it = s.upper_bound(b[i]);
		if (it == s.end()) {
			cout << -1 << endl;
			return;
		}
		a[2 * i] = b[i];
		a[2 * i + 1] = *it;
		s.erase(it);
	}
	for (int i = 0; i < 2 * n; ++i)
		cout << a[i] << ' ';
	cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}