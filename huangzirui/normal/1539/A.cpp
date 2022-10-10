/************************************************
*Author        :  demonlover
*Created Time  :  2021.12.20.15:10
*Problem       :  CF1539A
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
	ll n,m,t;
	inline void main() {
		read(n,m,t);
		ll len = min(n-1,t/m);
		printf("%lld\n",len*(n-len)+(len-1)*len/2);
		return;
	}
}

int main() {
#ifdef demonlover
	freopen("CF1539A.in","r",stdin);
	freopen("CF1539A.out","w",stdout);
#endif
	int T;read(T);
	while (T--)run :: main();
	return 0;
}