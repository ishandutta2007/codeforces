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

const int N = 1000100;
const int MOD1 = 1e9 + 9;
const int MOD2 = 1e9 + 7;
const int B = 3;
int n, m, a, b, hsh1[N], hsh2[N], pwb1[N], pwb2[N];

long long ans = 0;
vector <pair<int, int> > e;
vector <int> v[N];
map <pair<int, int>, int> mp;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	pwb1[0] = 1;
	pwb2[0] = 1;
	for(int i = 1; i < N; i++) pwb1[i] = (1LL * pwb1[i - 1] * B) % MOD1;
	for(int i = 1; i < N; i++) pwb2[i] = (1LL * pwb2[i - 1] * B) % MOD2;
		// dbg_v(pwb2, 10);

	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		e.push_back({a, b});
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for(int i = 1; i <= n; i++) {
		for(auto j : v[i]) {
			hsh1[i] += pwb1[j];
			hsh1[i] %= MOD1;
			hsh2[i] += pwb2[j];
			hsh2[i] %= MOD2;
		}
		mp[{hsh1[i], hsh2[i]}]++;
	}

	for(auto i : mp) {
		ans += 1LL * i.nd * (i.nd - 1) / 2;
	}

	for(auto i : e) {
		a = i.st;
		b = i.nd;
		hsh1[a] = (MOD1 + hsh1[a] - pwb1[b]) % MOD1;
		hsh1[b] = (MOD1 + hsh1[b] - pwb1[a]) % MOD1;
		hsh2[a] = (MOD2 + hsh2[a] - pwb2[b]) % MOD2;
		hsh2[b] = (MOD2 + hsh2[b] - pwb2[a]) % MOD2;
		if(hsh1[a] == hsh1[b] && hsh2[a] == hsh2[b])
			ans++;
		hsh1[a] = (hsh1[a] + pwb1[b]) % MOD1;
		hsh1[b] = (hsh1[b] + pwb1[a]) % MOD1;
		hsh2[a] = (hsh2[a] + pwb2[b]) % MOD2;
		hsh2[b] = (hsh2[b] + pwb2[a]) % MOD2;
	}
	cout << ans << '\n';
}