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

int a[10];

int get(int nr) {
	int ans = 10;
	
	for(int i = 0; i < 7; ++i) {
		int x = 0, cnt = 0;
		for(int j = i; x < nr; j = (j + 1) % 7, ++cnt) x += a[j];
		ans = min(ans, cnt);
	}
	
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	int i, t, k, s;
	
	for(cin >> t; t; --t) {
		cin >> k;
		for(s = 0, i = 0; i < 7; ++i) {
			cin >> a[i];
			s += a[i];
		}
		
		if(k % s == 0) cout << (k / s - 1) * 7 + get(s) << '\n';
		else cout << (k / s) * 7 + get(k % s) << '\n';
	}
	
	return 0;
}