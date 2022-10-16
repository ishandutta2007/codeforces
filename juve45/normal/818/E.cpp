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

const int N = 200100;
int n, cnt[15], k, cnt2[15], a[N];
vector <int> primes;
long long ans;

void add(int x, int mul = 1) {
	for(int i = 0; i < primes.size(); i++)
		while(x % primes[i] == 0) {
			cnt2[i] += mul;
			x /= primes[i];
		}
}

bool ok() {
	for(int i = 0; i < primes.size(); i++)
		if(cnt[i] > cnt2[i])
			return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	for(int i = 2; i * i <= k; i++) {
		if(k % i) continue;
		while(k % i == 0) {
			cnt[primes.size()]++;
			k /= i;
		}
		primes.push_back(i);
	}
	if(k != 1) 
		cnt[primes.size()] ++,
		primes.push_back(k);

	// dbg(primes);
	// dbg_v(cnt, primes.size());
	// dbg_v(cnt2, primes.size());
	int j = 0;
	for(int i = 1; i <= n; i++) {
		while(!ok() && j < n) {
			j++;
			add(a[j]);
		}

		if(ok()) ans += min(n - j + 1, n - i + 1);
		// dbg(i, j);
		add(a[i], -1);
	}
	cout << ans << '\n';
}