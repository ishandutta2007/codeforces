#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 100100
#define KMAX 12 

using namespace std;

int n, k, x, a[DMAX];
long long ft[KMAX][DMAX];
string s;

int last2(int k) {
	return ((k^(k - 1))&k);
}

void upd(long long *ft, int pos, long long val) {
	for(int i = pos; i < DMAX; i += last2(i))
		ft[i] += val;
}

long long que(long long *ft, int pos) {
	long long ans = 0;
	for(int i = pos; i > 0; i-= last2(i)) 
		ans += ft[i];
	return ans;
}



template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if(k == 0) {
		cout << n << '\n';
		return 0;
	}

	// if(k > 0)
	// 	for(int i = 1; i <= n; i++)

	long long ans = 0;
	for(int j = 1; j <= n; j++) {
		upd(ft[1], a[j], 1);
		for(int i = 2; i <= k; i++) {
			long long x = que(ft[i - 1], a[j] - 1);
			// dbg(j);
			// dbg(x);
			upd(ft[i], a[j], x);
		}
		ans += que(ft[k], a[j] - 1);
	}

	cout << ans << '\n';
}