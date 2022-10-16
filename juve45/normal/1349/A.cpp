#include <bits/stdc++.h>
using namespace std;

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_array(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)

const long long N = 100100;
long long n, q[100][2], a[N];
vector <long long> v;

void upd(long long a[2], long long nr) {
	if(nr > a[1]) return;
	if(nr > a[0]) a[1] = nr;
	else {
		a[1] = a[0];
		a[0] = nr;
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	// sieve();
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
	}

	long long w = a[1] * a[2];

	for(long long i = 2; i * i <= w; i++)
		if(w % i == 0) {
			while(w % i == 0) w /= i;
			v.push_back(i);
		}

	if(w != 1) v.push_back(w);

	memset(q, 0x3f, sizeof q);

	for(long long i = 1; i <= n; i++) {
		for(long long j = 0; j < v.size(); j++) {
			long long nr = 0;
			while(a[i] % v[j] == 0) a[i] /= v[j], nr++;
			upd(q[j], nr);
		}
	}

	long long ans = 1;
	for(long long i = 0; i < v.size(); i++) {
		for(long long j = 0; j < q[i][1]; j++)
			ans *= v[i];
	}
	cout << ans << '\n';
}