#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const long long N = 500100;
long long n, k, a[N], sum;

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

bool can1(long long val) {
	long long req = 0;
	for(long long i = 1; i <= n; i++)
		if(a[i] < val)
			req += val - a[i];
	return req <= k;
}

bool can2(long long val) {
	long long req = 0;
	for(long long i = 1; i <= n; i++)
		if(a[i] > val)
			req += a[i] - val;
	return req <= k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(long long i = 1; i <= n; i++)
		cin >> a[i], sum += a[i];

	sort(a + 1, a + n + 1);

	// dbg(can2(2));

	long long l = 1;
	long long r = sum / n;
	while(l != r) {
		long long mid = (l + r + 1) / 2;
		if(can1(mid))
			l = mid;
		else 
			r = mid - 1;
	}
	long long low = l;

	l = (sum + n - 1) / n;
	r = 1e9;
	while(l != r) {
		long long mid = (l + r) / 2;
		if(can2(mid))
			r = mid;
		else 
			l = mid + 1;
	}
	long long high = l;
	// dbg(high);
	// dbg(low);
	cout << high - low << '\n';

}