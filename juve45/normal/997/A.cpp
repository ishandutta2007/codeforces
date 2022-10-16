#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

long long n, k, x, y, nr;
string s;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> x >> y;
	cin >> s;
	int ok = 1;
	for(int i = 0; i <= n; i++) {
		if(s[i] == '0' && ok) {
			nr++;
			ok = 0;
		}
		if(s[i] == '1') ok = 1;
	}
	if(nr == 0) return cout << "0\n", 0;
	cout << min(nr * y, (nr - 1) * x + y);
}