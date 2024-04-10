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

const long long N = 400100;
long long B = 300607;
long long MOD = 1e9 + 7;
long long n, start, mm, fin, use[N], a, b, nr, val[N], invm[N];
set <long long> v[N];
vector <long long> w[N];
vector <pair<long long, long long> > e;
map <long long, long long> m;
// map <long long, long long> val;
long long hsh[N];


void dfs(long long node, long long ant = 0) {
	use[node] = use[ant] + 1;
	if(v[node].size() > 2) cout << "NO\n", exit(0);

	long long nrr = 0;
	for(auto i : v[node]) 
		if(!use[i])
			dfs(i, node), nrr++;
		else if(i != ant)
			cout << "NO", exit(0);
	if(nrr > 1) 
		cout << "NO", exit(0);
}

long long powMod(long long base, long long exp) {
	if(exp == 0)return 1;
	long long tmp = powMod(base, exp / 2);
	tmp = (1LL * tmp * tmp) % MOD;
	if(exp % 2) tmp = (tmp * base) % MOD;
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> mm;
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

	// srand(657 + time(0));
	// B = rand() % 100000 + 324688;
	// MOD = 1LL * rand() * rand();
	// MOD %= 1000000000;
	// MOD += 900000000;

	for(int i = 1; i <= n; i++)
		val[i] = rng();

	for(long long i = 1; i <= mm; i++) {
		cin >> a >> b;
		e.push_back({a, b});
		w[a].push_back(b);
		w[b].push_back(a);
	}

	for(long long i = 1; i <= n; i++) {
		w[i].push_back(i);
		sort(w[i].begin(), w[i].end());
		for(auto j : w[i]) {
			hsh[i] ^= val[j];
			// hsh[i] %= MOD;
			// assert(hsh[i] >= 0);
		}
		// add(hsh[i], i);
		if(!m.count(hsh[i])) {
			m[hsh[i]] = ++nr;
			invm[nr] = hsh[i];
		}
		// dbg(i, hsh[i]);
	}

	for(auto i : e) {
		if(hsh[i.st] == hsh[i.nd]) continue;
		else {
			v[m[hsh[i.st]]].insert(m[hsh[i.nd]]);
			v[m[hsh[i.nd]]].insert(m[hsh[i.st]]);
			// v[i.nd].insert(i.st);
		}
	}

	// dbg(nr);
	for(long long i = 1; i <= nr; i++) {
		if(v[i].size() == 1)
			start = i;
	}

	// dbg(v[1]);
	// dbg(v[2]);
	// dbg(v[3]);
	// dbg(v[4]);
	// dbg(v[5]);
	// dbg(start);

	if(nr > 1 && start == 0) return cout << "NO\n", 0;
	if(nr != 1)
		dfs(start);
	else use[1] = 1;

	cout << "YES\n";
	for(long long i = 1; i <= n; i++)
		cout << use[m[hsh[i]]] << ' ';
}