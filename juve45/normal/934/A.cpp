#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

long long n, k, x, m, a[55], b[55], ans[16];
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	for(int i = 1; i <= m; i++)
		cin >> b[i];

	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);

	long long ans1 = -1000000000000000000LL;
	long long ans2 = -1000000000000000000LL;

	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			ans1 = max(ans1, a[i] * b[j]);
		}
	}

	for(int i = 1; i < n; i++) {
		for(int j = 1; j <= m; j++) {
			ans2 = max(ans2, a[i] * b[j]);
		}
	}

	cout << min(ans1, ans2);
}