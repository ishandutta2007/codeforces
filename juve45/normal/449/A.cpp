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

long long n, m, k, ans;

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n >> m >> k;
	
	if(k > (n - 1) + (m - 1)) {
		cout << "-1\n";
		return 0;
	}



	for(int k1 = 0; k1 * k1 <= n; k1++) {
		if(k1 > k) break;
		int k2 = k - k1;
		int l1 = n / (k1 + 1);
		// dbg(l1, k1, k2);
		ans = max(n / (k1 + 1) * (m / (k2 + 1)), ans);
	}

	for(int l1 = 1; l1 * l1 <= n; l1++) {
		int k1 = (n - (n % l1) - l1) / l1;
		// dbg(l1, k1);
		if(k1 < 0) continue;
		if(k1 > k) k1 = k;
		int k2 = k - k1;
		// dbg(l1, k1, k2);
		ans = max(n / (k1 + 1) * (m / (k2 + 1)), ans);
	}
	cout << ans << '\n';
	return 0;


	if(n < m) swap(n, m);

	if(n % (k + 1) == 0 || m % (k + 1) == 0)
 		return cout << n * m / (k + 1), 0;

 	if(k < n)
		ans = max(ans, (n / (k + 1)) * m);
	else
		ans = max(ans, m / (k - n + 2));
 	if(k < m)
		ans = max(ans, (m / (k + 1)) * n);
	else
		ans = max(ans, n / (k - m + 2));
	cout << ans << '\n';
}