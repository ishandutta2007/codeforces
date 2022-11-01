#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

const int _ = 1e5 + 7; struct Edge{int end , upEd , w;}Ed[_ << 1]; int head[_] , cntEd , N , Q;
void addEd(int a , int b , int c){Ed[++cntEd] = (Edge){b , head[a] , c}; head[a] = cntEd;}

int rt , mx;
void dfsrt(int x , int p , int d){
	if(mx <= d){mx = d; rt = x;}
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p) dfsrt(Ed[i].end , x , d + Ed[i].w);
}

struct solver{
	int son[_] , dep[_] , mxdep[_] , down[_] , fa[_] , top[_]; vector < int > len , slen;
	void dfs1(int x , int p){
		fa[x] = p;
		for(int i = head[x] ; i ; i = Ed[i].upEd)
			if(Ed[i].end != p){
				dep[Ed[i].end] = dep[x] + Ed[i].w; dfs1(Ed[i].end , x); mxdep[Ed[i].end] += Ed[i].w;
				if(mxdep[Ed[i].end] > mxdep[x]){mxdep[x] = mxdep[Ed[i].end]; son[x] = Ed[i].end;}
			}
	}
	
	void dfs2(int x , int t){
		top[x] = t;
		if(!son[x]) down[x] = x;
		else{
			dfs2(son[x] , t); down[x] = down[son[x]];
			for(int i = head[x] ; i ; i = Ed[i].upEd)
				if(Ed[i].end != fa[x] && Ed[i].end != son[x]) dfs2(Ed[i].end , Ed[i].end);
		}
		if(x == t) len.push_back(mxdep[x]);
	}
	
	void prep(int rt){
		dfs1(rt , 0); dfs2(rt , rt); sort(len.begin() , len.end() , [&](int p , int q){return p > q;}); len.push_back(-1);
		slen.push_back(0); for(int i = 0 ; i < len.size() ; ++i) slen.push_back(slen.back() + len[i]);
	}
	
	int solve(int x , int y){
		static vector < int > del , ins; del.clear(); ins.clear(); x = down[x]; int sum = dep[x];
		for(int i = top[x] ; i ; i = top[x = fa[i]]){del.push_back(mxdep[i]); ins.push_back(mxdep[i] - (dep[x] - dep[fa[i]]));}
		reverse(del.begin() , del.end()); reverse(ins.begin() , ins.end()); del.push_back(-1); ins.push_back(-1);
		int lim = min((int)len.size() - 1 , 2 * y - 2) , pl = lim , pd = 0 , pi = 0; sum += slen[pl];
		while(pl && del[pd] >= len[pl - 1]) sum -= del[pd++];
		while(pl && ins[pi] > len[pl - 1]) sum += ins[pi++];
		while(pl + pi - pd < lim)
			if(del[pd] >= len[pl] && del[pd] >= ins[pi]) sum -= del[pd++];
			else sum += len[pl] >= ins[pi] ? len[pl++] : ins[pi++];
		return sum;
	}
}solve1 , solve2;

int main(){
	N = read(); Q = read(); for(int i = 1 ; i < N ; ++i){int p = read() , q = read() , w = read(); addEd(p , q , w); addEd(q , p , w);}
	dfsrt(1 , 0 , 0); int p = rt; dfsrt(p , 0 , 0); int q = rt; solve1.prep(p); solve2.prep(q); int lastans = 0;
	while(Q--){
		int x = (read() + lastans - 1) % N + 1 , y = (read() + lastans - 1) % N + 1;
		printf("%d\n" , lastans = max(solve1.solve(x , y) , solve2.solve(x , y)));
	}
	return 0;
}