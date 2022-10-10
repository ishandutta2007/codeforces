/************************************************
*Author        :  demonlover
*Created Time  :  2021.12.20.16:12
*Problem       :  CF1493E
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
	const int maxn = 1e6+10;
	int a[maxn],b[maxn];
	int n;
	inline int main() {
		read(n);
		bool flg = true;
		for (int i = 1;i <= n;++i)scanf("%1d",&a[i]);
		for (int i = 1;i <= n;++i)scanf("%1d",&b[i]),flg &= b[i];
		if ((a[1] ^ b[1]) || flg) {
			for (int i = 1;i <= n;++i)putchar(49);
			puts("");
			return 0;
		}
		flg = true;
		for (int i = 1;i <= n;++i)flg &= (a[i] == b[i]);
		if (flg) {
			for (int i = 1;i <= n;++i)putchar(b[i]+'0');
			puts("");
			return 0;
		}
		a[n]++;
		for (int i = n;i;--i)if (a[i] > 1)a[i] -= 2,a[i-1]++;
		flg = true;
		for (int i = 1;i <= n;++i)flg &= (a[i] == b[i]);
		if (flg) {
			for (int i = 1;i <= n;++i)putchar(b[i]+'0');
			puts("");
			return 0;
		}
		if (b[n] == '1') {
			for (int i = 1;i <= n;++i)putchar(b[i]+'0');
			puts("");
			return 0;
		}
		b[n] = 1;
		for (int i = 1;i <= n;++i)putchar(b[i]+'0');
		puts("");
		return 0;
	}
}

int main() {
#ifdef demonlover
	freopen("CF1493E.in","r",stdin);
	freopen("CF1493E.out","w",stdout);
#endif
	return run :: main();
}