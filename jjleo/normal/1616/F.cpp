#include <bits/stdc++.h>
#define maxn 10086
#define maxm 260

using namespace std;

bitset<maxm> a[maxn][2];

int t;
int n, m;
int e[100][100];
int x, y, c[maxm];

void add(int i, int j){ // i += j
	bitset<maxm> b[2];
	bitset<maxm> x = ~a[i][0] & ~a[i][1], y = ~a[j][0] & ~a[j][1];
	b[0] = x & a[j][0] | y & a[i][0] | a[i][1] & a[j][1];
	b[1] = x & a[j][1] | y & a[i][1] | a[i][0] & a[j][0];
	a[i][0] = b[0], a[i][1] = b[1];
}

void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) e[i][j] = 0;
	for(int i = 1;i <= m;i++){
		scanf("%d%d%d", &x, &y, &c[i]);
		e[x][y] = e[y][x] = i;
	}
	int N = 0;
	for(int i = 1;i <= n;i++) for(int j = i + 1;j <= n;j++) for(int k = j + 1;k <= n;k++) if(e[i][j] && e[j][k] && e[k][i]){
		int sum = 0;
		a[++N][0].reset(), a[N][1].reset();
		if(c[e[i][j]] == -1) a[N][0][e[i][j]] = 1;
		else sum += c[e[i][j]];
		if(c[e[j][k]] == -1) a[N][0][e[j][k]] = 1;
		else sum += c[e[j][k]];
		if(c[e[k][i]] == -1) a[N][0][e[k][i]] = 1;
		else sum += c[e[k][i]];
		sum = (3 - sum % 3) % 3;
		a[N][0][m + 1] = sum & 1;
		a[N][1][m + 1] = (sum & 2) != 0;
	} 
	n = N;
	int now = 1;
	for(int i = 1;i <= m && now <= n;i++){
		for(int j = now;j <= n;j++) if(a[j][0][i] || a[j][1][i]){
			if(j ^ now) swap(a[now][0], a[j][0]), swap(a[now][1], a[j][1]);
			break;
		}
		if(!a[now][0][i] && !a[now][1][i]) continue;
		if(a[now][1][i]) add(now, now);
		for(int j = 1;j <= n;j++) if(j ^ now){
			while(a[j][0][i] || a[j][1][i]) add(j, now); 
		}
		now++;
	}
	for(int i = now;i <= n;i++){
		bool tag = false;
		for(int j = 1;j <= m;j++) if(a[i][0][j] || a[i][1][j]){
			tag = true;
			break;
		}
		if(!tag && (a[i][0][m + 1] || a[i][1][m + 1])) return (void)puts("-1"); 
	}
	for(int i = now - 1;i;i--){
		int x;
		for(int j = 1;;j++) if(a[i][0][j] || a[i][1][j]){
			x = j;
			break;
		}
		int sum = 0;
		for(int j = x + 1;j <= m;j++){
			if(c[j] == -1) c[j] = 0;
			sum -= c[j] * (a[i][0][j] | (a[i][1][j] << 1));
		}
		sum += a[i][0][m + 1] | (a[i][1][m + 1] << 1);
		assert(c[x] == -1);
		c[x] = (sum % 3 + 3) % 3;
	}
	for(int i = 1;i <= m;i++) printf("%d ", c[i] <= 0 ? 3 : c[i]);puts("");
}

int main(){
	scanf("%d", &t);
	while(t--) solve();
}

/*
1
4 5
1 2 -1
1 3 -1
2 3 1
2 4 -1
3 4 -1
*/