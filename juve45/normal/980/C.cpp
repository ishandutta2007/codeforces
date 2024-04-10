#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

int n, k, x, y, maybe[333];
string s;

map<int, int> a;

int mp(int x) {
	if(a.find(x) != a.end()) return x;

	auto it = a.lower_bound(x);
	if(it == a.begin()) {
		int val = max(0, x - k + 1);
		a[val] = x - val + 1;
		return val;
	}

	it--;
	// dbg(it->first);
	// dbg(it->second);
	if(it->first + it->second - 1 >= x)
		return it->first;

	if(it->first + k - 1 >= x) {
		int val = it->first;
		a[val] = x - val + 1;
		return val;
	}


	int val = max(it->second + it->first, x - k + 1);
	a[val] = x - val + 1;
	return val;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		cout << mp(x) << ' ';
	}
}