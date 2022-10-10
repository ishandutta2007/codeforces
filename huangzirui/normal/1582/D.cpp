/************************************************
*Author        :  demonlover
*Created Time  :  2021.12.19.19:13
*Problem       :  CF1582D
************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
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
	int a[maxn];
	int n;
	inline void main() {
		read(n);
		for (int i = 1;i <= n;++i)read(a[i]);
		if (!(n&1)) {
			for (int i = 1;i <= n;i += 2)printf("%d %d ",-a[i+1],a[i]);
			puts("");
			return;
		}
		if (a[1]+a[2])printf("%d %d %d ",-a[3],-a[3],a[1]+a[2]);
		else if (a[2]+a[3])printf("%d %d %d ",a[2]+a[3],-a[1],-a[1]);
		else printf("%d %d %d ",-a[2],a[1]+a[3],-a[2]);
		for (int i = 4;i <= n;i += 2)printf("%d %d ",-a[i+1],a[i]);
		puts("");
		return;
	}
}

int main() {
#ifdef demonlover
	freopen("CF1582D.in","r",stdin);
	freopen("CF1582D.out","w",stdout);
#endif
	int T;read(T);
	while (T--)run :: main();
	return 0;
}