#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define all(x) x.begin(), x.end()
#define mod 1000000007ll
//using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
//#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//#endif
}

typedef long long ll;
typedef double ld;
typedef pair<ll, ll> pi;
typedef map<int, int> mii;
typedef __V<ll> vi;
typedef __V<pi> vpi;
typedef __V<pi> vvi;
typedef __V<__V<pi>> vvpi;

ll n, k, sum = 0;
vpi v;

struct cmp1 {
	bool operator() (const pi& a, const pi& b) {
		return a.first < b.first || (a.first == b.first && a.second < b.second);
	}
};
struct cmp2 {
	bool operator() (const pi& a, const pi& b) {
		return a.second > b.second || (a.second == b.second && a.first > b.first);
	}
};
ll ans;
multiset<pi, cmp1> st;
int main() {
	doin();
	cin >> n >> k;
	v.resize(n);
	for(auto& i : v) cin >> i.first >> i.second;
	sort(all(v), [](const pi& a, const pi& b) {
		return a.second > b.second || (a.second == b.second && a.first > b.first);
	});
	for(int i = 0; i < n; i++) {
		st.insert(v[i]);
		sum += v[i].first;
		if(st.size() > k)
			sum -= st.begin()->first, st.erase(st.begin());
		ans = max(v[i].second * sum, ans);
	}
	cout << fixed << ans;
}