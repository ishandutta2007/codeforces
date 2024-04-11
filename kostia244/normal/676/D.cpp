#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma comment(linker, "/STACK:16777216")
//#pragma GCC target ("avx2,tune=native")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace std;
using namespace __gnu_pbds;
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
		getv1(v[i], ns...);
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
template<typename a, typename b>
void minq(a& x, b y) {
	if (x > y)
		x = y;
}
template<typename a, typename b>
void maxq(a& x, b y) {
	if (x < y)
		x = y;
}
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef int _I;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <string> vs;
typedef __V <ld> vd;
typedef __V <vd> vvd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
using AntonTsypko = void;
using arsijo = AntonTsypko;
using god = arsijo;
//store differences, not the elements for rsq in fenwick or array(for write-only)
//Sum Over Subsets + inclusion-exclusion is a thing! (Solved div1E (383E) using it!)
//SQRT-heuristic divide items into groups: >sqrt and <=sqrt and do something according to group(eg. trie for one, z-func for other) - 1202E
//f-e+v=2
uniform_real_distribution<double> double_dist(0, 1);
uniform_int_distribution<int> dist(31, 55);
//WHEN DOING MODULAR SUBTRACTION ALWAYS **ALWAYS** ADD MOD
//don't use AVX at AtCoder(=RE)
//Trie: MAXDEPTH!=MAXSIZE
//suspiciously big numbers? use python, seriosly you don't wanna waste your time if it overflows
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//SQRT IS PROBABLY THE ANSWER
//SET TO ZERO
//char a[] = {'+', '-', '|', '^', '>', '<', 'v', 'L', 'R', 'U', 'D', '*'};
//> = 1, ^ = 2, < = 4, v = 8
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int dira[] = { 8, 2, 1, 4 };
int dirb[] = { 2, 8, 4, 1 };
map<char, int> code;

void setup() {
	code['+'] = 15;
	code['-'] = 1|4;
	code['|'] = 2|8;
	code['^'] = 2;
	code['>'] = 1;
	code['<'] = 4;
	code['v'] = 8;
	code['U'] = 15^2;
	code['R'] = 15^1;
	code['L'] = 15^4;
	code['D'] = 15^8;
	code['*'] = 0;
}

void shift(int& x) {
	x = (x>>1) + 8*(x&1);
}

int f(int x, int y, int s, int t, int st) {
	int r = 0;
	while(st--)
		shift(x),
		shift(y);
	while (r < 4 && (!(x & s) || !(y & t))) {
		shift(x);
		shift(y);
		r++;
	}
	return r;
}
int n, m, cost[4][1010][1010];
char mat[1010][1010];
pi st, e;
bool valid(int x, int y) {
	return x>=0&&y>=0&&x<n&&y<m;
}
int main() {
	doin();
	setup();
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin  >> mat[i][j], mat[i][j] = code[mat[i][j]], cost[0][i][j] = cost[1][i][j] = cost[2][i][j] = cost[3][i][j] = INT_MAX;
	cin >> st.first >> st.second, st.first--, st.second--;
	cost[0][st.first][st.second] = 0;
	cin >> e.first >> e.second, e.first--, e.second--;
	priority_queue<pair<pair<int, int>, pi>> a;
	a.push({{0, 0}, st});
	while(!a.empty()) {
		int x, y, cst, state;
		cst = -a.top().first.first, state = a.top().first.second, x = a.top().second.first, y = a.top().second.second;
		a.pop();
//		cout << state << " " << x << " " << y << "\n";
		if(cost[state][x][y] < cst) continue;
		for(int i = 0; i < 4; i++) {
			int tx = x+dx[i], ty = y+dy[i];
			if(!valid(tx, ty)) continue;
			int w = f(mat[x][y], mat[tx][ty], dira[i], dirb[i], state);
			if(w < 4 && cost[state][x][y]+w+1 < cost[(state+w)%4][tx][ty]) {
				cost[(state+w)%4][tx][ty] = cost[state][x][y]+w+1;
				a.push({{-cost[(state+w)%4][tx][ty], (state+w)%4}, {tx, ty}});
			}
		}
	}
	int q = min({cost[0][e.first][e.second], cost[1][e.first][e.second], cost[2][e.first][e.second], cost[3][e.first][e.second]});
	cout << (q == INT_MAX ? -1 : q);
	return 0;
}