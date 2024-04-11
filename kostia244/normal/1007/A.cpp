#include<bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<int>;
using vpi = vector<pi>;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	map<int, int> cnt;
	for(int t = 0,i = 0; i < n; i++) cin >> t, cnt[t]++;
	int ans = n;
	for(auto i : cnt) ans = min(ans, n - i.second);
	cout << ans;
}