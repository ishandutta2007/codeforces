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

const long long N = 1001000;
long long n;
long long k, p[N];

int main() {
	ios_base::sync_with_stdio(false);


	cin >> n >> k;

	long long base = (n + 1) * n / 2;
	if(base > k) return cout << "-1\n", 0;

	long long maxx = n, minn = 1;
	while(base < k && minn < maxx) {
		if(base + maxx - minn <= k) {
			p[minn] = maxx;
			base += maxx - minn;
			maxx--;
			minn++;
		} else {
			long long need = k - base;
			long long who = maxx - need;
			base += maxx - who;
			p[who] = maxx;
			maxx--;
			break;
		}
	}
	// dbg_v(p, n + 1);

	cout << base << '\n';
	for(long long i = 1; i <= n; i++) cout << i << ' ';
	cout << '\n';
	for(long long i = n; i > 0; i--)
		if(!p[i]) p[i] = maxx--;

	for(long long i = 1; i <= n; i++) 
		cout << p[i] << ' ';

}