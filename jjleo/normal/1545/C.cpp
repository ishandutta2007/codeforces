#include <bits/stdc++.h>
#define maxn 1086

using namespace std;

const int p = 998244353;

int t, n;
int a[maxn][maxn];
bool vis[maxn];
int b[maxn];
vector<int> v;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n * 2;i++){
			for(int j = 1;j <= n;j++) scanf("%d", &a[i][j]);
			vis[i] = false;
		}
		v.clear();
		int ans = 1;
		while(v.size() < n){
			int id = 0;
			for(int j = 1;j <= n;j++){
				for(int i = 1;i <= n;i++) b[i] = 0;
				for(int i = 1;i <= n * 2;i++){
					if(vis[i]) continue;
					if(b[a[i][j]]) b[a[i][j]] = -1;
					else b[a[i][j]] = i;
				}
				for(int i = 1;i <= n;i++){
					if(b[i] > 0){
						id = b[i];
						break;
					}
				}
				if(id) break;
			} 
			if(!id){
				ans = (ans + ans) % p;
				for(int i = 1;i <= n * 2;i++){
					if(!vis[i]){
						id = i;
						break;
					}
				}
			}
			v.push_back(id);
			for(int i = 1;i <= n * 2;i++){
				if(vis[i]) continue;
				for(int j = 1;j <= n;j++){
					if(a[i][j] == a[id][j]){
						vis[i] = true;
						break;
					}
				}
		 	}
		}
		printf("%d\n", ans);
		for(int i = 0;i < v.size();i++) printf("%d ", v[i]);puts("");
	}
}