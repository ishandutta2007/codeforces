#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 6e5 + 10;

int n, m;

int f[10][10][10];
int g[10];

char s[MAXN];
int tree[MAXN][5][5];
int ans[5][5];

void read(){

}

void query(int u, int l, int r, int ll, int rr){
	if (l == ll && r == rr){
		for(int j = 0; j <= 4; j++)
			for(int k = j; k <= 4; k++)
				ans[j][k] = tree[u][j][k];
		return ;
	}
	int m = (l + r) / 2;
	if (rr <= m)
		query(u << 1, l, m, ll, rr);
	else
		if (ll > m)
			query((u << 1) | 1, m + 1, r, ll, rr);
		else{
			query(u << 1, l, m, ll, m);
			int x[5][5];
			for(int j = 0; j <= 4; j++)
				for(int k = j; k <= 4; k++)
					x[j][k] = ans[j][k];
			query((u << 1) | 1, m + 1, r, m+1, rr);
			int y[5][5];
			for(int j = 0; j <= 4; j++)
				for(int k = j; k <= 4; k++)
					y[j][k] = ans[j][k];
			for(int j = 0; j <= 4; j++)
				for(int k = j; k <= 4; k++){
					ans[j][k] = n;
					for(int l = j; l <= k; l++)
						ans[j][k] = min(ans[j][k], x[j][l] + y[l][k]);
				}
		}
}

void solve(){
	f[0][0][2] = 1;
	f[1][1][0] = 1;
	f[2][2][1] = 1;
	f[3][3][6] = 1;
	f[3][3][7] = 1;
	f[4][4][6] = 1;
	g[0] = 2;
	g[1] = 0;
	g[2] = 1;
	g[3] = 7;
	int Q;
	scanf("%d%d", &n, &Q);
	scanf("%s", s + 1);
	for(m=1; m<n; m*=2);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= 4; j++)
			for(int k = j; k <= 4; k++){
				if (k == j){
					tree[m+i-1][j][k] = f[j][k][s[i]-'0'];
				} else if (k == j + 1){
					tree[m+i-1][j][k] = (g[j] == s[i] - '0') ? 0 : n;
				} else tree[m+i-1][j][k] = n;
			}
	}
	for(int i = n + 1; i <= m; i++)
		for(int j = 0; j <= 4; j++)
			for(int k = j; k <= 4; k++)
				tree[m + i - 1][j][k] = n;
	for(int i = m - 1; i >= 1; i--){
		for(int j = 0; j <= 4; j++)
			for(int k = j; k <= 4; k++){
				tree[i][j][k] = n;
				for (int l = j; l <= k; l++){
					tree[i][j][k] = min(tree[i][j][k], tree[i<<1][j][l] + tree[(i<<1)|1][l][k]);
				}
			}
	}
	for(int i = 1; i <= Q; i++){
		int l,r;
		scanf("%d%d", &l, &r);
		query(1, 1, m, l, r);
		if (ans[0][4] >= n){
			puts("-1");
		}
		else
			printf("%d\n", ans[0][4]);
	}
}

void printans(){

}


int main(){
	int T = 1;
//	cin>>T;
	while(T--){
		read();
		solve();
		printans();
	}
	return 0;
}