#include <cstdio>
#include <queue>

typedef long long LL;

const int MAXN = 100100;

struct P {
	int id, w, c, val;
	P(int i = 0, int w_ = 0, int c_ = 0) : id(i), w(w_), c(c_) {
		val = w * (100 - c);
	}
	bool operator < (const P p2) const {
		return val < p2.val;
	}
	bool operator > (const P p2) const {
		return val > p2.val;
	}
};

int n, m;
int c[MAXN], w[MAXN], ans[MAXN][2];
LL ret;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++)
		scanf("%d", & c[i]);
	for(int i = 1; i <= n; i ++)
		scanf("%d", & w[i]);

	std :: priority_queue<P, std :: vector<P>, std :: greater<P> > Q;

	for(int i = 1; i <= n; i ++) {
		ans[i][0] = c[i] / 100;
		Q.push(P(i, w[i], c[i] %= 100));

		ans[i][1] = c[i];
		m -= c[i];

		for(; m < 0; ) {
			P k = Q.top(); Q.pop();
			if(!ans[k.id][1]) continue ;
			ans[k.id][0] ++;
			m += 100;
			ans[k.id][1] = 0;
			ret += k.val;
		}
	}
	printf("%lld\n", ret);

	for(int i = 1; i <= n; i ++)
		printf("%d %d\n", ans[i][0], ans[i][1]);
	return 0;
}