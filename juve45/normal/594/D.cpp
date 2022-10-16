#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const long long N = 200100;
const long long MAX = 1000001;
const long long MOD = 1e9 + 7;

long long n, k, p[MAX], a[N], aib[N], q, lst[N], ans[N], ppos[MAX], inv[MAX];
vector <long long> primes;
vector <pair<long long, long long> > nxt[N];
vector <pair<pair<long long, long long>, long long> > w;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

long long powMod(long long base, long long exp) {
	if(exp == 0) return 1;
	if(exp == 1) return base;

	long long tmp = powMod(base, exp / 2);
	tmp = (tmp * tmp) % MOD;
	if(exp % 2) return (tmp * base) % MOD;
	return tmp;
}

long long invMod(long long base) {
	if(inv[base] == -1)
		inv[base] = powMod(base, MOD - 2);
	return inv[base];
}

long long lsb(long long k) {
	return k & -k;
}

void add(long long pos, long long val) {
	for(; pos < N; pos += lsb(pos))
		aib[pos] = (aib[pos] * val) % MOD;
}

long long que(long long pos) {
	long long ret = 1;
	for(; pos > 0; pos -= lsb(pos))
		ret = (ret * aib[pos]) % MOD;
	return ret;
}
 
int main() {
	ios_base::sync_with_stdio(false);

	for(long long i = 2; i < MAX; i++)
		if(!p[i]) {
			ppos[i] = primes.size();
			primes.push_back(i);
			for(long long j = 2 * i; j < MAX; j+=i)
				p[j] = 1;
		}

	cin >> n;

	memset(inv, -1, sizeof inv);

	for(long long i = 1; i <= n; i++)
		aib[i] = 1;

	for(long long i = 1; i <= n; i++)
		cin >> a[i];

	for(long long i = 1; i <= n; i++)
		add(i, a[i]);

	for(long long i = n; i > 0; i--) {
		long long x = a[i];	

		for(long long j = 0; j < primes.size() && primes[j] * primes[j] <= x; j++) 
			if(x % primes[j] == 0) {
				while(x % primes[j] == 0) 
					x /= primes[j];
				if(lst[j]) {
					nxt[i].push_back({j, lst[j]});
					add(lst[j], primes[j]);
					add(lst[j], invMod(primes[j] - 1));
				} else
					nxt[i].push_back({j, -1});

				add(i, invMod(primes[j]));
				add(i, primes[j] - 1);
				lst[j] = i;
			}

		if(!p[x] && x > 1) {
			int j = ppos[x];
			if(lst[j]) {
				nxt[i].push_back({j, lst[j]});
				add(lst[j], primes[j]);
				add(lst[j], invMod(primes[j] - 1));
			} else
				nxt[i].push_back({j, -1});

			add(i, invMod(primes[j]));
			add(i, primes[j] - 1);
			lst[j] = i;
		}
	}

	cin >> q;
	for(long long i = 1; i <= q; i++) {
		pair<pair<long long, long long>, long long> pp;
		cin >> pp.st.st >> pp.st.nd;
		pp.nd = i;
		w.push_back(pp);
	}

	sort(w.begin(), w.end());
	long long left = 1;

	for(auto p : w) {
		while(left < p.st.st) {
			for(auto j : nxt[left]) {
				add(left, primes[j.st]);
				add(left, invMod(primes[j.st] - 1));

				if(j.nd != -1) {
					add(j.nd, invMod(primes[j.st]));
					add(j.nd, primes[j.st] - 1);
				}
			}
			add(left, invMod(a[left]));
			left++;
		}
		ans[p.nd] = que(p.st.nd);
	}

	for(long long i = 1; i <= q; i++)
		cout << ans[i] << '\n';
}