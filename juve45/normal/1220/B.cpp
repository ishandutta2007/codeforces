#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 1006;
long long n, a[N][N];

long long _sqrt(long long val) {
	long long l = 0, r = val;
	while(l != r) {
		long long mid = (l + r + 1) / 2;
		if(mid * mid <= val) l = mid;
		else r = mid - 1;
	}
	return l;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i = 1; i <= n; i++)
		for(long long j = 1; j <= n; j++)
			cin >> a[i][j];

	a[1][1] = a[1][2] * a[1][3] / a[2][3];

	for(long long i = 2; i <= n; i++)
		for(long long j = 2; j <= n; j++)
			a[i][j] = a[i - 1][j] * a[i][j - 1] / a[i - 1][j - 1];
	for(long long i = 1; i <= n; i++)
		cout << (long long)(sqrt(a[i][i] + 0.0001)) << ' ';
}