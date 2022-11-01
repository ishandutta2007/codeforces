#include<bits/stdc++.h>
#define lch (x << 1)
#define rch (x << 1 | 1)
#define mid ((l + r) >> 1)
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	bool f = 0;
	char c = getchar();
	while(c != EOF && !isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(c != EOF && isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 100010;
struct node{
	int l , r , mark , num;
}Tree[MAXN << 2];
int N , M , num[MAXN][3];

inline void mark(int x , int num){
	Tree[x].mark |= num;
	Tree[x].num |= num;
}

inline void pushdown(int x){
	if(Tree[x].mark){
		mark(lch , Tree[x].mark);
		mark(rch , Tree[x].mark);
		Tree[x].mark = 0;
	}
}

inline void pushup(int x){
	Tree[x].num = Tree[lch].num & Tree[rch].num;
}

void modify(int x , int l , int r , int L , int R , int num){
	if(l >= L && r <= R){
		mark(x , num);
		return;
	}
	pushdown(x);
	if(mid >= L)
		modify(lch , l , mid , L , R , num);
	if(mid < R)
		modify(rch , mid + 1 , r , L , R , num);
	pushup(x);
}

int query(int x , int l , int r , int L , int R){
	if(l >= L && r <= R)
		return Tree[x].num;
	pushdown(x);
	int now = (1 << 30) - 1;
	if(mid >= L)
		now &= query(lch , l , mid , L , R);
	if(mid < R)
		now &= query(rch , mid + 1 , r , L , R);
	return now;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("482B.in" , "r" , stdin);
	//freopen("482B.out" , "w" , stdout);
#endif
	N = read();
	M = read();
	for(int i = 1 ; i <= M ; ++i){
		num[i][0] = read();
		num[i][1] = read();
		num[i][2] = read();
		modify(1 , 1 , N , num[i][0] , num[i][1] , num[i][2]);
	}
	for(int i = 1 ; i <= M ; ++i)
		if(query(1 , 1 , N , num[i][0] , num[i][1]) != num[i][2]){
			puts("NO");
			return 0;
		}
	puts("YES");
	for(int i = 1 ; i <= N ; ++i)
		printf("%d " , query(1 , 1 , N , i , i));
	return 0;
}