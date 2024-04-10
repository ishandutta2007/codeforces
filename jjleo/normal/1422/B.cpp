#include <bits/stdc++.h>
#define maxn 200

using namespace std;

int t;
int n, m;
long long ans;
int a[maxn][maxn];
bool vis[maxn][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		ans = 0;
		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) scanf("%d", &a[i][j]), vis[i][j] = false;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				if(vis[i][j]) continue;
				vis[i][j] = true;
				if(i == n - i + 1 && j == m - j + 1) continue;
				if(i == n - i + 1){
					vis[i][m - j + 1] = true;
					ans += abs(a[i][j] - a[i][m - j + 1]);
				}else if(j == m - j + 1){
					vis[n - i + 1][j] = true;
					ans += abs(a[n - i + 1][j] - a[i][j]);
				}else{
					vis[n - i + 1][j] = true;
					vis[i][m - j + 1] = true;
					vis[n - i + 1][m - j + 1] = true;
					vector<int> v;
					v.push_back(a[i][j]), v.push_back(a[i][m - j + 1]), v.push_back(a[n - i + 1][j]), v.push_back(a[n - i + 1][m - j + 1]);
					sort(v.begin(), v.end());
					for(int k = 0;k < v.size();k++) ans += abs(v[k] - v[1]);
				}
			}
		}
		printf("%lld\n", ans);
	}
}