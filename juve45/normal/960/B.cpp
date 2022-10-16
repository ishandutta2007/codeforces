#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 1010
#define NMAX 
#define MMAX 

using namespace std;

int n, k, a[DMAX], b[DMAX], k1, k2;

priority_queue<int> pq;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k1 >> k2;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i];	

	for(int i = 1; i <= n; i++) {
		pq.push(abs(a[i] - b[i]));
	}

	for(int i = 1; i <= k1 + k2; i++) {
		auto x = pq.top();
		pq.pop();
		pq.push(abs(x - 1));
	}

	long long ans = 0;
	while(!pq.empty()) {
		int x = pq.top();
		pq.pop();
		ans += 1LL * x * x;
	}

	cout << ans << '\n';
}