#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 10100;
// const int N = 0;
int n, k, m, l, r, x, dp[2 * N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

struct asd {
	int l, r, x;

	bool operator<(asd &a) const {
		return r < a.r;
	}
}a[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> a[i].l >> a[i].r >> a[i].x;
	}	
	sort(a + 1,  a + m + 1);

	for(int i = 1; i <= m; i++) {
		for(int j = n; j > 0; j--) {
			if(a[i].l <= dp[j] && dp[j] <= a[i].r)
				dp[j + a[i].x] = max(dp[j], dp[j + a[i].x]);
		}
		dp[a[i].x] = a[i].r;
		// dbg_v(dp, n + 2);
	}

	vector <int> aa;
	for(int i = 1; i <= n; i++)
		if(dp[i])
			aa.push_back(i);
	cout << aa << '\n';
}