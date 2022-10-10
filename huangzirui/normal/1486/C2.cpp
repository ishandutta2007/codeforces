/************************************************
*Author        :  demonlover
*Created Time  :  2021.12.18.14:15
*Problem       :  CF1486C1
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
	int n;
	inline int main() {
		read(n);
		printf("? 1 %d\n",n);
		fflush(stdout);
		int pos;read(pos);
		int l = 1,r = n;
		if (pos == 1)l = 2;
		else {
			int tmp;
			printf("? 1 %d\n",pos);
			fflush(stdout);
			read(tmp);
			if (tmp == pos)r = pos-1;
			else l = pos+1;
		}
		if (l == pos+1) {
			while (l < r) {
				int mid = (l+r)>>1;
				printf("? %d %d\n",pos,mid);
				fflush(stdout);
				int tmp;read(tmp);
				if (tmp == pos)r = mid;
				else l = mid+1;
			}
		}
		else {
			while (l < r) {
				int mid = (l+r+1)>>1;
				printf("? %d %d\n",mid,pos);
				fflush(stdout);
				int tmp;read(tmp);
				if (tmp == pos)l = mid;
				else r = mid-1;
			}
		}
		printf("! %d\n",l);
		fflush(stdout);
		return 0;
	}
}

int main() {
#ifdef demonlover
	freopen("CF1486C1.in","r",stdin);
	freopen("CF1486C1.out","w",stdout);
#endif
	return run :: main();
}