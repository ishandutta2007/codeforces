/************************************************
*Author        :  demonlover
*Created Time  :  2021.12.20.15:32
*Problem       :  CF1539D
************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
using namespace std;
typedef long long ll;
#define int ll
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
	const int maxn = 1e5+10;
	struct node {int x,y;}a[maxn];
	int n,ans;
	inline int main() {
		read(n);
		for (int i = 1;i <= n;++i)read(a[i].x,a[i].y);
		sort(a+1,a+1+n,[] (node u,node v) {return u.y < v.y;});
		for (int l = 1,r = n,tot = 0;l <= r;) {
			if (a[l].y <= tot)tot += a[l].x,ans += a[l].x,l++;
			else {
				int tmp = min(a[r].x,a[l].y-tot);
				tot += tmp;
				ans += tmp*2;
				a[r].x -= tmp;
				if (!a[r].x)r--;
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
}

#undef int
int main() {
#ifdef demonlover
	freopen("CF1539D.in","r",stdin);
	freopen("CF1539D.out","w",stdout);
#endif
	return run :: main();
}