#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#ifndef LOCAL
#define cerr if(0)cout
#endif

#define st first
#define nd second

using namespace std;

const int N = 14;
int n, k, a[N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << '\n';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << p.st << ' ' << p.nd;  
}

int f(int k) {
	for(int i = 1; i <= n; i++)
		k = abs(a[i] - k);
	return k;
}

vector <pair<int, int> > ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	cout << __builtin_popcount(n);
}