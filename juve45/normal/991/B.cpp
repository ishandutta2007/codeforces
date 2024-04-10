#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 13;
int n, k, sum;
priority_queue<int>pq;
template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> k;
		pq.push(-k);
		sum += k;
	}

	int ans = 0;
	while(!pq.empty() && sum*2 < n*9) {
		sum += 5;
		sum += pq.top();
		pq.pop();
		ans++;
	}
	cout << ans << '\n';
}