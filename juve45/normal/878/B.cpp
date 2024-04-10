#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 100100
#define NMAX 
#define MMAX 

using namespace std;

long long n, k, a[DMAX], c[DMAX], m, total, lhs, rhs, ans;

template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k >> m;
	for(long long i = 1; i <= n; i++)
		cin >> a[i], total += a[i];

	total = n * m;
	stack<pair<long long, long long> > s;

	for(long long i = 1; i <= n; i++) {
		if(!s.empty() && s.top().st == a[i]) {
			s.top().nd++;
			if(s.top().nd == k) s.pop();
		}
		else {
			s.push({a[i], 1});
		}
	}
	n = 0;
	while(!s.empty()) {
		++n;
		a[n] = s.top().st;
		c[n] = s.top().nd;
		s.pop();
	}
	dbg_v(a, n + 1);
	dbg_v(c, n + 1);

	long long i = 1, j = n;

	dbg_ok;
	while(i < j) {
		if(a[i] == a[j]) {
			if(c[i] + c[j] == k) {
				lhs += c[i];
				rhs += c[j];
			} else if(c[i] + c[j] > k) {
				// ans += c[i] + c[j] - k;
				lhs += c[i];
				rhs += k - c[i];
				c[j] -= k - c[i];
				i++;
				break; /// zrtx
			} else break;

		}
		else break;
		i++; j--;
	}
	dbg(i);
	dbg(j);
	dbg(ans);
	dbg(lhs);
	dbg(rhs);
	if(i == j) { // e impar.
		// if(ans != 0) cout << (ans + c[i]) * m + lhs + rhs + k << '\n';
		if(c[i] * m % k == 0) cout << 0 << '\n';
		else cout << lhs + rhs + (c[i] * m) % k << '\n';
		return 0;
	}
	if(i > j) {
		cout << 0 << '\n';
		return 0;
	}

	for(; i <= j; i++)
		ans += c[i];
	ans *= m;
	// ans += k;
	cout << ans + lhs + rhs << '\n';
}