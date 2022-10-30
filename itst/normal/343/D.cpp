#include<bits/stdc++.h>
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

const int MAXN = 500010;
struct Edge{
	int end , upEd;
}Ed[MAXN << 1];
int head[MAXN] , mark[MAXN << 2] , fa[MAXN] , size[MAXN] , son[MAXN] , top[MAXN] , ind[MAXN] , N , cntEd , ts;

inline void addEd(int a , int b){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	head[a] = cntEd;
}

void dfs1(int now){
	size[now] = 1;
	for(int i = head[now] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != fa[now]){
			fa[Ed[i].end] = now;
			dfs1(Ed[i].end);
			size[now] += size[Ed[i].end];
			if(size[Ed[i].end] > size[son[now]])
				son[now] = Ed[i].end;
		}
}

void dfs2(int now , int t){
	top[now] = t;
	ind[now] = ++ts;
	if(!son[now])
		return;
	dfs2(son[now] , t);
	for(int i = head[now] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != fa[now] && Ed[i].end != son[now])
			dfs2(Ed[i].end , Ed[i].end);
}

void pushup(int dir){
	mark[dir] = mark[dir << 1] == mark[dir << 1 | 1] ? mark[dir << 1] : -1;
}

void pushdown(int dir){
	if(mark[dir] != -1)
		mark[dir << 1] = mark[dir << 1 | 1] = mark[dir];
}

void m(int now , int l , int r , int L , int R , int mm){
	if(l >= L && r <= R){
		mark[now] = mm;
		return;
	}
	if(mark[now] == mm)
		return;
	pushdown(now);
	if(l + r >> 1 >= L)
		m(now << 1 , l , l + r >> 1 , L , R , mm);
	if(l + r >> 1 < R)
		m(now << 1 | 1 , (l + r >> 1) + 1 , r , L , R , mm);
	pushup(now);
}

void empty(int q){
	int tq = top[q];
	while(q){
		m(1 , 1 , N , ind[tq] , ind[q] , 0);
		q = fa[tq];
		tq = top[q];
	}
}

bool Query(int now , int l , int r , int tar){
	if(mark[now] + 1)
		return mark[now];
	if(l + r >> 1 >= tar)
		return Query(now << 1 , l , l + r >> 1 , tar);
	return Query(now << 1 | 1 , (l + r >> 1) + 1 , r , tar);
}

int main(){
	N = read();
	for(int i = 1 ; i < N ; i++){
		int a = read() , b = read();
		addEd(a , b);
		addEd(b , a);
	}
	dfs1(1);
	dfs2(1 , 1);
	for(int Q = read() ; Q ; Q--){
		int a = read() , b = read();
		if(a == 1)
			m(1 , 1 , N , ind[b] , ind[b] + size[b] - 1 , 1);
		else
			if(a == 2)
				empty(b);
			else{
				putchar(Query(1 , 1 , N , ind[b]) + 48);
				putchar('\n');
			}
	}
	return 0;
}