#include <bits/stdc++.h>
#define maxn 405

using namespace std;

const int p = 998244353;

int n, m;
vector<int> v[maxn]; 
int x, y;
int a[maxn][maxn];
int d[maxn][maxn];
queue<int> q;
int f[maxn];

int main(){
	scanf("%d%d", &n, &m);
	while(m--){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	memset(d, 0x3f, sizeof(d));
	for(int i = 1;i <= n;i++){
		d[i][i] = 0, q.push(i);
		while(!q.empty()){
			int x = q.front();q.pop();
			for(int j = 0;j < v[x].size();j++){
				int to = v[x][j];
				if(d[i][to] > d[i][x] + 1){
					d[i][to] = d[i][x] + 1;
					q.push(to);
				}
			} 
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			int sum = 0;
			for(int k = 1;k <= n;k++){
				sum += d[i][k] + d[j][k] == d[i][j];
			}
			if(sum > d[i][j] + 1) continue;
			a[i][j] = 1;
			memset(f, 0, sizeof(f));
			for(int k = 1;k <= n;k++){
				for(int l = 0;l < v[k].size();l++){
					int to = v[k][l];
					if(d[i][to] + d[j][to] == d[i][j]) continue;
					if(d[i][to] == d[i][k] + 1 && d[j][to] == d[j][k] + 1) f[to]++;
				}
			}
			for(int k = 1;k <= n;k++){
				if(d[i][k] + d[j][k] == d[i][j]) continue;
				a[i][j] = 1ll * a[i][j] * f[k] % p;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++) printf("%d ", a[i][j]);
		puts("");
	}
}