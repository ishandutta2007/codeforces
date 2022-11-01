#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int a[maxn][3];

int t;
int n;

set<int> st[maxn];
set<int> v[maxn];
int num[maxn];
queue<int> q;
int Q[maxn], cnt;
bool vis[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n), cnt = 0;
		for(int i = 1;i <= n;i++){
			vis[i] = false, v[i].clear();
		}
		for(int i = 1;i <= n - 2;i++){
			for(int j = 0;j < 3;j++){
				scanf("%d", &a[i][j]);
				st[a[i][j]].insert(i);
				num[a[i][j]]++;
			} 
			for(int j = 0;j < 3;j++){
				for(int k = 0;k < 3;k++){
					if(j == k) continue;
					int x = a[i][j], y = a[i][k];
					if(v[x].find(y) == v[x].end()) v[x].insert(y);
					else v[x].erase(y);
				}
			}
		}
		for(int i = 1;i <= n;i++){
			if(num[i] == 1) q.push(i);
		}
		while(!q.empty()){
			int x = q.front();
			q.pop();
			if(st[x].begin() == st[x].end()) continue;
			int i = *(st[x].begin());
			Q[++cnt] = i;
			for(int j = 0;j < 3;j++){
				st[a[i][j]].erase(i);
				num[a[i][j]]--;
				if(num[a[i][j]] == 1) q.push(a[i][j]);
			} 
		}
		int x = 1;
		for(int i = 1;i <= n;i++){
			vis[x] = true;
			printf("%d ", x);
			if(vis[*(v[x].begin())]) x = *(next(v[x].begin()));
			else x = *(v[x].begin());
		}
		puts("");
		for(int i = 1;i <= n - 2;i++) printf("%d ", Q[i]);
		puts("");
	}
}