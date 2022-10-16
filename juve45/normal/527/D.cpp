#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 
#define NMAX 
#define MMAX 

using namespace std;

int n, k, x, w, ans;
vector<pair<int, int> > v;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n ;i++)	{
		cin >> x >> w;
		v.push_back({x - w, x + w});
	}

	sort(v.begin(), v.end());

	int r = -1e9;
	for(int i = 0; i < v.size(); i++) {
		if(v[i].st >= r) ans++, r = v[i].nd;
		else r = min(r, v[i].nd);
	}
	cout << ans << '\n';
}