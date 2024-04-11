#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define pb push_back
#define __V vector
#define all(x) x.begin(), x.end()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
}
template<typename X, typename Y>
istream& operator>>(istream& in, pair<X, Y> &a) {
	in >> a.first >> a.second;
	return in;
}
template<typename T>
void getv(T& i) {
	cin >> i;
}
template<typename T, typename ... Ns>
void getv(vector<T>& v, int n, Ns ... ns) {
	v.resize(n);
	for (auto& i : v)
		getv(i, ns...);
}
template<typename T>
void getv1(T& i) {
	cin >> i;
}
template<typename T, typename ... Ns>
void getv1(vector<T>& v, int n, Ns ... ns) {
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
		getv(v[i], ns...);
}
#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
inline void getch(char &x) {
	while (x = getchar_unlocked(), x < 33) {
		;
	}
}
inline void getstr(string &str) {
	str.clear();
	char cur;
	while (cur = getchar_unlocked(), cur < 33) {
		;
	}
	while (cur > 32) {
		str += cur;
		cur = getchar_unlocked();
	}
}
template<typename T> inline bool sc(T &num) {
	bool neg = 0;
	int c;
	num = 0;
	while (c = getchar_unlocked(), c < 33) {
		if (c == EOF)
			return false;
	}
	if (c == '-') {
		neg = 1;
		c = getchar_unlocked();
	}
	for (; c > 47; c = getchar_unlocked())
		num = num * 10 + c - 48;
	if (neg)
		num *= -1;
	return true;
}
typedef unsigned long long ull;
typedef long long ll;
typedef float ld;
typedef int _I;
typedef pair<ll, ll> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <vd> vvd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
using AntonTsypko = void;
using arsijo = AntonTsypko;
using god = arsijo;
uniform_real_distribution<double> double_dist(0, 1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, s, first[70010], single[70010], child[70010];
bitset<70010> dp;
vi a, chain;

void updfirst(bitset<70010>& a, int idx) {
	int i = a._Find_first();
	while(i <= s) {
		first[i] = idx;
		i = a._Find_next(i);
	}
}

void knapstack() {
	bitset<70010> _dp[2];
	bitset<70010> dif;
	_dp[1].set(0);
	for(int it = 0; it < n; it++) {
		int i = it&1;
		_dp[i] = _dp[i^1]|(_dp[i^1]<<a[it]);
		dif = _dp[i] ^ _dp[i^1];
		updfirst(dif, it);
	}
	dp = _dp[(n-1)&1];
}

void backtrack(int sm = s) {
	if(!sm) return;
	single[first[sm]] = 1;
	backtrack(sm - a[first[sm]]);
}

int main() {
	doin();
	cin >> n >> s;
	getv(a, n);
	auto it = max_element(all(a));
	int amax = *it, amaxi = it-a.begin();
	swap(a[0], a[amaxi]);
	knapstack();
	if(amax > s || !dp.test(s) || !dp.test(s-amax)) {
		cout << -1;
		return 0;
	}
	chain.pb({amaxi});
	backtrack();
	swap(a[0], a[amaxi]);
	swap(single[0], single[amaxi]);
	for(int i = 0; i < n; i++)
		if(!single[i]) chain.pb(i);
	sort(all(chain), [](const int& i, const int& j) {
		return a[i] < a[j];
	});
	for(int i = 0; i < n; i++) child[i] = -1;
	for(int i = 1; i < chain.size(); i++) {
		child[chain[i]] = chain[i-1];
	}
	for(int i = 0; i < n; i++) {
		cout << (child[i] != -1 ? a[i]-a[child[i]] : a[i]) << " ";
		if(child[i] != -1)
			cout << "1 " << child[i]+1;
		else
			cout << "0";
		cout << "\n";
	}
}