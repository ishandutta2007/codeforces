#include <bits/stdc++.h>
#define maxn 606

using namespace std;

typedef long long ll;

int n, m;
ll a[maxn][maxn], d[maxn];
int x, y, z;
bool tag[maxn];

int main(){
	scanf("%d%d", &n, &m);
	memset(a, 0x3f, sizeof(a));
	while(m--) scanf("%d%d%d", &x, &y, &z), a[x][y] = z;
	for(int i = 0;i < n;i++){
		memset(d, 0x3f, sizeof(d));
		memset(tag, 0, sizeof(tag));//, tag[i] = true;
		for(int j = 0;j < n;j++) d[j] = min(d[j], a[i][j]);
		for(int j = 1;j < n;j++){
			int x = -1;
			for(int k = 0;k < n;k++) if(!tag[k] && (x == -1 || d[x] > d[k])) x = k;
			//for(int k = 0;k < n;k++) d[k] = min(d[k], d[x] + a[x][k]);
			for(int k = 0;k < n;k++) d[(k + d[x]) % n] = min(d[(k + d[x]) % n], d[x] + a[x][k]);
			d[(x + 1) % n] = min(d[(x + 1) % n], d[x] + 1);
			tag[x] = true;
		}
		d[i] = 0;
		for(int j = 0;j < n;j++) printf("%lld ", d[j]);puts("");
	}
}