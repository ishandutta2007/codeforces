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

const int N = 5e6;
int n, p, q, prime[N], f[N];

int pal1(int nr) {
	int ret = nr;
	while (nr)
		ret = ret * 10 + nr% 10, nr /= 10;
	return ret;
}
int pal2(int nr) {
	int ret = nr / 10;
	while (nr)
		ret = ret * 10 + nr% 10, nr /= 10;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> p >> q;
	int nr = 0;
	for(int i = 2; i < N; i++) {
		if(prime[i] == 0) {
			for(int j = 2 * i; j < N; j += i)
				prime[j] = 1;
		}
	}

	prime[1] = 0;
	for(int i = 2; i < N; i++)
		if(!prime[i])
			prime[i] = prime[i - 1] + 1;
		else prime[i] = prime[i - 1];

	for(int i = 1; i < 3000; i++) {
		int x1 = pal1(i); if(x1 < N) f[x1]++;
		int x2 = pal2(i); if(x2 < N) f[x2]++;
	}

	for(int i = 1; i < N; i++)
		f[i] += f[i - 1];

	int ans = -1;

	for(int i = 1; i < N; i++)
		if(1LL * prime[i] * q <= 1LL * f[i] * p) {
			ans = i;
		}
	
	// assert(ans != -1);
	cout << ans << '\n';
}