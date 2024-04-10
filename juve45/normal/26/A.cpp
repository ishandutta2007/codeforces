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

// const int N = ;
int n, ans, nr;

bool isPrime(int k) {
	for(int i = 2; i*i <= k; i++)
		if(k % i == 0) return 0;
	return 1;
}

vector <int> p;


int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;

	for(int i = 2; i <= n; i++)
		if(isPrime(i))
			p.push_back(i);
	// dbg(p);
	for(int i = 1; i <= n; i++) {
		nr = 0;
		for(auto j : p)
			nr += (i % j == 0);
		if(nr == 2)ans++;
	}
	cout << ans << '\n';
}