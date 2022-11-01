#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n;
int x, y, z;
vector<int> v[maxn];
int f[maxn];
int siz[maxn];
bool del[maxn];

void dfs(int i, int fa){
	siz[i] = 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa || del[to]) continue;
		dfs(to, i);
		siz[i] += siz[to];
	}
	if(siz[i] == f[y - 1] || siz[i] == f[y - 2]) x = i, z = fa;
}

bool solve(int i, int m){
	if(m <= 1) return true;
	x = 0, y = m, dfs(i, 0);
	if(!x) return false;
	int X = x, Z = z;
	if(siz[X] == f[m - 1]){
		del[Z] = true;
		if(!solve(x, m - 1)) return false;
		del[Z] = false;
		del[X] = true;
		if(!solve(Z, m - 2)) return false;
		del[X] = false;
	}else{
		del[Z] = true;
		if(!solve(x, m - 2)) return false;
		del[Z] = false;
		del[X] = true;
		if(!solve(Z, m - 1)) return false;
		del[X] = false;
	}
	return true;
}


int main(){
	scanf("%d", &n);
	if(n == 1) return printf("YES"), 0;
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	f[0] = f[1] = 1;
	int m;
	for(int i = 2;;i++){
		f[i] = f[i - 1] + f[i - 2];
		if(f[i] >= n){
			m = i;
			break;
		}
	}
	if(f[m] ^ n) return printf("NO"), 0;
	printf(solve(1, m) ? "YES" : "NO");
	
}