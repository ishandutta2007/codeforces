#include <bits/stdc++.h>
#define maxn 1086

using namespace std;

int t;
int m, k;
vector<int> v[maxn * maxn];
int a[maxn][maxn];
int x;
vector<pair<int, int> > w;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &m, &k);
		int mx = 0;
		for(int i = 1;i <= k;i++) scanf("%d", &x), v[x].push_back(i), mx = max(mx, x);
		int n = 1;
		while(m > n * n - n / 2 * (n / 2) || mx > n * ((n + 1) / 2)) n++;
		w.clear();
		for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) if(!(i & 1) && (j & 1)) w.push_back({i, j});
		for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) if((i & 1) && (j & 1)) w.push_back({i, j});
		for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) if((i & 1) && !(j & 1)) w.push_back({i, j});
		for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) a[i][j] = 0;
		x = -1;
		for(int i = mx;~i;i--){
			while(!v[i].empty()){
				for(int j = 1;j <= i;j++) x++, a[w[x].first][w[x].second] = v[i].back();
				v[i].pop_back();
			}
		}
		printf("%d\n", n);
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++) printf("%d ", a[i][j]);
			puts("");
		}
	}
}