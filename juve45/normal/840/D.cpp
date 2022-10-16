#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

const int N = 300100;
int n, k, m, a[N], l, r;
vector <int> v[N];

int cnt(int l, int r, int val) {
	auto low = lower_bound(v[val].begin(), v[val].end(), l);
	auto high = upper_bound(v[val].begin(), v[val].end(), r);
	return high - low;
}
	
int seed;
int nxt() {
	seed = 1ll * ((seed ^ 24573486 + 15463257) * 4856883ll) % 1000000;
	return seed;
}

int res(int l, int r, int k) {

	int res = 1e9;
	for(int j = 0, nr = 0; j < 60 && nr < 7; j++) {
		int pos = nxt() % (r - l + 1);
		if(a[l + pos] < res && v[a[l + pos]].size() > (r - l + 1) / k && cnt(l, r, a[l + pos]) > (r - l + 1) / k)
			res = min(a[l + pos], res), nr++;
	}
	if(res < 1000000000)
		return res;
	return -1;
}

int main() {
	// ios_base::sync_with_stdio(false);
	// srand(time(0));
	seed = time(0);
	// cin >> n >> m;
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++) {
		// cin >> a[i];
		scanf("%d", a + i);
		v[a[i]].push_back(i);
	}

	for(int i = 1; i <= m; i++) {
		scanf("%d %d %d ", &l, &r, &k);
		// cin >> l >> r >> k;

		// cout << res(l, r, k) << '\n';
		printf("%d\n", res(l, r, k));
		
	}
}