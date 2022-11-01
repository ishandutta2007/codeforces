#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
vector<int> v[maxn]; 
int deg[maxn];
int x, y, z;

queue<int> q;

int main(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		++deg[x], ++deg[y];
		v[x].push_back(y), v[y].push_back(x);
	}
	for(int i = 1;i <= n;i++) if(deg[i] == 1) q.push(i); 
	while(1){
		x = q.front();q.pop();
		if(q.empty()) return printf("! %d", x), 0;
		y = q.front();q.pop();
		printf("? %d %d\n", x, y), fflush(stdout);
		scanf("%d", &z);
		if(x == z || y == z) return printf("! %d", z), 0;
		deg[x] = deg[y] = 0;
		for(int i = 0;i < v[x].size();i++){
			if(deg[v[x][i]]){
				--deg[v[x][i]];
				if(deg[v[x][i]] == 1) q.push(v[x][i]);
			}
		}
		for(int i = 0;i < v[y].size();i++){
			if(deg[v[y][i]]){
				--deg[v[y][i]];
				if(deg[v[y][i]] == 1) q.push(v[y][i]);
			}
		}//
	}
}