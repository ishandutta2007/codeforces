#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

long long n, k;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	int y = 0;
	long long ans = 0;
	for(int i = -n; i < 0; i++) {
		int nr = 0;
		while(1LL * i * i + 1LL * (y + 1) * (y + 1) <= 1LL * n * n)
			y++, nr++;
		ans += max(nr, 1);
	}

	cout << max(ans * 4LL, 1LL) << '\n';
}