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

const long long N = 300100;
long long n, col[N], x[N], y[N], m, r, s;
long long ans[N], nra, nrb, suma, sumb;
vector <pair<long long, long long> > h;
vector <long long> v[N];

int main() {
	ios_base::sync_with_stdio(false);	

	cin >> n >> m;

	for(long long i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		sumb += y[i];
		nrb++;
		h.push_back({x[i] - y[i], i});
	}

	for(long long i = 1; i <= m; i++) {
		cin >> r >> s;
		v[s].push_back(r);
		v[r].push_back(s);
	}

	sort(h.begin(), h.end());

	for(auto p : h) {
		// dbg(p);
		sumb -= y[p.nd];
		nrb--;

		// dbg(suma, sumb, nra, nrb);

		ans[p.nd] += 1LL * sumb + nrb * x[p.nd] + 1LL * nra * y[p.nd] + 1LL * suma;

		// dbg(ans[p.nd]);

		for(auto i : v[p.nd]) {
			if(x[i] - y[i] < p.st) ans[p.nd] -= x[i] + y[p.nd];
			else ans[p.nd] -= x[p.nd] + y[i];
		}

		nra++;
		suma += x[p.nd];
	}
	for(long long i = 1; i <= n; i++)
		cout << ans[i] << ' ';
}