#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, m = -1, t, ans = 0;
vector<ll> a;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	a.resize(n);
	for(auto& i : a)
		cin >> i;
	reverse(a.begin(), a.end());
	for(int i = 0; i < n; i++) {
		if(i > m)
			ans++;
		m = max(m, i + a[i]);
	}
	cout << ans;
}