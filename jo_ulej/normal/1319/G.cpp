#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>
#include <bitset>
#include <cassert>
#include <random>
#ifdef __LOCAL
#define DBG(X) cout << "[DBG] " << #X << ": " << (X) << '\n';
#else
#define DBG(X) 42;
#endif
using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
const int INT_INT = (int)2e9;
const ll LL_INF = (ll)2e18;
const int NIL = -1;
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) {
	for(auto& el: vec) os << el << ' ';
	return os;
}
template<class T> T fetch() {
	T rez;
	cin >> rez;
	return rez;
}
void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}
const int T = 2;
const int MAXN = (int)2e5 + 7;
int MOD[T], BASE[T];
int pw[T][MAXN];
inline int checkPrime(int num) {
	for(int i = 2; i * i <= num; ++i) if(num % i == 0) return 0;
	return 1;
}
ll rand16() {
	return rand();
}
ll rand32() {
	ll a = rand16();
	ll b = rand16();
	a ^= b << 16LL;
	return a;
}
ll randint32(ll a, ll b) {
	ll w = rand32();
	return a + w%(b - a + 1);
}
inline int add(int a, int b, int mod) {
	return (a + b >= mod ? a + b - mod : a + b);
}
inline int sub(int a, int b, int mod) {
	return (a - b < 0 ? a - b + mod : a - b);
}
inline int mult(int a, int b, int mod) {
	ll rez = a * 1LL * b;
	if(rez >= mod) rez %= mod;
	return (int)rez;
}
void initHash() {
	int ptr = (int)1e9;
	for(int j = 0; j < T; ++j) {
		while(!checkPrime(ptr)) ++ptr;
		MOD[j] = ptr;
		BASE[j] = randint32(MOD[j] / 10, MOD[j] - 1);
		++ptr;
	}
	for(int j = 0; j < T; ++j) {
		pw[j][0] = 1;
		for(int i = 1; i < MAXN; ++i) {
			pw[j][i] = mult(pw[j][i - 1], BASE[j], MOD[j]);
		}
	}
}
struct Hash {
	int sz;
	int v[T];
	Hash(): sz(0) {
		for(int j = 0; j < T; ++j) v[j] = 0;
	}
	bool operator==(const Hash& other) const {
		if(sz != other.sz) return false;
		for(int j = 0; j < T; ++j) if(v[j] != other.v[j]) return false;
		return true;
	}
};
inline Hash append(Hash hsh, char ch) {
	++hsh.sz;
	int code = ch - '0' + 1;
	for(int j = 0; j < T; ++j) {
		hsh.v[j] = mult(hsh.v[j], BASE[j], MOD[j]);
		hsh.v[j] = add(hsh.v[j], code, MOD[j]);
	}
	return hsh;
}
inline Hash merge(const Hash& left, const Hash& right) {
	Hash rez;
	rez.sz = left.sz + right.sz;
	for(int j = 0; j < T; ++j) {
		rez.v[j] = left.v[j];
		rez.v[j] = mult(rez.v[j], pw[j][right.sz], MOD[j]);
		rez.v[j] = add(rez.v[j], right.v[j], MOD[j]);
	}
	return rez;
}
inline Hash antimerge(const Hash& left, const Hash& right) {
	Hash rez;
	rez.sz = -left.sz + right.sz;
	for(int j = 0; j < T; ++j) {
		rez.v[j] = right.v[j];
		int x = left.v[j];
		x = mult(x, pw[j][rez.sz], MOD[j]);
		rez.v[j] = sub(rez.v[j], x, MOD[j]);
	}
	return rez;
}
string S;
int n, q, pref[MAXN];
Hash prefHash[MAXN];
inline int getSum(int l, int r) {
	int rez = pref[r];
	if(l > 0) rez -= pref[l - 1];
	return rez;
}
int fst[MAXN], lst[MAXN];
inline Hash getHash(int l, int r) {
	//assert(l <= r);
	//DBG(l); DBG(r);
	if(S[l] == '0' && S[r] == '0') {
		auto rez = prefHash[r];
		if(l > 0) rez = antimerge(prefHash[l - 1], rez);
		return rez;
	} else {
		if(S[l] == '1' && S[r] == '1' && fst[l] == fst[r]) {
			Hash rez;
			int cnt = r - l + 1;
			if(cnt%2==1) rez = append(rez, '1');
			return rez;
		}
		if(S[l] == '1') {
			auto rez = getHash(lst[l] + 1, r);
			int cnt = lst[l] - l + 1;
			if(cnt%2==1) {
				Hash L;
				L = append(L, '1');
				rez = merge(L, rez);
			}
			return rez;
		}
		if(S[r] == '1') {
			auto rez = getHash(l, fst[r] - 1);
			int cnt = r - fst[r] + 1;
			if(cnt%2==1) rez = append(rez, '1');
			return rez;
		}
		assert(false);
	}
}
inline int check(int i, int j, int sz) {
	if(getSum(i, i + sz - 1) != getSum(j, j + sz - 1)) return 0;
	return getHash(i, i + sz - 1) == getHash(j, j + sz - 1);
}
void solve() {
	cin >> n >> S;
	pref[0] = S[0]-'0';
	for(int i = 1; i < n; ++i) {
		pref[i] = pref[i - 1] + (S[i]-'0');
	}
	vector<pair<char, Hash>> st;
	st.emplace_back('%', Hash());
	for(int i = 0; i < n; ++i) {
		char ch = S[i];
		if(ch == '1' && ch == st.back().first) {
			st.pop_back();
		} else {
			auto nh = append(st.back().second, ch);
			st.emplace_back(ch, nh);
		}
		prefHash[i] = st.back().second;
	}
	for(int i = 0; i < n; ++i) {
		if(S[i] == '0') {
			fst[i] = NIL;
		} else {
			fst[i] = i;
			if(i > 0 && S[i - 1] != '0') fst[i] = fst[i - 1];
		}
	}
	for(int i = n - 1; i >= 0; --i) {
		if(S[i] == '0') {
			lst[i] = NIL;
		} else {
			lst[i] = i;
			if(i < n - 1 && S[i + 1] != '0') lst[i] = lst[i + 1];
		}
	}
	cin >> q;
	for(int que = 0; que < q; ++que) {
		int i = fetch<int>() - 1;
		int j = fetch<int>() - 1;
		int sz = fetch<int>();
		cout << (check(i, j, sz) ? "Yes\n" : "No\n");
	}
}
int main() {
	fastIO();
	initHash();
	solve();
	return 0;
}