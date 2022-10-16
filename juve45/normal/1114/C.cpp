#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const long long N = 10;
long long n, k, b, ans = 3e18;

map<long long, long long> m;

long long get(long long n, long long k) {
	long long ans = 0, kk = 1;
	while(n / k >= kk) {
		kk *= k;
		ans += n / kk;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> b;

	for(long long i = 2; i * i <= b; i++)
		while(b % i == 0)
			b /= i, m[i]++;
	
	if(b != 1) m[b]++;

	for(auto i : m) {
		long long nr = i.st;
		long long f = i.nd;
		long long cnt = get(n, nr);
		ans = min(ans, cnt / f);
	}
	cout << ans << '\n';
}