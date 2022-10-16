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
int n, k;
vector <int> v;

int phi(int n) {
	int ans = 1;
	for(int i = 2; i * i <= n; i++) { 
		if(n % i != 0) continue;
		int nr = 0;
		while(n % i == 0)
			n /= i, nr++;
		int x = 1;
		for(int k = 1; k < nr ; k++) x *= i;
		// dbg(i, x, nr);
		ans *= (x * i - x);
	}
	if(n != 1) ans *= (n - 1);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	// dbg(phi(3));
	// dbg(phi(5));
	// dbg(phi(64));
	// return 0;
	cin >> n >> k;
	if(k == 1) return cout << "3\n", 0;
	
	for(int i = 3; i <= n; i++) 
		v.push_back(phi(i));
	// dbg(v);
	sort(v.begin(), v.end());
	long long ans = 0;
	for(int i = 0; i < k; i++) 
		ans += v[i];
	cout << ans + 2 << '\n';
}