#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

int n, k;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	long long minn = 1e9+1, pos = -1, sum = 0;
	for(int i = 1; i <= n; i++) {
		cin >> k;
		sum += k;
		if(k < minn)
			minn = k, pos = i;
	}

	if(2 * minn == sum)
		return cout << "-1\n", 0;
	if(n == 1)
		return cout << "-1\n", 0;
	cout << "1\n" << pos << '\n';
}