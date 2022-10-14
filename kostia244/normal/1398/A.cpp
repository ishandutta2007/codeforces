//#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 3e5 + 33, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<array<int, 2>> a(n);
		for(int i = 0; i < n; i++) cin >> a[i][0], a[i][1] = 1+i;
		sort(all(a));
		if(a[0][0]+a[1][0]>a.back()[0]) {
			cout << "-1\n";
			continue;
		}
		cout << a[0][1] << " " << a[1][1] << " " << a.back()[1] << '\n';
	}
}