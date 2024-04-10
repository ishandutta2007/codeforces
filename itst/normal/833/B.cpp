#include<bits/stdc++.h>
#define MAXN 35001
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar(); 
	}
	return a;
}

struct node{
	int add , maxN;
}Tree[MAXN << 2];
int ans[MAXN][51] , f[MAXN] , lasApp[MAXN] , pot[MAXN];

inline void pushup(int dir){
	Tree[dir].maxN = max(Tree[dir << 1].maxN , Tree[dir << 1 | 1].maxN);
}

inline void pushdown(int dir){
	if(Tree[dir].add){
		Tree[dir << 1].add += Tree[dir].add;
		Tree[dir << 1 | 1].add += Tree[dir].add;
		Tree[dir << 1].maxN += Tree[dir].add;
		Tree[dir << 1 | 1].maxN += Tree[dir].add;
		Tree[dir].add = 0;
	}
}

void add(int l , int r , int L , int R , int now , int dir){
	if(l >= L && r <= R){
		Tree[now].add += dir;
		Tree[now].maxN += dir;
		return;
	}
	pushdown(now);
	if(l + r >> 1 >= L)
		add(l , l + r >> 1 , L , R , now << 1 , dir);
	if(l + r >> 1 < R)
		add((l + r >> 1) + 1 , r , L , R , now << 1 | 1 , dir);
	pushup(now);
}

inline int getMax(int l , int r , int L , int R , int now){
	if(l >= L && r <= R)
		return Tree[now].maxN;
	pushdown(now);
	int maxN = 0;
	if(l + r >> 1 >= L)
		maxN = max(maxN , getMax(l , l + r >> 1 , L , R , now << 1));
	if(l + r >> 1 < R)
		maxN = max(maxN , getMax((l + r >> 1) + 1 , r , L , R , now << 1 | 1));
	return maxN;
}

int main(){
	int N = read() , k = read();
	for(int i = 1 ; i <= N ; i++)
		f[i] = read();
	for(int i = 1 ; i <= k ; i++){
		memset(&Tree , 0 , sizeof(Tree));
		memset(pot , 0 , sizeof(pot));
		for(int j = i ; j <= N ; j++){
			add(1 , N , j , j , 1 , ans[j - 1][i - 1]);
			add(1 , N , pot[f[j]] + 1 , j , 1 , 1);
			ans[j][i] = getMax(1 , N , i , j , 1);
			pot[f[j]] = j;
		}
	}
	cout << ans[N][k];
	return 0;
}