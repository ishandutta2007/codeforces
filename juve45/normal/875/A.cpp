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

int n, k;

int sc(int k) {
	int ans = 0;
	while(k) ans += k % 10, k /= 10;
	return ans;
}

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << '\n';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	vector <int>ans;
	for(int i = max(1, n - 10000); i <= n; i++)
		if(sc(i) + i == n)
			ans.push_back(i);
	cout << ans;
}