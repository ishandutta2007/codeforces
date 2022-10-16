#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 5050
#define NMAX 1
#define MMAX 1

using namespace std;

int n, k, x, y, ans[DMAX], a[DMAX], p[DMAX], sz = 0, b[DMAX];
short use[10010];

bool isPrime(int k) {
	for(int j = 2; j * j <= k; j++)
		if(k % j == 0)
			return 0;
	return 1;
}


void primes() {
	for(int i = 2; i <= 10000; i++)
		if(isPrime(i)) 
			p[sz++] = i * i;
}

map<int, int> mm;

int get(int k) {
	if(mm.find(k) != mm.end())
		return mm[k];
	int g = mm.size();
	mm[k] = g;
	return g;
}

int main()
{
	ios_base::sync_with_stdio(false);
	primes();
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] == 0) continue;
		for(int j = 0; j < sz; j++) {
			while(a[i] % p[j] == 0)
				a[i] /= p[j];
		}
	} 

	for(int i = 1; i <= n; i++)
		b[i] = get(a[i]);



	for(int i = 1; i <= n; i++) {
		int xx = 0;
		for(int j = i; j <= n; j++) {
			if(a[j] != 0) {
				if(use[b[j]] != i)
					use[b[j]] = i, xx++;
			}
			ans[max(xx, 1)]++;
		}
	}

	for(int i = 1; i <= n; i++)
		cout << ans[i] << " \n"[i == n];
}