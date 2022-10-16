#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 100100;
int n, k, a[N], b[N], dp[N], p[N], aa[N], bb[N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

bool cmp(int x, int y) {
	return aa[x] < aa[y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> aa[i] >> bb[i], p[i] = i;

	sort(p + 1, p + n + 1, cmp);

	// dbg_v(p, n + 1);

	for(int i = 1; i <= n; i++)
		a[i] = aa[p[i]],
		b[i] = bb[p[i]];

	dp[0] = 0;
	a[0] = -1e7;
	for(int i = 1; i <= n; i++) {
		int ind = lower_bound(a, a + n + 1, a[i] - b[i]) - a;
		ind--;
		dp[i] = dp[ind] + 1;
	}
	cout << n - *max_element(dp, dp + n + 1) << '\n';
}