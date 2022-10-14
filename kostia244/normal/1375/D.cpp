#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4.1,sse4.2,popcnt,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
const int maxn = 1<<18;
int mex(vector<int> a) {
	sort(all(a));
	int cur = 0;
	for(auto i : a) {
		if(i < cur) continue;
		if(i == cur) cur++;
		else return cur;
	}
	return cur;
}
bool S(vector<int> a) {
	for(int i = 1; i < a.size(); i++) if(a[i] < a[i-1]) return true;
	return false;
}
void solve() {
	int n;
	cin >> n;
	vector<int> a(n), op;
	for(auto &i : a) cin >> i;
	while(S(a)) {
		int f = mex(a);
		if(f == n) {
			for(int i = 0; i < n; i++) if(a[i] != i) {
				a[i] = f;
				op.pb(i);
				break;
			}
		} else {
			a[f] = f;
			op.pb(f);
		}
	}
	cout << op.size() << '\n';
	for(auto i : op) cout << i+1 << ' ';cout << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}