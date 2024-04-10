#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 
#define NMAX 
#define MMAX 

using namespace std;

long long n, k, x, p;
string s;
vector <long long> ans;
 
template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

void solve(long long k, long long p) {
	// dbg(p);
	// dbg(k);
	if(p == 0) {
		return;
	}
	if(p == 1) {
		ans.push_back(1);
		return;
	}
	if(p < 0) {
		ans.push_back((-p + k - 1)/k * k + p);
		solve(k, (-p + k - 1)/k);	
	}
	else {
		ans.push_back(-p/k * k + p);
		solve(k, -p/k);	
	} 

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> p >> k;
	// long long re = p / k * k;
	solve(k, p);
	cout << ans;

}