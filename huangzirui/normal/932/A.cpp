/************************************************
*Author        :  demonlover
*Created Time  :  2021.12.22.14:51
*Problem       :  CF932A
************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
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
	const int maxn = 1e3+10;
	char str[maxn];
	inline int main() {
		scanf("%s",str);
		int len = strlen(str);
		cout<<str;
		reverse(str,str+len);
		cout<<str<<'\n';
		return 0;
	}
}

int main() {
#ifdef demonlover
	freopen("CF932A.in","r",stdin);
	freopen("CF932A.out","w",stdout);
#endif
	return run :: main();
}