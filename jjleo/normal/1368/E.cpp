#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n, m;
vector<int> v[maxn];
int a[maxn], ans;
int x, y;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) v[i].clear(), a[i] = 0;
		while(m--){
			scanf("%d%d", &x, &y);
			v[y].push_back(x);
		}
		/*for(int i = 1;i <= n;i++){
			if(!v[i].size()) a[i] = 1;
		}
		for(int i = 1;i <= n;i++){
			if(a[i]) continue;
			bool tag = false;
			for(int j = 0;j < v[i].size();j++){
				if(a[v[i][j]] == 1) tag = true;
				else if(a[v[i][j]] == 2){
					tag = false;
					break;
				}
			}
			if(tag) a[i] = 2;
		}
		ans = 0;
		for(int i = 1;i <= n;i++){
			if(a[i]) continue;
			bool tag = false;
			for(int j = 0;j < v[i].size();j++){
				if(a[v[i][j]] == 2){
					tag = true;
					break;
				}
			}
			if(tag) a[i] = 3, ans++;
		}*/
		for(int i = 1;i <= n;i++){
			for(int j = 0;j < v[i].size();j++){
				if(a[v[i][j]] == 1) a[i] = 2;
				if(a[i] != 2 && a[v[i][j]] == 0) a[i] = 1;
			}
		}
		ans = 0;
		for(int i = 1;i <= n;i++) if(a[i] == 2) ans++;
		printf("%d\n", ans);
		for(int i = 1;i <= n;i++) if(a[i] == 2) printf("%d ", i);
		puts("");
	}
}