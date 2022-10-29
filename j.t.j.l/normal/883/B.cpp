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

const int M = 2E5 + 10, N = M;

int n, m, K;
int rk[M], lb[M], ub[M], deg[M];
vector<int> E[M], b, c[N];
int h[M];

int main(){
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 1; i <= n; ++i){
		scanf("%d", rk + i);
		if (rk[i])
			lb[i] = ub[i] = rk[i];
		else
			lb[i] = 1, ub[i] = K;
	}
	for (int i = 0; i < m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		++deg[v];
	}

	queue<int> Q;
	for (int i = 1; i <= n; ++i)
		if (deg[i] == 0)
			Q.push(i);
	while (!Q.empty()){
		int u = Q.front();
		Q.pop();
		b.push_back(u);

		for (auto &v: E[u])
			if (--deg[v] == 0)
				Q.push(v);
	}
	if (b.size() < n){
		puts("-1");
		return 0;
	}

	for (int i = 0; i < n; ++i){
		int u = b[i];
		for (auto &v: E[u])
			ub[v] = min(ub[v], ub[u] - 1);
	}
	for (int i = n - 1; i >= 0; --i){
		int u = b[i];
		for (auto &v: E[u])
			lb[u] = max(lb[u], lb[v] + 1);
	}
	for (int i = 1; i <= n; ++i){
		if (lb[i] > ub[i]){
			puts("-1");
			return 0;
		}
		c[ub[i]].push_back(i);
	}

	priority_queue<pii> Q1;
	for (int i = K; i >= 1; --i){
		for (auto &t: c[i])
			Q1.emplace(lb[t], t);
		if (Q1.empty()){
			puts("-1");
			return 0;
		}

		int u = Q1.top().nd;
		rk[u] = i;
		Q1.pop();
		for (; !Q1.empty() && Q1.top().st == i; Q1.pop())
			rk[Q1.top().nd] = i;
	}
	for (int i = 1; i <= n; ++i)
		printf("%d%c", rk[i], "\n "[i < n]);
	return 0;
}