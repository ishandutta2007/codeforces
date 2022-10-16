#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 201
#define NMAX 
#define MMAX 

using namespace std;

int n, k, x;
vector <int> a, b, c, d, e;


template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() - 1 << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

bool ok(vector <int> &v) {
	for(auto i : v) if(i > 1 || i < -1) return false;
	if(v.back() != 1) return false;
	return true;
}

void solve(vector<int> &a, vector<int> &b) {
	int sgn = 1;
	for(int i = 2; i <= n; i++) {
		// dbg(i);
		c.clear();
		c.push_back(0);
		// dbg(a.size());
		for(auto j : a)
			c.push_back(j);
		for(int j = 0; j < a.size(); j++)
			c[j] -= a[j];
		for(int j = 0; j < b.size(); j++)
			c[j] += b[j];
		// dbg(c.size());


		d.clear();
		d.push_back(0);
		for(auto j : a)
			d.push_back(j);
		for(int j = 0; j < a.size(); j++)
			d[j] += a[j];
		for(int j = 0; j < b.size(); j++)
			d[j] += b[j];


		// e.clear();
		// e.push_back(0);
		// for(auto j : a)
		// 	e.push_back(j);
		// for(int j = 0; j < b.size(); j++)
		// 	e[j] += b[j];

		b = a;
		if(ok(d))
			a = d;
		else //if(ok(c))
		a = c;
		for(int i = 0; i < a.size(); i++)
			a[i] = a[i] % 2;
		for(int i = 0; i < a.size(); i++)
			a[i] = a[i] == 2 ? -1 : a[i];
		
		// else a = e;
	}
	//reverse(a.begin(), a.end());
	//reverse(b.begin(), b.end());
	cout << a << '\n' << b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	// a = vector<int>(n, 0);
	// a.push_back(1);
	// for(int i = 1; i <= n; i+=2) {
	// 	b.push_back(1);
	// 	b.push_back(0);
	// }
	// if(b.size() == a.size()) b.pop_back();
	// reverse(b.begin(), b.end());

	a = vector<int> {0, 1};
	b = vector<int> {1};
	solve(a, b);
	// cout << a << '\n';
	// cout << b << '\n';


	// cout << "\n================================================\n";

	// solve(a, b);
}