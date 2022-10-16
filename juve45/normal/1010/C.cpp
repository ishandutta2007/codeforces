#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 100100;
int n, k, a[N];

int sieve[N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	
	set<int> s;
	vector <int> v;
	int g = 0;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		int nr = a[i] % k;
		s.insert(__gcd(a[i], k));
		g = __gcd(g, a[i]);
	}
	s.insert(g);

	for(auto i : s) {
		for(int j = 0; j < k; j += i)
			sieve[j] = 1;
		if(i == 1) break;
	}
	for(int i = 0; i < k; i++)
		if(sieve[i])
			v.push_back(i);
	cout << v;
}