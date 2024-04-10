#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
vector<int> v[maxn];
int a[maxn], f[maxn];

int t;

void dfs(int i, int fa){
	a[i] = a[fa] ^ 1;
	for(auto to : v[i]) if(to ^ fa) dfs(to, i);
}

int main(){
	srand(time(0));
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) v[i].clear();
		for(int i = 1;i < n;i++){
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
		}
		dfs(1, 0);
		for(int i = 1;i <= n;i++){
			f[i] = (int)v[i].size() * a[i];
			for(auto j : v[i]) f[i] -= a[j];
			if(f[i] == 0 || f[i] > 100000 || f[i] < -100000) assert(0);
		}
		for(int i = 1;i <= n;i++) printf("%d ", f[i]);puts("");
	}
}