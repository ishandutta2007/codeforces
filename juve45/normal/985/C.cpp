#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 100100;
int n, k, l, a[N];
priority_queue<int> pq;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	cin >> n >> k >> l;
	
	for(int i = 1; i <= n * k; i++)
		cin >> a[i];

	sort(a + 1, a + n * k + 1);

	long long ans = 0;
	int nr = 0, cnt = 0;
	for(int i = n * k; i >= 1; i--) {
		if(a[i] - a[1] > l) {
			nr++;
			continue;
		}

		if(nr >= k - 1) {
			nr -= k - 1;
			ans += 1LL * a[i];
			cnt++;
		} else {
			nr++;
		}
	}
	if(cnt == n)
		cout << ans << '\n';
	else 
		cout << 0 << '\n';
}