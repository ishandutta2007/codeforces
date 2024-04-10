#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define ll long long
#define pll pair < ll, ll >
#define x first
#define y second

using namespace std;

ll func(int n, int m){
	if (n > m) swap(n, m);
	return (ll)n * (n+1) * (3*m-n+1) / 6;
}

ll func2(ll n, ll del){
	return (ll)n * (n+1) * (2*n + 3*del + 1) / 6;
}

double func3(double n, double del){
	return n * (n+1) * (2*n + 3*del + 1) / 6.0;
}

int main(){
	ll x;
	cin >> x;
	
	int limit = 0;
	while ((ll)limit * limit * limit / 3 <= x) ++limit;
	--limit;
	
	//cout << limit << endl;
	
	vector < pll > V;
	
	FOR(n,1,limit+1){
		
		ll lo = x * 6 / n / (n+1);
		lo -= 2*n+1;
		lo /= 3;
		
		if (lo < 0) continue;
		
		if (func2(n, lo) == x){
			V.pb({n, lo+n});
			if (lo) V.pb({lo+n, n});
		}
	} sort(V.begin(), V.end());
	
	cout << V.size() << endl;
	for (auto x : V) cout << x.x << " " << x.y << endl;
	
	return 0;
}