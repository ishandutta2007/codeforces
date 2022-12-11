#include <algorithm>
#include <cstdio>
#include <bitset>
using namespace std;

const int M = 17500;
const int N = 3e8 + 5;

int l, r, p[M], cnt;

bitset<M> tag;
bitset<N / 4 + 5> vis;

void sieve(int n) {
	tag.reset(); tag[1] = 1;
	for(int i = 2; i <= n; i ++) {
		if(!tag[i]) p[++ cnt] = i;
		for(int j = 1; j <= cnt && p[j] * i <= n; j ++) {
			tag[i * p[j]] = 1;
			if(i % p[j] == 0) break ;
		}
	}
}

int main() {
	scanf("%d%d", &l, &r); sieve(min(M - 5, r));
	int ans = (l <= 2 && 2 <= r); l = max(l, 3);
	vis.reset();
	for(int i = 1; i <= cnt; i ++)
		for(int j = p[i] * max(2, l / p[i]); j <= r; j += p[i]) 
			if(j >= l && j % 4 == 1) vis[(j - 1) / 4] = 1;
	for(int i = max(1, l / 4); i <= r / 4; i ++)
		if(l <= i * 4 + 1 && i * 4 + 1 <= r && !vis[i]) ans ++;
	printf("%d\n", ans);
	return 0;
}