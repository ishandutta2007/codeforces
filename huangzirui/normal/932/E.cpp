/************************************************
*Author        :  demonlover
*Created Time  :  2021.12.22.15:36
*Problem       :  CF932E
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
	const int maxn = 5e3+10;
	const int mod = 1e9+7;
	int s[maxn][maxn];
	int ans,n,k;
	inline void init() {
		s[0][0] = 1;
		for (int i = 1;i <= k;++i)
			for (int j = 1;j <= i;++j)
				s[i][j] = (s[i-1][j-1]+1ll*s[i-1][j]*j%mod)%mod;
		return;
	}
	inline int power(int a,int b) {
		int res = 1;
		while (b) {
			if (b&1)res = 1ll*res*a%mod;
			a = 1ll*a*a%mod;
			b >>= 1;
		}
		return res;
	}
	inline int main() {
		read(n,k);
		init();
		int f = 1,bin2 = power(2,n),inv2 = power(2,mod-2);
		for (int i = 0;i <= k;++i) {
			ans = (ans+1ll*f*s[k][i]%mod*bin2%mod)%mod;
			f = 1ll*f*(n-i)%mod;
			bin2 = 1ll*bin2*inv2%mod;
		}
		if (!k)--ans;
		printf("%d\n",ans);
		return 0;
	}
}

int main() {
#ifdef demonlover
	freopen("CF932E.in","r",stdin);
	freopen("CF932E.out","w",stdout);
#endif
	return run :: main();
}