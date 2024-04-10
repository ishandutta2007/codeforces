#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 100 + 10;
const int MAXM = 2e6 + 10;

int n, m, K;
char s[MAXM];
int a[MAXM];
int c[MAXN][MAXN];
ll f[MAXN][MAXN][MAXN];

void read(){
	scanf("%d%d%d", &n, &m, &K);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)
			scanf("%d", &c[i][j]);
	}
}

const ll INF = 1ll << 60;

void upd(ll & x, ll y){
	x = min(x, y);
}

void solve(){
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++)
			for(int k = 0; k <= K; k++)
				f[i][j][k] = INF;
	f[0][0][0] = 0;
	for(int i = 0; i < n; i++){
		if (a[i+1] == 0){
			for(int j = 0; j <= m; j++)
				for(int k = 0; k <= K; k++)
					if (f[i][j][k] < INF){
					//	cout<<i<<' '<<j<<' '<<k<<' '<<f[i][j][k]<<endl;
						for(int l = 1; l <= m; l++)
							upd(f[i+1][l][k+(j!=l)], f[i][j][k] + c[i+1][l]);
						}
		}
		else{
			for(int j = 0; j <= m; j++)
				for(int k = 0; k <= K; k++)
					if (f[i][j][k] < INF){
						upd(f[i+1][a[i+1]][k + (j != a[i+1])], f[i][j][k]);
					}
		}
	}
	ll ans = INF;
	for(int j = 0; j <= m; j++)
		upd(ans, f[n][j][K]);
	if (ans == INF)
		puts("-1");
	else
		cout<<ans<<endl;
}

void printans(){

}
	

int main(){
	int T = 1;
//	cin >> T;
	while(T--){
		read();
		solve();
		printans();
	}
	return 0;
}