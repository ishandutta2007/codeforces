/************************************************
*Author        :  demonlover
*Created Time  :  2021.12.20.19:29
*Problem       :  CF1550C
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
	int n,ans;
	inline bool check(int a,int b,int c) {
		if ((a <= b && b <= c) || (a >= b && b >= c))return false;
		return true;
	}
	inline void main() {
		read(n);
		for (int i = 1;i <= n;++i)read(a[i]);
		if (n == 1)return puts("1"),void();
		ans = n*2-1;
		for (int i = 1;i <= n-2;++i)
			if (check(a[i],a[i+1],a[i+2]))
				ans++;
		for (int i = 1;i <= n-3;++i)
			if (check(a[i],a[i+1],a[i+2]) && check(a[i],a[i+1],a[i+3]) && check(a[i],a[i+2],a[i+3]) && check(a[i+1],a[i+2],a[i+3]))
				ans++;
		printf("%d\n",ans);
		return;
	}
}

int main() {
#ifdef demonlover
	freopen("CF1550C.in","r",stdin);
	freopen("CF1550C.out","w",stdout);
#endif
	int T;read(T);
	while (T--)run :: main();
	return 0;
}