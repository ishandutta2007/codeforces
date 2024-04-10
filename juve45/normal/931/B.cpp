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

int n, k, a, b, l, r;
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
	cin >> n >> a >> b;
	if(a > b) swap(a, b);
	
	int mx = log2(n);
	int k = mx + 1;
	l = 1; r = n;
	while(true) {
		k--;
		int mid = (l + r) / 2;
		if(a <= mid && b > mid) {
			cout << (k == mx ? "Final!" : to_string(k)) << '\n';
			return 0;
		}
		if( b <= mid) r = mid;
		else l = mid + 1;
	}

}