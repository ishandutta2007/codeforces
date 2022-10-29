#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e3 + 10;
const int MAXM = 2e6 + 10;

int n, m;
char s[MAXM];
ll a[MAXN][MAXN];
int f[MAXN][MAXN];

void read(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			scanf("%lld", &a[i][j]);
	}
}

void solve(){
	if (n == 1){
		puts("1"); return ;
	}
	int x, y;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if (a[i][j] == 0){
				x = i, y = j;
				break;
			}
	int p;
	if (x == 1) p = 2;
	else p = 1;
	ll sum = 0;
	for(int i = 1; i <= n; i++)
		sum += a[p][i];
	ll ans, tot = 0;
	for(int i = 1; i <= n; i++)
		tot += a[x][i];
	ans = sum - tot;
	if (ans <= 0){
		puts("-1");return;
	}
	a[x][y] = ans;
	for(int i = 1; i <= n; i++){
		tot = 0;
		for(int j = 1; j <= n; j++)
			tot += a[i][j];
		if (tot != sum){
			puts("-1"); return;
		}
	}	
	for(int i = 1; i <= n; i++){
		tot = 0;
		for(int j = 1; j <= n; j++)
			tot += a[j][i];
		if (tot != sum){
			puts("-1"); return;
		}
	}	
	tot = 0;
	for(int i = 1; i <= n; i++)
		tot += a[i][i];
	if (tot != sum){
		puts("-1"); return ;
	}
	tot = 0;
	for(int i = 1; i <= n; i++)
		tot += a[i][n+1-i];
	if (tot != sum){
		puts("-1"); return ;
	}
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