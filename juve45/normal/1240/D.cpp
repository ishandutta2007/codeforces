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

const long long N = 500107;
const long long MOD1 = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
// const long long B = 
long long n, invN1, invN2, a[N], q;


long long powMod(long long base, long long exp, long long MOD) {
	if(exp == 0)return 1;
	long long tmp = powMod(base, exp / 2, MOD);
	tmp = (1LL * tmp * tmp) % MOD;
	if(exp % 2) tmp = (tmp * base) % MOD;
	return tmp;
}

long long invMod(long long a, long long MOD) {
	return powMod(a, MOD - 2, MOD);
}

long long dc(long long l, long long r) {
	map <pair<long long, long long>, long long> f;

	if(l == r) return 0;
	long long mid = (l + r) / 2;
	long long ret = dc(l, mid) + dc(mid + 1, r);

	stack <long long> st;
	pair<long long, long long> h = {0, 0};

	for(long long i = mid; i >= l; i--) {
		if(st.empty() || st.top() != a[i]) {
			h.st = (h.st * N + a[i]) % MOD1;
			h.nd = (h.nd * N + a[i]) % MOD2;
			st.push(a[i]);
		}
		else {
			h.st = (MOD1 + h.st - a[i]) % MOD1 * invN1 % MOD1;
			h.nd = (MOD2 + h.nd - a[i]) % MOD2 * invN2 % MOD2;
			st.pop();
		}
		// dbg(i, a[i], h);
		f[h]++;
	}

	h = {0, 0};
	while(!st.empty()) st.pop();
	for(long long i = mid + 1; i <= r; i++) {
		if(st.empty() || st.top() != a[i]) {
			h.st = (h.st * N + a[i]) % MOD1;
			h.nd = (h.nd * N + a[i]) % MOD2;
			st.push(a[i]);
		}
		else {
			h.st = (MOD1 + h.st - a[i]) % MOD1 * invN1 % MOD1;
			h.nd = (MOD2 + h.nd - a[i]) % MOD2 * invN2 % MOD2;
			st.pop();
		}
		// dbg(i, a[i], h);
		ret += f[h];
	}
	// dbg(l, r, ret);
	return ret;
}

void solve() {
	cin >> n;
	for(long long i = 1; i <= n; i++) cin >> a[i];

	cout << dc(1, n) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);

	invN1 = invMod(N, MOD1);
	invN2 = invMod(N, MOD2);

	cin >> q;
	while(q--) solve();
}