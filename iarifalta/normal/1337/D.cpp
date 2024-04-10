#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second 
#define mp make_pair
#define pb push_back
#define pf push_front
#define speed_up ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define debug cerr << "OK\n";
#define ub upper_bound
#define lb lower_bound
 
namespace io {
	const int __SIZE = (1 << 21) + 1;
	char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1, __c, qu[55]; int __f, qr, _eof;
	#define Gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
	inline void flush () { fwrite (obuf, 1, oS - obuf, stdout), oS = obuf; }
	inline void gc (char &x) { x = Gc(); }
	inline void pc (char x) { *oS ++ = x; if (oS == oT) flush (); }
	inline void pstr (const char *s) {int __len = strlen(s); for (__f = 0; __f < __len; ++__f) pc (s[__f]); }
	inline void gstr (char *s) {  for(__c = Gc(); __c < 32 || __c > 126 || __c == ' ';)  __c = Gc();
		for(; __c > 31 && __c < 127 && __c != ' '; ++s, __c = Gc()) *s = __c; *s = 0;}
	template <class I> inline bool gi (I &x) { _eof = 0;
		for (__f = 1, __c = Gc(); (__c < '0' || __c > '9') && !_eof; __c = Gc()) { if (__c == '-') __f = -1; _eof |= __c == EOF; }
		for (x = 0; __c <= '9' && __c >= '0' && !_eof; __c = Gc()) x = x * 10 + (__c & 15), _eof |= __c == EOF; x *= __f; return !_eof; }
	template <class I> inline void gp (I x) { if (!x) pc ('0'); if (x < 0) pc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10; while (qr) pc (qu[qr --]); }
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
} using io::pc; using io::gc; using io::pstr; using io::gstr; using io::gi; using io::gp;
 
void scan() {
	return;
}
 
template<class T, typename... Args>
void scan(T &a, Args&&... args) {
	gi(a);
	scan(args...);
	return;
}

template<typename T>
void scann(T a, T b) {
	for (auto it = a; it != b; ++it)
		scan(*it);
}
 
template<typename T>
void scerr(T a, T b) {
	for (auto it = a; it != b; ++it)
		cerr << *it << " ";
	cerr << '\n';
}

void print() {
	pc('\n');
	return;
}
 
template<class T, typename... Args>
void print(T a, Args... args) {
	gp(a);
	pc(' ');
	print(args...);
	return;
}
 
void cer() {
	return;
}
 
template<class T, typename... Args>
void cer(T a, Args... args) {
	cerr << a;
	cer(args...);
	return;
}
 
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef set <int> si;
typedef set <ll> sll;
typedef multiset <int> msi;
typedef multiset <ll> msll;
typedef map <int, int> mi;
typedef map <ll, int> mll;
 
const int N = 2e5 + 2;
const ll M = 4e5 + 2;
const ll mod = 998244353;
const int inf = 2e9 + 3;
const ll INF = 1e18;

void data() {
	#ifdef PC
		freopen("d.in", "r", stdin);
		freopen("d.out", "w", stdout);
	#endif
}

ll T, n, na, nb, nc;
ll ans = INF;

ll mem(ll x, ll y, ll z) {
	return (x - y) * (x - y) + (x - z) * (x - z) + (z - y) * (z - y);
}

int get(int a, int b) {
	for (int i = 0; i < 3; ++i)
		if (i != a && i != b)
			return i;
}

int main() {
	data();
	scanf("%lld", &T);
	while (T--) {
		ans = -1; 
		set <ll> st[5];
		scanf("%lld %lld %lld", &na, &nb, &nc);
		for (int i = 1; i <= na; ++i) {
			ll x;
			scanf("%lld", &x);
			st[0].insert(x);
		}
		for (int i = 1; i <= nb; ++i) {			
			ll x;
			scanf("%lld", &x);
			st[1].insert(x);
		}
		for (int i = 1; i <= nc; ++i) {
			ll x;
			scanf("%lld", &x);		
			st[2].insert(x);		
		}
		for (int i = 0; i < 3; ++i) {
			for (auto it : st[i]) {
				for (int j1 = 0, j2; j1 < 3; ++j1) {
					if (j1 == i)
						continue;
				    j2 = get(j1, i);
					auto it1 = st[j1].lb(it);
					auto it2 = st[j2].lb(it);
					if (*it1 != it && it1 != st[j1].begin())
						it1--;
					if (it1 == st[j1].end() || it2 == st[j2].end())
					    continue;
					if (ans == -1)
						ans = mem(it, *it1, *it2);
					else
						ans = min(ans, mem(it, *it1, *it2));
				}
			}
		}
        printf("%lld\n", ans);
	}
}	

/*
	Timus: 288481RF
	CodeForces: fractal
*/