#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

long long n, k;

long long f(long long k, long long e) {
	if(k < 10)
		return k;
	if(k <= e)
		return k;
	k -= e;
	return e + f(k - k/10, e);
}


int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;


	long long l = 1, r = 1e18;
	while(l != r) {
		long long mid = (l + r) / 2;
		long long res = f(n, mid);
		if(res * 2 >= n) r = mid;
		else l = mid + 1;
	}

	cout << l << '\n';

}