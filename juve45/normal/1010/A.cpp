#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 1010;
int n, k, a[N], b[N], m;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

bool ok(double d) {
	for(int i = 1; i <= n; i++) {
		// a
		double req = (double) (m + d) / (1. * a[i]);
		d -= req;
		if(d < 0)
			return false;
		req = (double) (m + d) / (1. * b[i]);
		d -= req;
		if(d < 0)
			return false;
	}
	return true;
}

double bs(double l, double r) {
	for(int i = 1; i <= 200; i++) {
		double mid = (l + r) / 2;
		if(ok(mid)) r = mid;
		else l = mid;
	}
	return l;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
		
	for(int i = 1; i <= n; i++)
		cin >> b[i];


	double ans = bs(0, 1e9 + 100);
	if(ans > 1e9)
		cout << "-1\n";
	else 
		cout << fixed << setprecision(9) << ans << '\n';

}