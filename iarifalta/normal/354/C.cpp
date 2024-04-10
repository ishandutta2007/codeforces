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
	cerr << a << " ";
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
 
const int N = 1e6 + 2;
const int M = 4e6 + 2;
const int mod = 998244353;
const ll inf = 1e6;
const ll INF = 1e16;

void data() {
	#ifdef PC
		freopen("c.in", "r", stdin);
		freopen("c.out", "w", stdout);
	#endif
}

ll n, k, a[N], cnt, ans[N], pref, is[N], was[N], ret;

ll r[N]; 
 
vector<ll> p[N];
 
void pr(){
    for(int i = 2; i <= inf; i++){
        if(r[i])
            continue;
        r[i] = i;
        for(int j = i * 2; j <= inf ; j += i)
            r[j] = i;
    }
    p[1].pb(1);
    for(int i = 2; i <= inf; i++){
        ll x = i / r[i];
        ll y = r[i];
        r[i] = -i;
        for(int l = 0 ,f = 0 ; l < p[x].size() || f < p[x].size() ;){

            if(p[x].size() == l){
                if(p[i][p[i].size() - 1] != p[x][f] * y)
                    p[i].pb(p[x][f] * y),r[i] += p[i][p[i].size() - 1];
                f++;
            }
            else if(p[x].size() == f)
                p[i].pb(p[x][l]),l++,r[i] += p[i][p[i].size() - 1];

            else{
                if(p[x][l] <= p[x][f] * y)
                    p[i].pb(p[x][l]),l++,r[i] += p[i][p[i].size() - 1];
                else{
                    if(p[i][p[i].size() - 1] != p[x][f] * y)
                        p[i].pb(p[x][f] * y),r[i] += p[i][p[i].size() - 1];
                    f++;
                }
            }
        }
    }
    r[1] = 0;
}


int main() {
	data();
	scan(n, k);
	ret = 1;
	for (int i = 1; i <= n; ++i) {
		scan(a[i]);
		was[max(a[i] - k, 1LL)]++;
		was[a[i] + 1]--;
		is[a[i]]++;
	}
	sort(a + 1, a + n + 1);
	for (int i = k; i >= 1; --i) {
		if (is[i])
		    ret = i;
	}
	pr();
	for (int i = 1; i <= inf; ++i) {
		cnt += was[i];
		for (auto it : p[i]) {
			if (it > k)
				ans[it] += cnt;	
		}
	}
	for (int i = 2; i <= inf; ++i) {
		if (ans[i] == n)
			ret = max(ret, 1LL * i);
	}
	print(ret);
}		

/*
	Timus: 288481RF
	CodeForces: fractal
*/