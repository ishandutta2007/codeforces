#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 100100;
int n, k, a[N], sum, q[N], m;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin >> m;
	for(int i = 1; i <= m; i++)
		cin >> q[i];

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], sum += a[i];

	sort(a + 1, a + n + 1);
	sort(q + 1, q + m + 1);

	int i = 1;
	while(n && i <= m) {
		if(n < q[i]) break;

		n -= q[i];
		// dbg(n);

		if(n) sum -= a[n--];
		if(n) sum -= a[n--];
		// dbg(n);
		// i++;
	}

	// int l = 1, r = n, i = 1;
	// while(l <= r) {
	// 	if(q[i] >= r - l + 1)
	// 		break;

	// 	r--;
	// 	l += q[i] - 1;

	// 	if(l <= r) {
	// 		sum -= a[r];
	// 		r--;
	// 	}

	// 	i++;
	// }

	cout << sum << '\n';
}