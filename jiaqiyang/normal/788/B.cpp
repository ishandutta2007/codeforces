#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--) 
#define Rep(i,a) for(int i = 0; i < a; i++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ab(x) ((x) < 0 ? -(x) : (x))
using namespace std;
typedef long long LL;
typedef map<int, int>::iterator mit;
typedef set<int>::iterator sit;
const int N = 1e6 + 10;
int n, m, d[N], f[N], cnt = 0;
bool vis[N];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

#define C2(x) (1LL * (x) * ((x) - 1) / 2)

int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n) f[i] = i;
	rep(i,1,m) {
		int a, b; scanf("%d%d",&a,&b);
		if (a == b) cnt++, vis[a] = true;
		else {
			int fa = find(a), fb = find(b);
			f[fa] = fb;
			vis[a] = vis[b] = true; 
			d[a]++, d[b]++;
		}
	}
	rep(i,1,n) vis[find(i)] |= vis[i];
	int tot = 0; rep(i,1,n) if (f[i] == i && vis[i]) tot++;
	if (tot > 1) { printf("0\n"); return 0; }

	LL ans = C2(cnt);
	rep(i,1,n) ans += C2(d[i]);
	ans += 1LL * cnt * (m - cnt);
	cout <<ans<<endl;
	return 0;
}