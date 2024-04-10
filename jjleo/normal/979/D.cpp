#include <bits/stdc++.h>
#define maxn 100086
using namespace std;

int son[maxn << 8][2], val[maxn << 8];

int cnt = maxn;

void insert(int x, int y){
	for(int i = 1 << 20;i;i >>= 1){
		bool z = (y & i) != 0;
		if(!son[x][z]) son[x][z] = ++cnt, val[son[x][z]] = maxn;
		x = son[x][z], val[x] = min(val[x], y);
		//printf("%d %d %d--\n", x, i, val[x]);
	}
}

int query(int x, int y, int s){
	int ans = 0;
	for(int i = 1 << 20;i;i >>= 1){
		//printf("%d %d %d %d--\n", x, y, s, i);
		bool z = (y & i) != 0;
		if(val[son[x][z ^ 1]] <= s) x = son[x][z ^ 1], ans += (z ^ 1) * i;
		else if(val[son[x][z]] <= s) x = son[x][z], ans += z * i;
		else return -1;
	}
	return ans;
}

int n;
int opt, x, y, z;

int main(){
	scanf("%d", &n);
	val[0] = maxn;
	while(n--){
		scanf("%d", &opt);
		if(opt == 1){
			scanf("%d", &x);
			for(int i = 1;i * i <= x;i++){
				if(x % i) continue;
				insert(i, x);
				if(i * i != x) insert(x / i, x);
			}
		}else{
			scanf("%d%d%d", &x, &y, &z);
			if(x % y){
				puts("-1");
				continue;
			}
			printf("%d\n", query(y, x, z - x));
		}
	}
}