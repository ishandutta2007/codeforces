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
#define NMAX 100010

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

int v[NMAX];
set<pii> pairs;

int main()
{
	ios_base::sync_with_stdio(false);
	
	int i, j, k, m, n, x, a, b;
	
	cin >> n >> m;
	
	if(n == 1 || m == 1LL * n * (n - 1) / 2) return cout << "NO\n", 0;
	
	for(i = 1; i <= m; ++i) {
		cin >> a >> b;
		if(a > b) swap(a, b);
		
		pairs.insert({a, b});
	}
	
	cout << "YES\n";
	
	for(i = 1; i <= n; ++i)
		for(j = i + 1; j <= n; ++j)
			if(!pairs.count({i, j})) {
				v[i] = 1;
				v[j] = 2;
				for(x = 3, k = 1; k <= n; ++k) if(k != i && k != j) v[k] = x++;
				
				for(k = 1; k <= n; ++k) cout << v[k] << ' '; cout << '\n';
				
				v[j] = 1;
				for(k = 1; k <= n; ++k) cout << v[k] << ' '; cout << '\n';
				
				return 0;
			}
	
	return 0;
}