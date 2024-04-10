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

const long long N = 300100;
long long n, b, bb, a[N], f[164], v[N];

set <long long> s;
vector <long long> ans;
int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i= 1; i <= n; i++) {
		cin >> a[i];
		b = a[i];
		long long nr = 0;
		while(b % 2 == 0) b /= 2, nr++;
		f[nr]++;
		v[i] = nr;
	}
	long long an = 0;

	for(long long i = 0; i <= 100; i++)
		if(f[an] < f[i])
			an = i;

	for(long long i = 1; i <= n; i++)
		if(v[i] != an)
			ans.push_back(a[i]);
	cout << ans;
}