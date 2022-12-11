#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
template <typename T>
void read(T &x) {
	x = 0;int f = 1;
	char c = getchar();
	for (;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x *= f;
}
const int N = 5e5;
int n, v[N];
int h[N], ne[N], to[N];
int dep[N], f[N], tot;
inline void add(int x,int y) {
	ne[++tot] = h[x], h[x] = tot;
	to[tot] = y;
}
struct node{
	int dep, num;
	bool operator < (const node &i) const{
		return dep > i.dep;
	}
}p[N];
void dfs(int x,int fa) {
	p[x] = (node){p[fa].dep+1, x};
	f[x] = fa;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i];
		if (y == fa) continue;
		dfs(y, x);
	}
}
int main() {
	read(n);
	for (int i = 1;i < n; i++) {
		int x, y;
		read(x), read(y);
		add(x, y); add(y, x);
	}
	dfs(1, 0);
	sort(p + 1,p + n + 1);
	int ans = 0;
	for (int i = 1;i <= n; i++) {
		if (p[i].dep <= 3) break;
		if (!v[p[i].num]) {
			ans++;
			v[f[p[i].num]] = 1;
			for (int j = h[f[p[i].num]]; j; j = ne[j]) 
				v[to[j]] = 1;
		}
	}
	cout << ans << endl;
	return 0;
}