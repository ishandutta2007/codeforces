/************************************************
*Author        :  demonlover
*Created Time  :  2021.12.18.14:03
*Problem       :  CF1486A
************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
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
	const int maxn = 1e4+10;
	int a[maxn];
	int n;
	inline void main() {
		read(n);
		for (int i = 1;i <= n;++i)read(a[i]);
		a[n+1] = 0;
		for (int i = 1;i <= n;++i) {
			a[i+1] += a[i]-(i-1);
			if (a[i] <= a[i-1] && (i ^ 1))return puts("NO"),void();
			a[i] = i-1;
		}
		puts("YES");
		return;
	}
}

#undef int
int main() {
#ifdef demonlover
	freopen("CF1486A.in","r",stdin);
	freopen("CF1486A.out","w",stdout);
#endif
	int T;read(T);
	while (T--)run :: main();
	return 0;
}