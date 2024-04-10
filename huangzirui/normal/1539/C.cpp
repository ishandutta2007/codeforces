/************************************************
*Author        :  demonlover
*Created Time  :  2021.12.20.15:18
*Problem       :  CF1539C
************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
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
	const int maxn = 2e5+10;
	ll a[maxn],b[maxn];
	ll n,k,x,tot,ans;
	inline int main() {
		read(n,k,x);
		for (int i = 1;i <= n;++i)read(a[i]);
		sort(a+1,a+1+n);
		for (int i = 2;i <= n;++i)if (a[i]-a[i-1] > x)b[++tot] = a[i]-a[i-1];
		sort(b+1,b+1+tot);
		ans = tot+1;
		for (int i = 1;i <= tot;++i)
			if (k >= (b[i]-1)/x)k -= (b[i]-1)/x,ans--;
		printf("%d\n",ans);
		return 0;
	}
}

int main() {
#ifdef demonlover
	freopen("CF1539C.in","r",stdin);
	freopen("CF1539C.out","w",stdout);
#endif
	return run :: main();
}