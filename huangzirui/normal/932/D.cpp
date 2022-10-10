/************************************************
*Author        :  demonlover
*Created Time  :  2021.12.22.16:13
*Problem       :  CF932D
************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair <int,int> pii;
#define DEBUG(x) cout << #x << " = " << x << "\n"
template <typename T>
inline bool read(T &x) {
	int f = 1,c = getchar();x = 0;
	while (!isdigit(c)) {if (c == 45)f = -1;c = getchar();}
	while (isdigit(c))x = (x<<3)+(x<<1)+(c^48),c = getchar();
	return x *= f,true;
}
template <typename T,typename... Args>
inline bool read(T &x,Args &...args) {
	return read(x) && read(args...);
}

namespace run {
	const int maxn = 5e5+10;
	const ll inf = 0x3f3f3f3f3f3f3f3fll;
	ll val[maxn],sum[maxn][24];
	int fa[maxn][24];
	inline void add(int x,int y) {
		if (val[x] >= val[y])fa[y][0] = x;
		else {
			for (int i = 19;~i;--i) {
				if (val[fa[x][i]] < val[y])x = fa[x][i];
				fa[y][0] = fa[x][0];
			}
		}
		sum[y][0] = val[fa[y][0]];
		for (int i = 1;i <= 19;++i) {
			fa[y][i] = fa[fa[y][i-1]][i-1];
			if (fa[y][i])sum[y][i] = sum[y][i-1]+sum[fa[y][i-1]][i-1];
			else sum[y][i] = inf;
		}
		return;
	}
	inline int query(int x,ll tot) {
		if (val[x] > tot)return 0;
		tot -= val[x];
		int now = x,ans = 1;
		for (int i = 19;~i;--i)
			if (tot >= sum[now][i]) {
				tot -= sum[now][i];
				ans += 1<<i;
				now = fa[now][i];
			}
		return ans;
	}
	inline int main() {
		int q;read(q);
		val[0] = inf;
		memset(sum[1],inf,sizeof(sum[1]));
		ll lst = 0;
		int cnt = 1;
		for (int i = 1,opt;i <= q;++i) {
			ll a,b;read(opt,a,b);
			a ^= lst,b ^= lst;
			if (opt == 1)val[++cnt] = b,add(a,cnt);
			else lst = query(a,b),printf("%lld\n",lst);
		}
		return 0;
	}
}

int main() {
#ifdef demonlover
	freopen("CF932D.in","r",stdin);
	freopen("CF932D.out","w",stdout);
#endif
	return run :: main();
}