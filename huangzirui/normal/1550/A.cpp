/************************************************
*Author        :  demonlover
*Created Time  :  2021.12.20.19:15
*Problem       :  CF1550A
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
	int n;
	inline void main() {
		read(n);
		int ans = 0;
		for (int i = 1,sum = 0;sum < n;i += 2) {
			sum += i;
			ans++;
		}
		printf("%d\n",ans);
		return;
	}
}

int main() {
#ifdef demonlover
	freopen("CF1550A.in","r",stdin);
	freopen("CF1550A.out","w",stdout);
#endif
	int T;read(T);
	while (T--)run :: main();
	return 0;
}