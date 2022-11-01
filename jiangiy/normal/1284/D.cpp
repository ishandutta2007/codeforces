#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define xx first
#define yy second

typedef long long ll;

const int N = 200005;

int n, sa[N], ea[N], sb[N], eb[N], wa[N], wb[N], v[N];
pair<int, int> t[N];

void work(int *s, int *e, int *w, int &wc) {
	for (int i = 1; i <= n; i++) {
		t[i] = mp(s[i], i);
		t[i + n] = mp(e[i] + 1, -i);
	}
	std::sort(t + 1, t + n * 2 + 1);
	int lst = -1, u = 0, c = 0;
	for (int i = 1; i <= n * 2; i++) {
		if (lst > 0 && t[i].yy < 0 && c > 1) {
			w[wc++] = u;
		}
		u ^= v[abs(t[i].yy)];
		c += t[i].yy > 0 ? 1 : -1;
		//printf("%d %d %d %d\n",i,u,c,lst);
		lst = t[i].yy;
	}
}

int main() {
	std::mt19937 ran(time(0) ^ reinterpret_cast<ll>(new char));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d%d", sa + i, ea + i, sb + i, eb + i),
		v[i] = ran();
	int ca = 0, cb = 0;
	work(sa, ea, wa, ca);
	work(sb, eb, wb, cb);
	std::sort(wa,wa+ca);
	std::sort(wb,wb+cb);
	//printf("%d %d\n",ca,cb);
	if(ca!=cb)return puts("NO"),0;
	for(int i=0;i<ca;i++)if(wa[i]!=wb[i])return puts("NO"),0;
	puts("YES");
}