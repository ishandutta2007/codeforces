#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define dbg(x) cerr<<#x": "<<(x)<<endl
#define dbg_p(x) cerr<<#x": "<<(x).first<<' '<<(x).second<<endl
#define dbg_v(x, n) {cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<(x)[_]<<' ';cerr<<endl;}
#define all(v) v.begin(), v.end()
#define fi first
#define se second

template<typename T1, typename T2>
ostream& operator <<(ostream &out, const pair<T1, T2> &item) {
	out << '(' << item.first << ", " << item.second << ')';
	return out;
}

template<typename T>
ostream& operator <<(ostream &out, const vector<T> &v) {
	for(const auto &item : v) out << item << ' ';
	return out;
}

const int N = 200010;

ll a[N];

int main()
{
	ios_base::sync_with_stdio(false);
	
	int n;
	ll k, ans;

	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i];

	ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans += a[i] / k;
		a[i] %= k;

		if(a[i]) {
			a[i + 1] -= min(a[i + 1], k - a[i]);
			++ans;
		}
	}

	cout << ans << '\n';

	return 0;
}