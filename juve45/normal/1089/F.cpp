#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define dbg(x) cerr<<#x": "<<(x)<<endl
#define dbg_p(x) cerr<<#x": "<<(x).first<<' '<<(x).second<<endl
#define dbg_v(x, n) {cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<(x)[_]<<' ';cerr<<endl;}
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define INF 2000000010
#define MOD 1000000007
#define ST_SIZE 1048600
#define QMAX 
#define NMAX 

template<typename T1, typename T2>
ostream& operator <<(ostream &out, const pair<T1, T2> &item) {
	out << '(' << item.first << ", " << item.second << ')';
	return out;
}

template<typename T>
ostream& operator <<(ostream &out, const vector<T> &v) {
	for(const auto &item : v) out << item << ' ';
	return out;
}

pll solve(ll a, ll b) {
	if(!b) return { 1, 0 };
	
	auto ret = solve(b, a % b);
	return { ret.se, ret.fi - a / b * ret.se };
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	int d, n, nn;
	ll x, y, k, a, b;
	vector<int> divs;
	
	cin >> n;
	nn = n;
	
	for(d = 2; d * d <= n; ++d) {
		if(n % d == 0) divs.push_back(d);
		while(n % d == 0) n /= d;
	}
	if(n > 1) divs.push_back(n);
	
	// dbg(divs);
	if(divs.size() == 1) return cout << "NO\n", 0;
	
	a = divs[0];
	b = divs[1];
	auto ret = solve(a, b);
	
	x = ret.fi;
	y = ret.se;
	
	x *= nn - 1;
	y *= nn - 1;
	
	// cerr << a << ' ' << x << ' ' << b << ' ' << y << '\n';
	
	k = -x / b;
	x += k * b;
	y -= k * a;
	
	if(x <= 0) x += b, y -= a;
	// cout << x << ' ' << y << '\n';
	if(y <= 0) return cout << "NO\n", 0;
	
	cout << "YES\n2\n";
	cout << x << ' ' << nn / a << '\n';
	cout << y << ' ' << nn / b << '\n';
	
	return 0;
}