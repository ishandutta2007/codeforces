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
double l, v1, v2;
string s;


template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main()
{
	ios_base::sync_with_stdio(false);

	cout << fixed << setprecision(8);
	cin >> n >> l >> v1 >> v2 >> k;
	double x, y;
	int nr = (n + k - 1) / k;
	double nrr = nr;
	// cout << v2 / (v1 * (nrr - 1)) << '\n';
	double left = 0, right = l;
	for(int i = 0; i < 300; i++) {
		// dbg(left);
		// dbg(right);
		double mid = (left + right) / 2;
		y = mid;
		x = l - mid;
		if(x / v1 + y / v2 >= nrr * y / v2 + (nrr - 1) * y*(1. - v1 / v2) / (v1 + v2) ) left = mid;
		else right = mid;
	}


	y = right;
	x = l - right;
	// cout << y / x << '\n';
	cout << x / v1 + y / v2;
}