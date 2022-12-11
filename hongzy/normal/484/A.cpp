#include <cstdio>

typedef long long LL;

bool buf[110];

LL calc() {
	LL ans = 0;
	for(int i = 0; i < 63; i ++)
		if(buf[i]) ans += (1LL << i);
	return ans;
}

int main() {
	int T;
	for(scanf("%d", &T); T --; ) {
		LL l, r, ans = 0, num;
		scanf("%lld %lld", &l, &r);
		for(int i = 0; i < 63; i ++)
			buf[i] = (l & (1LL << i)) ? 1 : 0;
		for(int i = 0; i < 63; i ++) {
			if(buf[i]) continue ;
			buf[i] = 1;
			if(calc() > r) {buf[i] = 0; break;}
			++ ans;
		}
		printf("%lld\n", calc());
	}
	return 0;
}