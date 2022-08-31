#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
const int N = 200005;
char s[N];
int pref[N];
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned uint;
typedef unsigned char uint8;
const ull mod = 10000000000000061ULL;

const ld invMOD = 1. / mod;
inline ull add(ull x, ull y){ x += y; if(x >= mod) x -= mod; return x;}
inline ull sub(ull x, ull y){ x -= y; if(ll(x) < 0) x += mod; return x;}
inline ll mul(ull a, ull b) {
	ull y = ull(ld(a) * ld(b) * invMOD + ld(1) / 2);
	ull r = a * b - y * mod;
	if(ll(r) < 0)
		r += mod;
	return r;
}

int len[N], nxt0[N], prv0[N];
ll H[N], powers[N];
const int base = 31;

ll getHash(int l, int r){
	ll retHash = 0;
	if(pref[r] - pref[l - 1] == r - l + 1){
		retHash = (r - l + 1) % 2 == 0 ? 0 : 2;
	} else{
		int _l = nxt0[l], _r = prv0[r];
		int L = len[_r] - len[_l] + 1;
		retHash = sub(H[_r], mul(H[_l - 1], powers[L]));
		assert(retHash >= 0 & retHash < mod);
		if((r - _r) % 2){
			retHash = (retHash * base + 2) % mod;
			L++;
		}
		if((_l - l) % 2){
			retHash = (powers[L] * 2 + retHash) % mod;
		}
	}
	return retHash;
}

int main(){
	// cerr << setprecision(50) << fixed << (1./mod) << " " << 1./(ld)mod << endl;
	int n; sd(n);
	scanf("%s", s + 1);
	powers[0] = 1;
	for(int i = 1; i <= n; i++){
		powers[i] = powers[i - 1] * base % mod;
		pref[i] = pref[i - 1] + (s[i] == '1');
	}
	nxt0[n + 1] = n + 1;
	prv0[0] = 0;
	for(int i = n; i >= 1; i--) nxt0[i] = s[i] == '0' ? i : nxt0[i + 1];
	for(int i = 1; i <= n; i++) prv0[i] = s[i] == '0' ? i : prv0[i - 1];
	for(int i = 1; i <= n; i++){
		if(s[i] == '0'){
			H[i] = (H[i - 1] * base + 1) % mod;
			len[i] = len[i - 1] + 1;
		} else{
			if(i != 1 && s[i - 1] == '1'){
				H[i] = H[i - 2];
				len[i] = len[i - 2];
			} else{
				H[i] = (H[i - 1] * base + 2) % mod;
				len[i] = len[i - 1] + 1;
			}
		}
	}

	int q; sd(q);
	while(q--){
		int l1, l2, len;
		sd(l1); sd(l2); sd(len);
		if(pref[l1 + len - 1] - pref[l1 - 1] != pref[l2 + len - 1] - pref[l2 - 1]) printf("No\n");
		else printf(getHash(l1, l1 + len - 1) == getHash(l2, l2 + len - 1) ? "Yes\n" : "No\n");
	}
}