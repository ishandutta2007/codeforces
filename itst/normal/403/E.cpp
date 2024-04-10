#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c) && c != EOF){f = c == '-'; c = getchar();}
	if(c == EOF) exit(0);
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

const int _ = 2e5 + 3;
#define PII pair < int , int >
struct Edge{int end , upEd;}Ed[_ * 120];
int head[_ * 20] , cntEd , dis[_ * 20] , N; bool ised[_ * 20];
vector < int > ans[_ * 2];

void addEd(int a , int b){
	Ed[++cntEd] = (Edge){b , head[a]};
	head[a] = cntEd;
}

namespace segtree{
	int lch[_ * 20] , rch[_ * 20] , cnt;

#define mid ((l + r) >> 1)
	
	void init(int &x , int l , int r){
		x = ++cnt;
		if(l == r) return;
		init(lch[x] , l , mid); init(rch[x] , mid + 1 , r);
		addEd(lch[x] , x); addEd(rch[x] , x);
	}

	void add(int x , int l , int r , int L , int R , int id){
		if(l >= L && r <= R) return addEd(x , id);
		if(mid >= L) add(lch[x] , l , mid , L , R , id);
		if(mid < R) add(rch[x] , mid + 1 , r , L , R , id);
	}

	int qid(int x , int l , int r , int tar){
		if(l == r) return x;
		return mid >= tar ? qid(lch[x] , l , mid , tar) : qid(rch[x] , mid + 1 , r , tar);
	}
}

struct Tree{
	vector < PII > ed;
	Edge ned[_ << 1]; int hd[_] , cnted;
	int ts[_] , rt[_] , top[_] , dep[_] , fa[_] , sz[_] , son[_] , down[_];

	void added(int a , int b){
		ned[++cnted] = (Edge){b , hd[a]};
		hd[a] = cnted;
	}

	void dfs1(int x , int p){
		fa[x] = p; dep[x] = dep[p] + 1; sz[x] = 1;
		for(int i = hd[x] ; i ; i = ned[i].upEd)
			if(ned[i].end != p){
				dfs1(ned[i].end , x); sz[x] += sz[ned[i].end];
				if(sz[ned[i].end] > sz[son[x]]) son[x] = ned[i].end;
			}
	}

	void dfs2(int x , int t){
		top[x] = t;
		if(!son[x]){
			down[x] = x;
			segtree::init(rt[top[x]] , dep[top[x]] , dep[x]);
			for(int i = dep[top[x]] ; i <= dep[x] ; ++i)
				ised[segtree::qid(rt[top[x]] , dep[top[x]] , dep[x] , i)] = 1;
			return;
		}
		dfs2(son[x] , t); down[x] = down[son[x]];
		for(int i = hd[x] ; i ; i = ned[i].upEd)
			if(ned[i].end != fa[x] && ned[i].end != son[x])
				dfs2(ned[i].end , ned[i].end);
	}
	
	void init(){
		for(int i = 2 ; i <= N ; ++i){
			int a = read() , b = i;
			added(a , b); added(b , a);
			ed.push_back(PII(a , b));
		}
		dfs1(1 , 0); dfs2(1 , 1);
	}

	int cmp(int p , int q){return dep[p] > dep[q] ? p : q;}
	
	void add(int p , int q , int id){
		int tp = top[p] , tq = top[q];
		while(tp != tq){
			if(dep[tp] < dep[tq]){swap(p , q); swap(tp , tq);}
			segtree::add(rt[tp] , dep[tp] , dep[down[tp]] , dep[tp] , dep[p] , id);
			p = fa[tp]; tp = top[p];
		}
		if(p == q) return;
		if(dep[p] > dep[q]) swap(p , q);
		segtree::add(rt[top[p]] , dep[top[p]] , dep[down[p]] , dep[p] + 1 , dep[q] , id);
	}

	int qid(int x){return segtree::qid(rt[top[x]] , dep[top[x]] , dep[down[x]] , dep[x]);}
	
	void getans(){
		for(int i = 0 ; i < ed.size() ; ++i){
			int now = qid(cmp(ed[i].first , ed[i].second));
			if(dis[now] != 0x3f3f3f3f) ans[dis[now]].push_back(i + 1);
		}
	}
}T1 , T2;

deque < int > q;
void bfs(int x){
	memset(dis , 0x3f , sizeof(dis));
	dis[x] = 0; q.push_front(x);
	while(!q.empty()){
		int t = q.front(); q.pop_front(); dis[t] += ised[t];
		for(int i = head[t] ; i ; i = Ed[i].upEd)
			if(dis[Ed[i].end] > dis[t]){
				dis[Ed[i].end] = dis[t];
				if(ised[Ed[i].end]) q.push_back(Ed[i].end);
				else q.push_front(Ed[i].end);
			}
	}
}

int main(){
	N = read(); T1.init(); T2.init();
	for(auto t : T1.ed){
		int p = T1.qid(T1.cmp(t.first , t.second));
		T2.add(t.first , t.second , p);
	}
	for(auto t : T2.ed){
		int p = T2.qid(T2.cmp(t.first , t.second));
		T1.add(t.first , t.second , p);
	}
	int id = read() - 1;
	bfs(T1.qid(T1.cmp(T1.ed[id].first , T1.ed[id].second))); T1.getans(); T2.getans();
	for(int i = 1 ; ans[i].size() ; ++i){
		puts(i & 1 ? "Blue" : "Red");
		for(auto t : ans[i]) printf("%d " , t);
		putchar('\n');
	}
	return 0;
}