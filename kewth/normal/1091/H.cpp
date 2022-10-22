#if 0
2020.03.13

Alice  Bob  S  d 
 d 
 k  SG 

 O(n^2)  bitset  f[x][k]  k  sg=x 
d k  f  k  SG  x S << k  f[x] 
#endif
#include <cstdio>
#include <algorithm>
#include <bitset>

typedef long long ll;
typedef size_t si;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
} read;

const int maxn = 200005;
int sg[maxn];
int minp[maxn];
std::bitset<maxn> S;
std::bitset<maxn> mex[1000];

int main() {
	int n = read, forbit = read;
	int V = 200000;
	minp[1] = 1;
	for(int i = 2; i <= V; i ++)
		if(!minp[i]) {
			minp[i] = i;
			if(i <= V / i)
				for(int j = i * i; j <= V; j += i)
					if(!minp[j])
						minp[j] = i;
			S[si(i)] = 1;
		} else {
			int j = i / minp[i];
			if(minp[j] == j)
				S[si(i)] = 1;
		}

	S[si(forbit)] = 0;

	for(int x = 0; x <= V; x ++) {
		while(mex[sg[x]][si(x)])
			++ sg[x];
		mex[sg[x]] |= S << si(x);
	}


	int ans = 0;
	for(int i = 1; i <= n; i ++) {
		int a = read, b = read, c = read;
		ans ^= sg[b - a - 1] ^ sg[c - b - 1];
	}

	if(ans) printf("Alice\nBob\n");
	else printf("Bob\nAlice\n");
}