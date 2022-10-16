#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

int n, k, a, b, h, t1, f1, t2, f2;

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

int dmin(int x, int y) {
	if(x >= b && y >= b)
		return x + y - 2 * b;
	if(x <= a && y <= a)
		return 2 * a - x - y;
	return fabs(x - y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> h >> a >> b >> k;
	for(int i = 1; i <= k; i++) {
		cin >> t1 >> f1;
		cin >> t2 >> f2;
		if(t1 != t2)
			cout << abs(t1 - t2) + dmin(f1, f2) << '\n';
		else cout << abs(f1 - f2) << '\n';
	}
}