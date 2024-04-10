#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
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

long long m, n, a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> a >> b;


	long long high = (n + m - 1) / m * m;
	long long low = high - m;
	dbg(high);
	dbg(low);
	cout << min(1LL * (high - n) * a, 1LL * (n - low) * b) << '\n';
}