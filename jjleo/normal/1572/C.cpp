#include <bits/stdc++.h>
#define maxn 3086

using namespace std;

int t, n;
int a[maxn];
vector<int> v[maxn];
int f[maxn][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int m = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]);
			if(a[m] ^ a[i]) a[++m] = a[i];
			v[i].clear();
		}
		n = m;
		for(int i = 1;i <= n;i++) v[a[i]].push_back(i);
		for(int len = 2;len <= n;len++){
			for(int i = 1;i + len - 1 <= n;i++){
				int j = i + len - 1;
				f[i][j] = min(f[i + 1][j], f[i][j - 1]) + (a[i] != a[j]);
				for(int k = 0;k < v[a[i]].size();k++){
					int x = v[a[i]][k];
					if(i < x && x < j) f[i][j] = min(f[i][j], f[i][x] + f[x + 1][j] + (a[i] != a[j]));
				}
				for(int k = 0;k < v[a[j]].size();k++){
					int x = v[a[j]][k];
					if(i < x && x < j) f[i][j] = min(f[i][j], f[i][x] + f[x + 1][j] + (a[i] != a[j]));
				}
			}
		}
		printf("%d\n", f[1][n]);
	}
}