/************************************************
*Author        :  demonlover
*Created Time  :  2021.12.18.14:57
*Problem       :  CF1486E
************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
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
	const int maxn = 5e6+1e5+10;
	vector< pii > g[maxn];
	int n,m;
	inline void add(int x,int y,int z) {
		g[x].push_back(pii(y+n*z,0));
		for (int i = 1;i <= 50;++i)g[i*n+x].push_back(pii(y,z));
		return;
	}
	inline int calc(int x) {return x*x;}
	int dis[maxn];
	priority_queue< pii > q;
	inline void dijkstra() {
		memset(dis,0x3f,sizeof(dis));dis[1] = 0;
		q.push(pii(0,1));
		while (!q.empty()) {
			int x = q.top().second;q.pop();
			for (auto [y,w] : g[x]) {
				if (dis[y] > dis[x]+calc((x-1)/n+w)) {
					dis[y] = dis[x]+calc((x-1)/n+w);
					q.push(pii(-dis[y],y));
				}
			}
		}
		return;
	}
	inline int main() {
		read(n,m);
		for (int i = 1,x,y,z;i <= m;++i) {
			read(x,y,z);
			add(x,y,z);add(y,x,z);
		}
		dijkstra();
		for (int i = 1;i <= n;++i)printf("%d ",dis[i] > 1e9 ? -1 : dis[i]);
		return 0;
	}
}

int main() {
#ifdef demonlover
	freopen("CF1486E.in","r",stdin);
	freopen("CF1486E.out","w",stdout);
#endif
	return run :: main();
}