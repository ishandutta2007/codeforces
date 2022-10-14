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
const int S = 151*151 + 100;
int n, m, k;
bitset<S> no[4], msk[4][2], ans, cur;
char mat[160][160];
void setp(bitset<S>& bs, int i, int j, int c = 1) {
	i = i*m + j;
	bs.set(i, c);
}
void shbo(bitset<S>& bs) {
	bs<<=m;
	bs&=no[0];
}
void shup(bitset<S>& bs) {
	bs>>=m;
	bs&=no[1];
}
void shle(bitset<S>& bs) {
	bs>>=1;
	bs&=no[3];
}
void shri(bitset<S>& bs) {
	bs<<=1;
	bs&=no[2];
}
void db(bitset<S>& bs) {
	for(int i = 0; i < n; cout << "\n", i++)
		for(int j = 0; j < m; j++)
			cout << bs[i*m + j];
	cout << "============\n";
}

int main() {
	doin();
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			if(i)
				setp(no[0], i, j);
			if(i+1 != n)
				setp(no[1], i, j);
			if(j)
				setp(no[2], i, j);
			if(j+1 != m)
				setp(no[3], i, j);
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> mat[i][j];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			if(mat[i][j] == 'E') {
				setp(ans, i, j);
			}
			if(mat[i][j] == '#')
				continue;
			setp(cur, i, j);
			setp(msk[0][(!i||mat[i-1][j] == '#')], i, j);//up
			setp(msk[1][(i+1==n||mat[i+1][j] == '#')], i, j);//bottom
			setp(msk[2][(!j||mat[i][j-1] == '#')], i, j);//right
			setp(msk[3][(j+1==m||mat[i][j+1] == '#')], i, j);//left
		}
	string s;
	if(cur == ans) {
		cout << 0;
		return 0;
	}
	cin >> s;
	int k = 0;
	while(k < s.size()) {
		if(s[k] == 'L') {
			bitset<S> t = (cur&msk[2][0]);
			shle(t);
			cur = (cur&msk[2][1])|t;
		} else if(s[k] == 'R') {
			bitset<S> t = (cur&msk[3][0]);
			shri(t);
			cur = (cur&msk[3][1])|t;

		} else if(s[k] == 'U') {
			bitset<S> t = (cur&msk[0][0]);
			shup(t);
			cur = (cur&msk[0][1])|t;
		} else if(s[k] == 'D') {
			bitset<S> t = (cur&msk[1][0]);
			shbo(t);
			cur = (cur&msk[1][1])|t;
		}
		k++;
		if(cur == ans) {
			cout << k << "\n";
			return 0;
		}
	}
	cout << -1;
}