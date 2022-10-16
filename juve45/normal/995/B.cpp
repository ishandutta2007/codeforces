#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

int n, k, b, ans, a[222];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	ans = n;
	for(int i = 1; i <= 2 * n; i++) {
		cin >> a[i];
	}

	int ans = 0;
	for(int i = 1; i <= 2 * n; i += 2) {
		int j = i + 1;
		while(a[i] != a[j]) j++;
		while(a[i] != a[i+1]) {
			swap(a[j], a[j - 1]);
			j--;
			ans++;
		}
	}
	cout << ans << '\n';
}