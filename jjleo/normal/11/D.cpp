#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<int> v[19];
int x, y;
ll ans, f[1 << 19][19];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= m;i++){
		scanf("%d%d", &x, &y), --x, --y;
		v[x].push_back(y), v[y].push_back(x); 
	}
	int sup = 1 << n;
	for(int i = 1, j = 0;j < n;i <<= 1, j++) f[i][j] = 1;
	for(int i = 1;i < sup;i++){
		for(int j = 0;j < n;j++){
			if(!f[i][j]) continue;
			for(int k = 0;k < v[j].size();k++){
				int to = v[j][k];
				x = 1 << to;
				if((i & -i) > x) continue;
				if(i & x){
					if((i & -i) == x){
						ans += f[i][j];
					}
				}else{
					f[i | x][to] += f[i][j];
				}
			}
		}
	}
	printf("%lld", (ans - m) >> 1);
	
}