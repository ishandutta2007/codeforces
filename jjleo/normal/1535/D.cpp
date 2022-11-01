#include <bits/stdc++.h>
#define maxn 1100086

using namespace std;

int n, q, x;
char s[maxn];
int siz[maxn];
vector<int> v[maxn];
int id[maxn], Id[maxn];
char c[maxn];

void Dfs(int i, int dep){
	v[dep].push_back(i);
	if(dep == n) return;
	Dfs(i << 1, dep + 1), Dfs(i << 1 | 1, dep + 1);
}

void dfs(int i){
	if(i >= (1 << n)){
		siz[i] = 1;
		return;
	}
	dfs(i << 1), dfs(i << 1 | 1);
	if(s[id[i]] == '0' || s[id[i]] == '?') siz[i] += siz[i << 1];
	if(s[id[i]] == '1' || s[id[i]] == '?') siz[i] += siz[i << 1 | 1];
}

int main(){
	scanf("%d%s", &n, s + 1);
	Dfs(1, 1);
	int cnt = 0;
	for(int i = n;i;i--) for(int j = 0;j < v[i].size();j++) Id[id[v[i][j]] = ++cnt] = v[i][j]; 
	dfs(1);
	scanf("%d", &q);
	while(q--){
		scanf("%d%s", &x, c);
		int y = Id[x];
		if(s[x] == '0' || s[x] == '?'){
			siz[y] -= siz[y << 1];
			for(int i = y;i > 1;i >>= 1){
				if(s[id[i >> 1]] - '0' == !(i & 1)) break;
				siz[i >> 1] -= siz[y << 1];
			}
		}
		if(s[x] == '1' || s[x] == '?'){
			siz[y] -= siz[y << 1 | 1];
			for(int i = y;i > 1;i >>= 1){
				if(s[id[i >> 1]] - '0' == !(i & 1)) break;
				siz[i >> 1] -= siz[y << 1 | 1];
			}
		}
		s[x] = c[0];
		if(s[x] == '0' || s[x] == '?'){
			siz[y] += siz[y << 1];
			for(int i = y;i > 1;i >>= 1){
				if(s[id[i >> 1]] - '0' == !(i & 1)) break;
				siz[i >> 1] += siz[y << 1];
			}
		}
		if(s[x] == '1' || s[x] == '?'){
			siz[y] += siz[y << 1 | 1];
			for(int i = y;i > 1;i >>= 1){
				if(s[id[i >> 1]] - '0' == !(i & 1)) break;
				siz[i >> 1] += siz[y << 1 | 1];
			}
		}
		printf("%d\n", siz[1]);
	}
}