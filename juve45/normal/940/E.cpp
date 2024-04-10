#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const long long N = 100100;
long long n, k, a[N], s[N], dp[N], sum, c;

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
	cin >> n >> c;
		
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}

	if(c > n) {
		cout << s[n] << '\n';
		return 0;
	}

	deque <long long> mn;
	for(long long i = 1; i < c; i++) {
		sum += a[i];
		dp[i] = dp[i - 1] + a[i];

		while(!mn.empty() && a[mn.back()] >= a[i])
			mn.pop_back();
		mn.push_back(i);
	}

	for(long long i = c; i <= n; i++) {
			
		sum += a[i];
		sum -= a[i - c];

		while(!mn.empty() && mn.front() <= i - c) mn.pop_front();

		while(!mn.empty() && a[mn.back()] >= a[i])
			mn.pop_back();
		mn.push_back(i);

		dp[i] = min(dp[i - 1] + a[i], dp[i - c] + sum - a[mn.front()]);
	}
	
	cout << dp[n] << '\n';
}