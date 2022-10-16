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

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

void solve() {
	
	long long p, q, r, b, g;
	// cin >> p >> q >> b;
	scanf("%lld %lld %lld", &p, &q, &b);
	g = __gcd(p, q);
	p /= g;
	q /= g;
	g = __gcd(q, b);
	while(g != 1) {
		while(q % g == 0) 
			q /= g;
		g = __gcd(q, b);
	}
	if(q == 1) printf("Finite\n");//cout << "Finite\n";
	else printf("Infinite\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	scanf("%d ", &n);
	for(int i = 1 ; i <= n; i++) solve();
}