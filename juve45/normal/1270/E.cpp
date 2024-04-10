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

const long long N = 1005;
long long n, x[N], y[N];

long long dist(long long x, long long y, long long ax, long long ay) {
	long long xx = x - ax;
	long long yy = y - ay;
	return xx * xx + yy * yy;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	
	long long g = 0;

	for(long long i = 1; i <= n; i++)
		cin >> x[i] >> y[i];

	for(long long i = 2; i <= n; i++)
		g = __gcd(g, dist(x[1], y[1], x[i], y[i]));
	
	vector <long long> v;
	for(long long i = 2; i <= n; i++)
		if(dist(x[1], y[1], x[i], y[i]) / g % 2 == 1)
			v.push_back(i);

	cout << v << '\n';
}