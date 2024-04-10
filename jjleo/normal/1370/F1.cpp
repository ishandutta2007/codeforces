#include <bits/stdc++.h>
#define maxn 1086

using namespace std;

int t;
int n;
int x, y, a, b;
vector<int> v[maxn];
vector<int> d[maxn];
int dep[maxn];
char s[maxn];

void dfs(int i, int fa){
	d[dep[i] = dep[fa] + 1].push_back(i);
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to ^ fa) dfs(to, i);
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) v[i].clear(), d[i].clear();
		for(int i = 1;i < n;i++){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
		}
		dfs(1, 0);
		printf("? %d", n);
		for(int i = 1;i <= n;i++) printf(" %d", i);
		puts(""), fflush(stdout);
		scanf("%d%d", &a, &b);
		for(int i = 1;i <= n;i++) d[i].clear();
		dfs(a, 0);
		int l = (b + 1) / 2, r = min(n, b + 1), mid;
		while(l < r){
			mid = (l + r >> 1) + 1;
			int sum = 0;
			for(int i = n;i >= mid;i--) sum += d[i].size();
			if(!sum){
				r = mid - 1;
				continue; 
			} 
			printf("? %d", sum);
			for(int i = n;i >= mid;i--) for(int j = 0;j < d[i].size();j++) printf(" %d", d[i][j]);
			puts(""), fflush(stdout);
			scanf("%d%d", &x, &y);
			if(y == b) l = mid;
			else r = mid - 1;
			if(y == b && dep[x] > dep[a]) a = x;
		}
		for(int i = 1;i <= n;i++) d[i].clear();
		dfs(a, 0);
		printf("? %d", d[b + 1].size());
		for(int i = 0;i < d[b + 1].size();i++) printf(" %d", d[b + 1][i]);
		puts(""), fflush(stdout);
		scanf("%d%d", &x, &y);
		printf("! %d %d", a, x);
		puts(""), fflush(stdout);
		scanf("%s", s);
		if(s[0] == 'I') return 0;
	}
}