#include <bits/stdc++.h>
#define maxn 205

using namespace std;

int t;
int n;
bool a[maxn][maxn];
int b[maxn];
set<int> st[maxn];
int x, y;
vector<int> ans; 


int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i < n;i++) for(int j = 1;j <= n;j++) a[i][j] = false;
		for(int i = 1;i < n;i++){
			scanf("%d", &y);
			while(y--){
				scanf("%d", &x);
				a[i][x] = true;
			}
		}
		for(int i = 1;i <= n;i++){
			bool suc = true;
			ans.clear();
			for(int j = 1;j < n;j++){
				st[j].clear(), b[j] = 0;
				for(int k = 1;k <= n;k++){
					if(a[j][k]) st[j].insert(k);
				}
			}
			x = i;
			for(int j = 1;j <= n;j++){
				ans.push_back(x);
				for(int k = 1;k < n;k++){
					if(!a[k][x]) continue;
					if(b[k] == 0 || b[k] == j - 1) b[k] = j, st[k].erase(x);
					else{
						suc = false;
						break;
					}
				}
				if(!suc || j == n) break;
				x = 0;
				for(int k = 1;k < n;k++){
					if(st[k].size() == 1 && (b[k] == 0 || b[k] == j)){
						//printf("%d %d %d--\n", i, j, k);
						x = *st[k].begin();
						break;
					}
				}
				if(!x){
					suc = false;
					break;
				}
			}
			if(suc) break;
		}
		for(int i = 0;i < ans.size();i++) printf("%d ", ans[i]);
		puts("");
	}
}