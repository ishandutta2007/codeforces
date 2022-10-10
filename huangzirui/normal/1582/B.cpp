/************************************************
*Author        :  demonlover
*Created Time  :  2021.12.19.19:02
*Problem       :  CF1582B
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
	int n,cnt0,cnt1;
	inline int main() {
		read(n);
		cnt0 = cnt1 = 0;
		for (int i = 1,x;i <= n;++i) {
			read(x);
			if (!x)cnt0++;
			if (x == 1)cnt1++;
		}
		printf("%lld\n",1ll*(1ll<<cnt0)*cnt1);
		return 0;
	}
}

int main() {
#ifdef demonlover
	freopen("CF1582B.in","r",stdin);
	freopen("CF1582B.out","w",stdout);
#endif
	int T;read(T);
	while (T--)run :: main();
	return 0;
}