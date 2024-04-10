#if 0
2020.03.19




 f(x)  x 
 f(x)  k 

 k  x 

 x = sum(x_i)  k 
 k_i  x_i = x  x_i = 0 
ps:  k_i  x_i 

 1/x = sum(1/x_i), f(x) = sum(f_i(x_i)) 
 f(x)  k = sum(1 / x_i) sum(k_i x_i) 
 x_i  k >= sum(sqrt(k_i))^2  k 
 k_i x_i^2 = S  S 
 S  1/x = sum(1/x_i)  x_i 


#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef long double ld;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator char () { int x = getchar();
		while(x == ' ') x = getchar(); return char(x); }
} read;

const int maxn = 320005;
const ld eps = 1e-6l;
int ip;
std::vector<int> G[maxn];
int type[maxn];
ld X[maxn], K[maxn];

inline int newnode () { return type[++ ip] = 0, ip; }

int build () {
	int u = newnode();
	for(char c = read; c != ')'; c = read) {
		if(c == '*') G[u].push_back(newnode());
		if(c == '(') G[u].push_back(build());
		if(c == 'S') type[u] = 1;
		if(c == 'P') type[u] = 2;
	}
	return u;
}

void dfs1 (int u) {
	for(int v : G[u]) dfs1(v);
	if(type[u] == 0)
		K[u] = 1;
	if(type[u] == 1) {
		K[u] = 1e300l;
		for(int v : G[u])
			K[u] = std::min(K[u], K[v]);
	}
	if(type[u] == 2) {
		K[u] = 0;
		for(int v : G[u])
			K[u] += sqrtl(K[v]);
		K[u] *= K[u];
	}
}

void dfs2 (int u) {
	if(type[u] == 1) {
		int key = 0;
		for(int v : G[u])
			if(K[v] >= K[u] and K[v] <= K[u])
				key = v;
		for(int v : G[u])
			X[v] = v == key ? X[u] : 0;
	}
	if(type[u] == 2) {
		if(X[u] <= 0)
			for(int v : G[u]) X[v] = 0;
		else {
			ld alpha = 0;
			for(int v : G[u])
				alpha += sqrtl(K[v]);
			alpha *= X[u];
			for(int v : G[u])
				X[v] = alpha / sqrtl(K[v]);
		}
	}
	for(int v : G[u]) dfs2(v);
}

int main () {
	int T = read;
	while(T --) {
		ip = 0;
		int R = read, S = char(read) == '*' ? newnode() : build();
		dfs1(S);
		for(int i = 1; i <= ip; i ++)
			if(type[i] and G[i].empty())
				return 1;
		X[S] = R;
		dfs2(S);
		for(int i = 1; i <= ip; i ++)
			G[i].clear();
		for(int i = 1; i <= ip; i ++)
			if(type[i] == 0 and std::min(X[i] - floorl(X[i]), ceill(X[i]) - X[i]) > eps)
					goto fail;
		printf("REVOLTING");
		for(int i = 1; i <= ip; i ++)
			if(type[i] == 0)
				printf(" %lld", ll(X[i] + eps));
		puts("");
		continue;
fail:
		puts("LOSS");
	}
}