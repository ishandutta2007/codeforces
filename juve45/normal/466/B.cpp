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

long long n, a, b, a1, b1;

bool can(long long n) {
	for(long long i = a; i * i <= n; i++)
		if(n % i == 0 && n / i >= b) {
			a1 = i;
			b1 = n / i;
			return 1;
		}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n >> a >> b;
	long long sw = 0, ans = 2e18;

	if(a > b) swap(a, b), sw = 1;

	for(long long i = 6 * n; i <= 6 * n + 10000; i++)
		if(can(i)) {
			cout << i << '\n';
			if(sw) swap(a1, b1);
			cout << a1 << ' ' << b1 << '\n';
			return 0;
		}

	for(long long b2 = b; b2 <= b + 10000; b2++) {
		long long tmp = ((6 * n + b2 - 1) / b2) * b2;
		// dbg(tmp);
		
		if(tmp < b2 * a) 
			tmp = b2 * a;

		if(tmp < ans) {
			ans = tmp;
			b1 = b2;
			a1 = tmp / b2;
		}
	}
	cout << ans << '\n';
	if(sw) swap(a1, b1);
	cout << a1 << ' ' << b1 << '\n';
}