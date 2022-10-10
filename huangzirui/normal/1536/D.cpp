/************************************************
*Author        :  demonlover
*Created Time  :  2021.12.18.10:53
*Problem       :  CF1536D
************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
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
	set<int> s;
	inline void main() {
		read(n);
		s.clear();
		bool flg = false;
		for (int i = 1;i <= n;++i) {
			read(a[i]);
			if (!s.count(a[i]))s.insert(a[i]);
			if (a[i-1] == a[i])continue;
			if (a[i-1] < a[i]) {
				if (s.upper_bound(a[i-1]) != s.find(a[i]))flg = true;
			}
			else {
				if (s.upper_bound(a[i]) != s.find(a[i-1]))flg = true;
			}
		}
		if (flg)puts("NO");
		else puts("YES");
		return;
	}
}

int main() {
#ifdef demonlover
	freopen("CF1536D.in","r",stdin);
	freopen("CF1536D.out","w",stdout);
#endif
	int T;read(T);
	while (T--)run :: main();
	return 0;
}