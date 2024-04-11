#include<bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
void solve() {
	int n, t;
	set<int> a;
	cin >> n;
	while(n--) cin >> t, a.insert(t);
	cout << a.size() << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}