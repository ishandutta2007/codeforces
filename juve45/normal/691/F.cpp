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

const long long N = 3001000;
// const long long N = 17;
long long n, f[N], a[N], p[N], m, ans[N];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i = 1; i <= n; i++)
		cin >> a[i], f[a[i]]++;

	for(long long i = 1; i < N; i++) 
		for(long long j = i; j < N; j += i) {
			if(j != i * i)
				ans[j] += f[i] * f[j / i];
			else 
				ans[j] += f[i] * (f[i] - 1);
		}

	for(long long i = 1; i < N; i++)
		ans[i] += ans[i - 1];

	cin >> m;
	for(long long i = 1; i <= m; i++)
		cin >> p[i];

	for(long long i = 1; i <= m; i++) 
		cout << n * (n - 1) - ans[p[i] - 1] << '\n';

}