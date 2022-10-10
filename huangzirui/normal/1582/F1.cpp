/************************************************
*Author        :  demonlover
*Created Time  :  2021.12.19.19:44
*Problem       :  CF1582F
************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
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
	const int maxn = 1e6+10,maxm = 5e3+10,maxk = 8192;
	int a[maxn],f[maxm][maxk];
	bool vis[maxn];
	int n,ans;
	vector<int> v[maxn];
	inline int main() {
		read(n);
		for (int i = 1;i <= n;++i)read(a[i]),v[a[i]].push_back(i);
		memset(f,0x3f,sizeof(f));
		f[0][0] = 0;
		for (int i = 0;i <= 5000;++i)
			for (int j = 0;j <= 8191;++j) {
				f[i+1][j] = min(f[i+1][j],f[i][j]);
				if (f[i][j] <= n)vis[j] = true;
				int tmp = upper_bound(v[i+1].begin(),v[i+1].end(),f[i][j])-v[i+1].begin();
				if (tmp >= (int)v[i+1].size())continue;
				f[i+1][j^(i+1)] = min(f[i+1][j^(i+1)],v[i+1][tmp]);
			}
		for (int i = 0;i <= 8191;++i)ans += vis[i];
		printf("%d\n",ans);
		for (int i = 0;i <= 8191;++i)if (vis[i])printf("%d ",i);
		puts("");
		return 0;
	}
}

int main() {
#ifdef demonlover
	freopen("CF1582F.in","r",stdin);
	freopen("CF1582F.out","w",stdout);
#endif
	return run :: main();
}