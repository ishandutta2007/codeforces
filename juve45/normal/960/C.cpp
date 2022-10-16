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

long long n, k, x, d;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

vector <long long> ans;

void solve(long long start, long long count) {
	// dbg(start);
	// dbg(count);
	if(count < 10) {
		for(long long i = 0; i < count; i++)
			ans.push_back(start + i * (d + 1));
		return;
	}
	long long i;
	for(i = 1; ;i++)
		if((1 << (i + 1)) - 1 > count) 
			break;

	for(long long j = 0; j < i; j++)
		ans.push_back(start);
	solve(start + d + 1, count - (1 << i) + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> x >> d;
	solve(1, x);
	cout << ans << '\n';
}