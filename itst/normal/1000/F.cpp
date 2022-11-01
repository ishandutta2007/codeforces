#include<bits/stdc++.h>
#define INF 0x7fffffff
#define mid ((l + r) >> 1)
#define P pair < int , int >
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 5e5 + 10;
struct node{
	int l , r , minN , minInd;
}Tree[MAXN * 50];
int root[MAXN] , num[MAXN] , pre[MAXN] , N , cntNode;

inline void pushup(int x){
	if(Tree[Tree[x].l].minN < Tree[Tree[x].r].minN){
		Tree[x].minN = Tree[Tree[x].l].minN;
		Tree[x].minInd = Tree[Tree[x].l].minInd;
	}
	else{
		Tree[x].minN = Tree[Tree[x].r].minN;
		Tree[x].minInd = Tree[Tree[x].r].minInd;
	}
}

void insert(int& x , int l , int r , int tar , int num){
	int p = ++cntNode;
	Tree[p] = Tree[x];
	x = p;
	if(l == r){
		Tree[x].minN = num;
		Tree[x].minInd = l;
	}
	else{
		if(mid >= tar)
			insert(Tree[x].l , l , mid , tar , num);
		else
			insert(Tree[x].r , mid + 1 , r , tar , num);
		pushup(x);
	}
}

P query(int x , int l , int r , int L , int R){
	if(!x)
		return P(INF , 0);
	if(l >= L && r <= R)
		return P(Tree[x].minN , Tree[x].minInd);
	P minN(INF , 0);
	if(mid < R)
		minN = min(minN , query(Tree[x].r , mid + 1 , r , L , R));
	if(mid >= L)
		minN = min(minN , query(Tree[x].l , l , mid , L , R));
	return minN;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	N = read();
	Tree[0].minN = INF;
	for(int i = 1 ; i <= N ; ++i){
		root[i] = root[i - 1];
		num[i] = read();
		if(pre[num[i]])
			insert(root[i] , 1 , N , pre[num[i]] , INF);
		insert(root[i] , 1 , N , i , pre[num[i]]);
		pre[num[i]] = i;
	}
	for(int M = read() ; M ; --M){
		int a = read() , b = read();
		P ans = query(root[b] , 1 , N , a , b);
		printf("%d\n" , ans.first < a ? num[ans.second] : 0);
	}
	return 0;
}