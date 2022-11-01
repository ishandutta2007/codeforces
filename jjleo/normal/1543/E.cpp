#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
vector<int> v[maxn], w[maxn];
int x, y;
int a[maxn], p[maxn], d[maxn];
queue<int> q;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0;i < (1 << n);i++) v[i].clear(), w[i].clear(), d[i] = 1e9;
		for(int i = 0;i < (n << (n - 1));i++){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
		}
		a[0] = d[0] = 0;
		for(int i = 0;i < v[0].size();i++) a[v[0][i]] = 1 << i, d[v[0][i]] = 1, q.push(v[0][i]);
		while(!q.empty()){
			int x = q.front();q.pop();
			if(d[x] > 1) a[x] = w[x][0] | w[x][1];
			for(int i = 0;i < v[x].size();i++){
				int to = v[x][i];
				if(d[to] > d[x] + 1) d[to] = d[x] + 1, q.push(to);
				if(d[to] == d[x] + 1) w[to].push_back(a[x]);
			}
		}
		for(int i = 0;i < (1 << n);i++) p[a[i]] = i;
		for(int i = 0;i < (1 << n);i++) printf("%d ", p[i]);puts("");
		if(!(n == 1 || n == 2 || n == 4 || n == 8 || n == 16)){
			puts("-1");
			continue;
		}
		for(int i = 0;i < (1 << n);i++){
			int ans = 0;
			for(int j = 0;j < n;j++) if(a[i] & (1 << j)) ans ^= j;
			printf("%d ", ans);
		}
		puts("");
	}
}