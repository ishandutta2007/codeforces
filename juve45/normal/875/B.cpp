#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 300100
#define NMAX 
#define MMAX 

using namespace std;

int n, k, aib[DMAX], p, v[DMAX], last;
long long ans;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int lsb(int k) {
	return ((k ^ (k - 1)) & k);
}

void upd(int pos) {
	for(;pos <= n; pos+=lsb(pos))
		aib[pos]++;
}

int que(int pos) {
	int ans = 0;
	for(;pos > 0; pos -= lsb(pos))
		ans += aib[pos];
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	cout << 1 << ' ';
	for(int i = 1; i <= n; i++) {
		cin >> p;
		v[p] = 1;
		while(last < n && v[n - last] == 1) 
			last++;
		cout << i - last + 1 << ' ';
	}
}