#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 200100
#define NMAX 
#define MMAX 

using namespace std;

int n, k, x, a[DMAX], t[DMAX];


template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

void solve() {
	cout << "ambiguous\n";

	int last = 1;
	//tree1
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= a[i]; j++)
			t[last + j] = last;
		last += a[i];
	}
	for(int i = 1; i <= last; i++)
		cout << t[i] << ' ';
	cout << '\n';
	//tree2
	last = 1;
	for(int i = 1; i <= n; i++) {
		if(i > 1 && a[i] > 1 && a[i - 1] > 1)
			t[last + 1] = last - 1;
		last += a[i];
	}
	for(int i = 1; i <= last; i++)
		cout << t[i] << ' ';
	cout << '\n';
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i <= n; i++) cin >> a[i];
	int ok = 0;
	for(int i = 1; i <= n; i++) 
		if(a[i] > 1 && a[i - 1] > 1)
			ok = 1;
	if(!ok) 
		cout << "perfect\n";
	else 
		solve();
}