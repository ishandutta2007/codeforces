#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pd __gnu_pbds
#define st first
#define nd second
#define all(x) (x).begin(), (x).end()

using namespace std;
using namespace placeholders;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T> using il = initializer_list<T>;

template <class T> inline void mini(T &l, T r){l = min(l, r);}
template <class T> inline void maxi(T &l, T r){l = max(l, r);}

template <class T> void _dbg(const char *sdbg, T &&h){cerr << sdbg << "=" << h << "\n";}
template <class T, class ...R> void _dbg(const char *sdbg, T h, R... a){
	while (*sdbg != ','){cerr << *sdbg++;} cerr << "=" << h << ","; _dbg(sdbg + 1, a...);}
template <class L, class R> ostream &operator <<(ostream &os, pair<L, R> &P){
	return os << "(" << P.st << "," << P.nd << ")";}
template <class T> ostream &operator <<(ostream &os, const vector<T> &v){
	os << "["; for (auto x: v) os << x << ","; return os << "]";}
template <class IT, class V = vector<typename iterator_traits<IT>::value_type>> V gr(IT b, IT e){
	return V(b, e);}
template <class T, class c = decltype(T().begin())> ostream &operator <<(ostream &os, T &v){
	return os << gr(v.begin(), v.end());}
template <class T, int I, int N, typename enable_if<I == N, T>::type* = nullptr> void TuplePrint(ostream &os, T val){
	os << get<N>(val);}
template <class T, int I, int N, typename enable_if<I < N, T>::type* = nullptr> void TuplePrint(ostream &os, T val){
	os << get<I>(val) << ","; TuplePrint<T, I + 1, N>(os, val);}
template <class... Ts> ostream &operator<<(ostream &os, tuple<Ts...> t){
	os << "("; TuplePrint<tuple<Ts...>, 0, sizeof...(Ts) - 1>(os, t); return os << ")";}

#ifdef SFIC
#define eput(...) do{cerr << __LINE__;_dbg("\t| "#__VA_ARGS__, __VA_ARGS__);}while(0)
#else
#define eput(...) 218
#endif

//pd::priority_queue<int, less<int>, pairing_heap_tag>
//pd::tree<int, int, less<int>, pd::rb_tree_tag, pd::tree_order_statistics_node_update>
//constexpr int N = 1E5 + 10, M = 1E9 + 7;
//constexpr ll INF = LLONG_MAX >> 1;
//constexpr double eps = 1E-9;

const int N = 24;

ull a[N];
ull fac[N];

int main(){
	fac[0] = 1;
	for (int i = 1; i < N; ++i)
		fac[i] = fac[i - 1] * i;

	int cas;
	scanf("%d", &cas);
	while (cas--){
		ull t;
		scanf("%llu", &t);

		int m = 2;
		memset(a, 0, sizeof(a));
		for (; t; t /= m, ++m)
			++a[t % m];
		--m;

		ull dem = 1;
		for (int j = 0; j < m; ++j)
			dem = dem * fac[a[j]];

		eput(gr(a, a + N));
		eput(m);

		ull ans = 0;
		for (int i = 1; i < m; ++i){
			if (a[i] == 0)
				continue;

			--a[i];
			ull cur = a[0] + a[1], s = a[i] + 1;
			for (int j = 2; j < m; ++j){
				if (cur <= 0){
					s = 0;
					break;
				}

				s *= cur;
				--cur;
				cur += a[j];
			}
			eput(s, dem, s / dem, s % dem);
			ans += s / dem;

			++a[i];
		}
		printf("%llu\n", ans - 1);
	}
	return 0;
}