#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <bitset>
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
const int M = 4010;
bitset<M> f[2];
int n, k;
bool vis[1010];
int main() {
	int n; scanf("%d",&n);
	int k; scanf("%d",&k);
	rep(i,1,k) { int x; scanf("%d",&x); vis[x] = true; }
	f[0][2000] = 1;
	rep(i,1,2010) {
		f[i&1] = 0;
		rep(j,0,1000) if (vis[j]) {
			if (j < n) f[i&1] |= f[!(i&1)] >> (n - j);
			else f[i&1] |= f[!(i&1)] << (j - n);
		}
		if (f[i&1][2000]) { printf("%d\n",i); return 0; }
	}
	printf("-1\n");
	return 0;
}