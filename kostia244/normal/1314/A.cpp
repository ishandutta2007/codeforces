#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	for(auto &i : a) cin >> i[0];
	for(auto &i : a) cin >> i[1];
	sort(all(a));
	ll sm = 0, ans = 0;
	multiset<int> vals;
	for(int i = 0, j = 0; vals.size() || i < a.size(); j++) {
		if(!vals.size()) j = a[i][0];
		while(i < a.size() && a[i][0] <= j) {
			vals.insert(a[i][1]);
			sm += a[i][1];
			i++;
		}
		sm -= *vals.rbegin();
		vals.erase(vals.find(*vals.rbegin()));
		ans += sm;
	}
	cout << ans << '\n';
}