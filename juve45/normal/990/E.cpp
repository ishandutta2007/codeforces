#include <bits/stdc++.h>

#define dbg(x) //cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 1000100;
int n, k, f[2 * N], last[2 * N], a[N], x, m, use[N];

long long ans = 1e18;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;

	int start = 2;
	long long noans = ans;

	for(int  i =1; i <= m; i++)
		cin >> x, f[x] = 1;

	for(int i = 1; i <= k; i++)
		cin >> a[i];

	if(f[0] == 1) {
		cout << "-1";
		return 0;
	}
	for(int i = 0; i <= 2 * n; i++) {
		if(f[i] == 0)
			last[i] = i;
		else 
			last[i] = last[i - 1], start = max(start, i - last[i]);
	}

	if(m == 0) {
		ans = 1LL * n * a[1];
	}

	for(int i = start; i <= k; i++) {

		int dr = 0, cnt = 0, ok = 1;

		while(dr < n) {
			dr += i;
			if(dr - last[dr] >= i) {
				ok = 0;
				break;
			}
			dr = last[dr];
			cnt++;
		}

		if(ok) {
			dbg(cnt);
			ans = min(ans, 1LL * cnt * a[i]);
		}
	}

	if(ans != noans)
		cout << ans << '\n';
	else 
		cout << "-1\n";

}