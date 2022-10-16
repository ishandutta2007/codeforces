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

long long n, k, v[DMAX], s[DMAX], st[DMAX], t[DMAX], cnt[DMAX], off[DMAX];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

long long get_last_day(long long day) {
	long long total = v[day] + st[day - 1];
	long long last = lower_bound(st + 1, st + n + 1, total) - st;
	return last;
}

long long diff(long long sum, long long i, long long j) {
	return sum - (st[j - 1] - st[i - 1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(long long i = 1; i <= n; i++)
		cin	>> v[i];

	for(long long i = 1; i <= n; i++)
		cin	>> t[i];

	for(long long i = 1; i <= n; i++)
		st[i] = st[i - 1] + t[i];

	for(long long i = 1; i <= n; i++) {
		long long j = get_last_day(i);
		cnt[i]++;
		cnt[j]--;
		// dbg(i);
		// dbg(j);
		off[j] += diff(v[i], i, j);
		// dbg(diff(v[i], i, j));
	}

	for(long long i = 1; i <= n; i++) {
		cnt[i] += cnt[i - 1];
		cout << 1LL * cnt[i] * t[i] + off[i] << ' ';
	}
	return 0;
}