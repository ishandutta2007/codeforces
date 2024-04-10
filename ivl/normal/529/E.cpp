#include <cstdio>
#include <algorithm>

#define FOR(a,b,c) for (int c = (a), __for = (b); c < __for; ++c)
#define REP(n) for (int __rep = 0, __for = (n); __rep < __for; ++__rep)

using namespace std;

const int oo = 1000000000;

int n, k;
int a[5005];

bool cnt[10000005];

int main(){
	scanf("%d%d", &n, &k);
	FOR(0,n,i) scanf("%d", a + i);
	FOR(0,n,i) cnt[a[i]] = true;
	int q; scanf("%d", &q);
	REP(q){
		int x; scanf("%d", &x);
		int r = oo;
		FOR(0,n,i)
			FOR(0,k+1,t1)
				FOR(0,k+1-t1,t2){
					int cr = x - a[i] * t1;
					if (t2 == 0){
						if (cr != 0) continue;
						r = min(r, t1); continue;
					}
					if (cr % t2) continue;
					cr /= t2;
					if (cr <= 0 || cr > 10000000) continue;
					if (cnt[cr]) r = min(r, t1 + t2);
				}
		if (r == oo) r = -1;
		printf("%d\n", r);
	}
	return 0;
}