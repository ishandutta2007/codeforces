#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

typedef long long ll;

const int p = 998244353;

vector<int> v[maxn];
ll f[maxn][3];

void dfs(int i, int fa){
	f[i][0] = f[i][1] = f[i][2] = 1;
	for(register int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dfs(to, i);
		f[i][0] = f[i][0] * (2 * f[to][0] + 2 * f[to][1] - f[to][2]) % p;
		f[i][1] = f[i][1] * (2 * f[to][0] + f[to][1] - f[to][2]) % p;
		f[i][2] = f[i][2] * (f[to][0] + f[to][1] - f[to][2]) % p;
	}
}

int n;
int x, y;

int main(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	dfs(1, 0);
	printf("%lld", (f[1][0] + f[1][1] + p - f[1][2] + p - 1) % p);
}