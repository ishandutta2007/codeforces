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

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

void bkt(int n,int off) {
	if(n <= 3) {
		for(int i = 1; i < n; i++)
			cout << off << ' ';
		cout << n * off << '\n';
		return;
	}
	for(int i = 1; i <= (n + 1) / 2; i++)
		cout << off << ' ';

	bkt(n / 2, off * 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;

	bkt(n, 1);
}