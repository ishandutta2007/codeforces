#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

template<class T>
ostream& operator<<(ostream& out, set<T> v) {
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

long long n, k, m;

long long get(long long n, long long step) {
	//1, step + 1, 2 * step + 1... 
	long long cnt = n / step;
	return cnt + step * (cnt * (cnt - 1) / 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;

	set<long long> ans;

	for(long long i = 1; i * i <= n; i++) {
		if(n % i == 0) {
			ans.insert(get(n, i));
			ans.insert(get(n, n / i));
		}
	}

	cout << ans;

}