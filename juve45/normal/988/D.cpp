#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const long long N = 1;
long long n, k, a;
set<long long> m;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> a;
		m.insert(a);
	}

	for(long long i = 0; i < 35; i++)
		for(auto j : m) {
			if(m.count(j + (1LL << i)) && m.count(j + (1LL << (i + 1))))
				return cout << 3 << '\n' << j << ' ' << j + (1LL << i) << ' '  << j + 2 * (1LL << i) << '\n', 0;
		}

		
	for(long long i = 0; i < 35; i++)
		for(auto j : m) {
			if(m.count(j + (1LL << i)))
				return cout << 2 << '\n' << j << ' ' << j + (1LL << i) << '\n', 0;
		}

	for(auto j : m) {
		cout << 1 << '\n' << j << '\n';
		break;
	}
	return 0;

}