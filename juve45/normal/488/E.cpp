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

// const long long N = ;
long long n;

bool isPrime(long long n) {
	for(long long i = 2; i * i <= n; i++)
		if(n % i == 0)
			return 0;
	return 1;
}

long long powMod(long long base, long long exp) {
	if(exp == 0)return 1;
	long long tmp = powMod(base, exp / 2);
	tmp = (1LL * tmp * tmp) % n;
	if(exp % 2) tmp = (tmp * base) % n;
	return tmp;
}

long long invMod(long long a) {
	return powMod(a, n - 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	if(n == 1) return cout << "YES\n1\n", 0;
	if(n == 4) return cout << "YES\n1\n3\n2\n4\n", 0;
	if(!isPrime(n)) return cout << "NO\n", 0;

	cout << "YES\n1\n";
	for(long long i = 2; i < n; i++)
		cout << (i * invMod(i - 1)) % n << '\n';
	cout << n << '\n';
}