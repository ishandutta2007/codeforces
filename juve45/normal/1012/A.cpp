#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 200100;
long long n, k, a[N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= 2 * n; i++)
	 	cin >> a[i];

	 sort(a + 1, a + 2 * n + 1);
	 long long ans = (a[n] - a[1]) * (a[2 * n] - a[n + 1]);

	 for(int i = 2; i <= n; i++) {
	 	ans = min(ans, (a[2 * n] - a[1]) * (a[n + i - 1] - a[i]));
	 }
	 cout << ans << '\n';
}