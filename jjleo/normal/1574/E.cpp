#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

const int p = 998244353;

int n, m, k;
map<pair<int, int>, bool> mp;
int x, y, t;
int cnta[3], cntb[3], cntc[2];
int a[maxn][2], b[maxn][2];
int pw[maxn];

void modify(int x, int y, int z, int c){
	cnta[(a[x][0] != 0) + (a[x][1] != 0)]--;
	a[x][(y + c) & 1] += z;
	cnta[(a[x][0] != 0) + (a[x][1] != 0)]++;
	cntb[(b[y][0] != 0) + (b[y][1] != 0)]--;
	b[y][(x + c) & 1] += z;
	cntb[(b[y][0] != 0) + (b[y][1] != 0)]++;
	cntc[(x + y + c) & 1] += z;
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	pw[0] = 1;for(int i = 1;i < maxn;i++) pw[i] = (pw[i - 1] + pw[i - 1]) % p;
	cnta[0] = n, cntb[0] = m;
	while(k--){
		scanf("%d%d%d", &x, &y, &t);
		if(mp.find({x, y}) != mp.end()){
			modify(x, y, -1, mp[{x, y}]);
			//printf("%d %d %d--\n", x, y, mp[{x, y}]);
			mp.erase({x, y});
		}
		if(t != -1){
			mp[{x, y}] = t;
			modify(x, y, 1, t);
		}
		int ans = 0;
		if(!cnta[2]) ans = (ans + pw[cnta[0]]) % p;
		if(!cntb[2]) ans = (ans + pw[cntb[0]]) % p;
		if(!cntc[0]) ans = (ans + p - 1) % p;
		if(!cntc[1]) ans = (ans + p - 1) % p;
		printf("%d\n", ans);
	}
}