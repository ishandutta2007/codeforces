#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n;
	map<int, int> cnt;
	cin >> n;
	int ans = 0;
	cnt[0]++;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		if(++cnt[t] != 1) {
			ans++;
		}
	}
	cout << ans;
}