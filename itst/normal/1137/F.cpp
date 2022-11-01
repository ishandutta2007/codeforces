#include<iostream>
#include<cstdio>
#include<queue>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}

const int MAXN = 2e5 + 3;
int N , Q , cntCol;

namespace BIT{
	int BIT[MAXN << 1];

#define lowbit(x) ((x) & -(x))
	void add(int x , int num){
		while(x <= N + Q){
			BIT[x] += num;
			x += lowbit(x);
		}
	}

	int get(int x){
		int sum = 0;
		while(x){
			sum += BIT[x];
			x -= lowbit(x);
		}
		return sum;
	}
}
using BIT::add; using BIT::get;

namespace LCT{
	struct node{
		int ch[2] , fa , col , sz;
		bool mrk;
	}Tree[MAXN];
	
	bool nroot(int x){
		return Tree[Tree[x].fa].ch[0] == x || Tree[Tree[x].fa].ch[1] == x;
	}

	bool son(int x){
		return Tree[Tree[x].fa].ch[1] == x;
	}

	void pushup(int x){
		Tree[x].sz = Tree[Tree[x].ch[0]].sz + Tree[Tree[x].ch[1]].sz + 1;
	}
	
	void rot(int x){
		bool f = son(x);
		int y = Tree[x].fa , z = Tree[y].fa , w = Tree[x].ch[f ^ 1];
		Tree[x].fa = z;
		if(nroot(y)) Tree[z].ch[son(y)] = x;
		Tree[y].fa = x; Tree[x].ch[f ^ 1] = y;
		Tree[y].ch[f] = w; if(w) Tree[w].fa = y;
		pushup(y);
	}

	void mark(int x , bool f , int col){
		if(!x) return;
		Tree[x].col = col;
		if(f){
			swap(Tree[x].ch[0] , Tree[x].ch[1]);
			Tree[x].mrk ^= 1;
		}
	}
	
	void pushdown(int x){
		mark(Tree[x].ch[0] , Tree[x].mrk , Tree[x].col);
		mark(Tree[x].ch[1] , Tree[x].mrk , Tree[x].col);
		Tree[x].mrk = 0;
	}

	void down_all(int x){
		if(nroot(x)) down_all(Tree[x].fa);
		pushdown(x);
	}
	
	void splay(int x){
		down_all(x);
		while(nroot(x)){
			if(nroot(Tree[x].fa))
				rot(son(x) == son(Tree[x].fa) ? Tree[x].fa : x);
			rot(x);
		}
		pushup(x);
	}
	
	void access(int x){
		for(int y = 0 ; x ; y = x , x = Tree[x].fa){
			splay(x);
			add(Tree[x].col , -(Tree[Tree[x].ch[0]].sz + 1));
			Tree[x].ch[1] = y;
			pushup(x);
		}
	}
	
	void makeroot(int x){
		access(x); splay(x);
		mark(x , 1 , ++cntCol); add(cntCol , Tree[x].sz);
	}

	int query(int x){
		splay(x);
		return get(Tree[x].col - 1) + Tree[Tree[x].ch[1]].sz + 1;
	}
}
using LCT::makeroot; using LCT::query;

namespace Tree{
	struct Edge{
		int end , upEd;
	}Ed[MAXN << 1];
	int head[MAXN] , in[MAXN] , cntEd;

	inline void addEd(int a , int b){
		Ed[++cntEd].end = b;
		Ed[cntEd].upEd = head[a];
		head[a] = cntEd;
		++in[a];
	}

	void init(){
		for(int i = 1 ; i < N ; ++i){
			int a = read() , b = read();
			addEd(a , b); addEd(b , a);
		}
		priority_queue < int , vector < int > , greater < int > > q;
		for(int i = 1 ; i <= N ; ++i)
			if(in[i] == 1) q.push(i);
		while(!q.empty()){
			int t = q.top(); q.pop();
			add(LCT::Tree[t].col = ++cntCol , 1);
			for(int i = head[t] ; i ; i = Ed[i].upEd){
				if(--in[Ed[i].end] == 1)
					q.push(Ed[i].end);
				if(in[Ed[i].end] >= 1 || Ed[i].end == N)
					LCT::Tree[t].fa = Ed[i].end;
			}
		}
	}
}

inline char getc(){
	char c = getchar();
	while(!islower(c)) c = getchar();
	return c;
}
	
int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
#endif
	N = read(); Q = read(); Tree::init();
	int a , b;
	for(int i = 1 ; i <= Q ; ++i)
		switch(getc()){
		case 'u': makeroot(read()); break;
		case 'w': printf("%d\n" , query(read())); break;
		case 'c':
			a = read(); b = read();
			printf("%d\n" , query(a) > query(b) ? b : a);
			break;
		}
	return 0;
}