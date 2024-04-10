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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 1001000;
int n, t, prime[N], sqr[N];

bool ok(int a, int b) {
	int g = __gcd(a, b);
	a /= g;
	b /= g;
	// dbg(a, b, g);
	if(a + b > g && a + g > b && g + b > a)
		return 1;
	return 0;
}

void solve() {

	sqr[1] = 0;
	for(int i = 1; i <= 1000; i++)
		sqr[i * i]++;

	for(int i = 1; i < N; i++)
		sqr[i] += sqr[i - 1];

	for(int i = 0; i < N; i++)
		prime[i] = 1;

	for(int i = 2; i < N; i++)
		if(prime[i])
			for(int j = 2 * i; j < N; j += i)
				prime[j] = 0;

	prime[0] = prime[1] = 0;

	for(int i = 1; i < N; i++)
		prime[i] += prime[i - 1];

}

int main() {
	ios_base::sync_with_stdio(false);

	solve();

	scanf("%d", &t);
	while(t--) {

		scanf("%d", &n);
		printf("%d\n", prime[n] - prime[sqr[n]] + 1);
	} 
}