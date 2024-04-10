#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <queue>
#include <complex>

//#define int long long

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;


inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt(T x, char end = 0);
inline void writeChar(int x);
inline void writeWord(const char* s);

/** Read */

static const int buf_size = 4096;

inline int getChar() {
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar() {
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar(int x) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt(T x, char end) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

inline void writeWord(const char* s) {
	while (*s)
		writeChar(*s++);
}

struct Flusher {
	~Flusher() {
		if (write_pos)
			fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

void solve();
void scan();

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

const int M = 2e5 + 7;
const int N = 1e3;
pair<ll, int> b[M];
int a[N];
int n;
multiset<ll> cur;

int check(ll x) {
	cur.clear();
	ll q = x;
	ll cc = 0;
	for (int j = 0; j < n; j++) {
		cur.insert(a[j]);
		q += a[j];
		while (q < 0) {
			q -= *cur.begin();
			cc++;
			cur.erase(cur.begin());
		}
	}
	return cc;
}

void solve() {
	int  m;
	n = readInt();
	m = readInt();
	for (int i = 0; i < n; i++) {
		a[i] = readInt();
	}
	for (int i = 0; i < m; i++) {
		b[i].first = readInt<long long>();
		b[i].second = i;
	}
	sort(b, b + m, [](pair<ll, int> f1, pair<ll, int> f2) {return f1 > f2; });
	ll nxt = -2;
	ll ans = -1;
	vector<int> f(m);
	int last = 0;
	for (int i = 0; i <= n; i++) {
		int l = last - 1, r = m;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (check(b[mid].first) <= i) l = mid;
			else r = mid;
		}
		for (int j = last; j <= l; j++) {
			f[b[j].second] = i;
		}
		last = l + 1;
	}
	for (int i : f) writeInt(i, '\n');
}