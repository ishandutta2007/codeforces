/************************************************
*Author        :  demonlover
*Created Time  :  2021.12.19.20:24
*Problem       :  CF1582G
************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <ctime>
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
	const int maxn = 1e6+10;
	int prime[maxn],fac[maxn],cnt;
	bool vis[maxn];
	int a[maxn],pre[maxn];
	int val[maxn],stk[maxn],top;
	int n;
	ll ans;
	vector<int> v[maxn];
	inline void init() {
		for (int i = 2;i < maxn;++i) {
			if (!vis[i])prime[++cnt] = i,fac[i] = i;
			for (int j = 1;j <= cnt && i*prime[j] < maxn;++j) {
				vis[i*prime[j]] = true;
				fac[i*prime[j]] = prime[j];
				if (i%prime[j] == 0)break;
			}
		}
		return;
	}
	inline int main() {
		init();
		read(n);
		for (int i = 1;i <= n;++i)read(a[i]);
		for (int i = 1;i <= n;++i) {
			char ch = getchar();
			while (ch != '*' && ch != '/')ch = getchar();
			if (ch == '*') {
				while (a[i] > 1) {
					int tmp = fac[a[i]];
					v[tmp].push_back(i);
					a[i] /= tmp;
				}
				pre[i] = i;
			}
			else {
				pre[i] = i;
				while (a[i] > 1) {
					int tmp = fac[a[i]];
					if (!v[tmp].empty())pre[i] = min(pre[i],v[tmp].back()),v[tmp].pop_back();
					else pre[i] = -1;
					a[i] /= tmp;
				}
			}
		}
		for (int i = n;i >= 1;--i) {
			int tmp = 1;
			while (top && pre[i] <= stk[top])tmp += val[top--];
			stk[++top] = pre[i];val[top] = tmp;
			if (pre[i] == i)ans += tmp;
		}
		printf("%lld\n",ans);
		return 0;
	}
}

int main() {
#ifdef demonlover
	freopen("CF1582G.in","r",stdin);
	freopen("CF1582G.out","w",stdout);
#endif
	return run :: main();
}