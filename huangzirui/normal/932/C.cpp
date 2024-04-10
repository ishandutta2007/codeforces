/************************************************
*Author        :  demonlover
*Created Time  :  2021.12.22.15:03
*Problem       :  CF932C
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
	const int maxn = 1e6+10;
	int p[maxn];
	int n,a,b;
	inline int main() {
		read(n,a,b);
		int tmp = n,i = 1;
		bool flg = false;
		if (tmp%a == 0)flg = true;
		if (tmp%b == 0)a = b,flg = true;
		while (i <= n) {
			p[i] = i+a-1;
			if (p[i] > n)break;
			for (int j = p[i];j > i;--j)p[j] = j-1;
			i += a;
			if (!flg) {
				tmp -= a;
				if (tmp%b == 0)a = b,flg = true;
			}
		}
		if (!flg)return puts("-1")&0;
		for (int i = 1;i <= n;++i)printf("%d ",p[i]);
		puts("");
		return 0;
	}
}

int main() {
#ifdef demonlover
	freopen("CF932C.in","r",stdin);
	freopen("CF932C.out","w",stdout);
#endif
	return run :: main();
}