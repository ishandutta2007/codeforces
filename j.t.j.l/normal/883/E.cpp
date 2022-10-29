#include <bits/stdc++.h>

#define st first
#define nd second
#define all(x) (x).begin(), (x).end()

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <class T> void mini(T &l, T r){l = min(l, r);}
template <class T> void maxi(T &l, T r){l = max(l, r);}

template <class TH> void _dbg(const char *sdbg, TH h){cerr << sdbg << "=" << h << "\n";}
template <class TH, class ...TA> void _dbg(const char *sdbg, TH h, TA... a){
	while (*sdbg != ',') cerr << *sdbg++; cerr << "=" << h << ","; _dbg(sdbg + 1, a...);
}
template <class T> ostream &operator <<(ostream &os, vector<T> V){
	os << "["; for (auto vv: V) os << vv << ","; return os << "]";
}
template <class L, class R> ostream &operator <<(ostream &os, pair<L, R> P){
	return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef SFIC
	#define eput(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
	#define eput(...) 218
#endif

const int N = 1000 + 100;

int n, m;
char a[N], b[N];

int main(){
	scanf("%d", &n);
	scanf("%s", a);
	int s0 = 0;
	for (int i = 0; i < n; ++i)
		if (a[i] != '*')
			s0 |= 1 << a[i] - 'a';
	scanf("%d", &m);

	int ans = (1 << 26) - 1;
	for (int i = 0; i < m; ++i){
		scanf("%s", b);
		int s1 = 0;
		bool flag = true;
		for (int j = 0; j < n; ++j)
			if (a[j] == '*')
				s1 |= 1 << b[j] - 'a';
			else
				flag &= a[j] == b[j];
		flag &= (s0 & s1) == 0;
		if (flag)
			ans &= s1;
	}
	printf("%d\n", __builtin_popcount(ans));
	return 0;
}