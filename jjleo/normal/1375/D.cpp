#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn], cnt[maxn];
bool vis[maxn];
vector<int> ans;

int mex(){
	for(int i = 0;i <= n;i++) cnt[i] = 0;
	for(int i = 1;i <= n;i++) cnt[a[i]]++;
	for(int i = 0;;i++) if(!cnt[i]) return i;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		//for(int i = 0;i <= n;i++) vis[i] = false;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		ans.clear();
		for(int i = 1;i <= n;i++){
			int x = mex();
			if(x == n) break;
			a[x + 1] = x, ans.push_back(x + 1);
		}
		//for(int i = 1;i <= n;i++) if(a[i] == n) a[i] = mex(), ans.push_back(i);
		//for(int i = 1;i <= n;i++) printf("%d ", a[i]);puts("---");
		for(int i = 1;i <= n;i++) vis[i] = false;
		//int f = 0;
		for(int i = 1;i <= n;i++){
			if(vis[i] || a[i] + 1 == i) continue;
			//if(!f) f = i;
			int x = i;
			while(!vis[x]){
				vis[x] = true;
				ans.push_back(x);
				x = a[x] + 1;
			}
			ans.push_back(i);
		}
		//ans.push_back(f);
		printf("%d\n", ans.size());
		for(int i = 0;i < ans.size();i++) printf("%d ", ans[i]);puts("");
		/*
		for(int i = 1;i <= n;i++) if(a[i] == 0) ans.push_back(i), a[i] = mex();
		for(int i = 1;i <= n;i++){
			int x = mex();
			if(x == i - 1){
				ans.push_back(i), a[i] = x;
				continue;
			}
			int I;
			for(int j = i;j <= n;j++){
				if(a[j] == i - 1){
					I = j;
					break;
				}
			}
			for(int j = i;j <= n;j++) 
		}
		printf("%d\n", ans.size());
		for(int i = 0;i < ans.size();i++) printf("%d ", ans[i]);puts("");
		
		for(int i = 1;i <= n;i++){
			if(a[i] == i - 1) continue;
			for(int j = i + 1;j <= n;j++) if(a[j] == i - 1) a[j] = mex(), ans.push_back(j);
			a[i] = i - 1, ans.push_back(i);
		}
		*/
	}
}