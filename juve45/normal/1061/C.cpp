#include <bits/stdc++.h> 

#define dbg(x) cerr<<#x": "<<x<<"\n"

#define st first
#define nd second

using namespace std;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(int i = 0; i < v.size(); i++) out << v[i] << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

const long long N = 100100;
const long long MOD = 1e9 + 7;
int ans = 0, n, a[N], dp[10 * N];


int main() {
	// freopen("mooyomooyo.in", "r", stdin);
	// freopen("mooyomooyo.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	dp[0] = 1;
	for(int i = 1; i <= n; i++) {
		vector <int> v;
		for(int j = 1; j * j <= a[i]; j++)
			if(a[i] % j == 0) {
				v.push_back(j);
				if(j * j != a[i])
					v.push_back(a[i] / j);
			}

		sort(v.begin(), v.end(), greater<int>());
		// dbg(v);
		for(int j = 0; j < v.size(); j++)
			dp[v[j]] += dp[v[j] - 1],
			dp[v[j]] %= MOD;
	}
	// dbg("faf");

	for(int i = 1; i <= n; i++)
		ans += dp[i], ans %= MOD;
	cout << ans << '\n';
}