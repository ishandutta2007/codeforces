#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << '\n'; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << '\n' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 100100;
long long n, x[N], s[5];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> x[i];

		// v[x[i] >= 0].push_back({x[i], i});
		s[x[i] >= 0] += abs(x[i]) / 2;

		// if(x < 0) ip.push_back(x), si += x;
		// else p.push_back(x), sp += x;
	}

	// dbg(s[0], s[1]);

	if(s[0] < s[1]) {
		long long nr = s[1] - s[0];
		dbg(nr);
		for(long long i = 1; i <= n; i++) {
			if(nr && x[i] < 0 && abs(x[i]) % 2 == 1)
				cout << -(abs(x[i]) / 2 + 1) << '\n', nr--;
			else cout << x[i] / 2 << '\n';
		}
	} else {
		long long nr = s[0] - s[1];
		// dbg(nr);
		for(long long i = 1; i <= n; i++) {
			if(nr && x[i] > 0 && x[i] % 2 == 1)
				cout << abs(x[i]) / 2 + 1 << '\n', nr--;
			else cout << x[i] / 2 << '\n';
		}
	}



}