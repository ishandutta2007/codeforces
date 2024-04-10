#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

long long n, k, a, b;

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

bool solve(long long a, long long b) {
	long long d = (long long)(round(cbrt(a * b)));
	if(d * d * d != a * b)
		return 0;
	if(a % d != 0 or b % d != 0)
		return 0;
	return 1;
	
}

int main() {
	ios_base::sync_with_stdio(false);

	scanf("%lld", &n);
	for(long long i = 1; i <= n; i++) {
		scanf("%lld", &a);
		scanf("%lld", &b);
		printf("%s\n", solve(a, b) ? "Yes" : "No");
	}

}