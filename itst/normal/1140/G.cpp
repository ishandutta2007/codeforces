#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
//This code is written by Itst
using namespace std;

#define int long long
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

const int MAXN = 3e5 + 7;
int N , Q;
struct Edge{int end , upEd , w;};

inline void addEd(Edge *Ed , int *head , int &cntEd , int a , int b , int c , bool f = 0){
	Ed[++cntEd] = (Edge){b , head[a] , c};
	head[a] = cntEd;
	if(f){
		Ed[++cntEd] = (Edge){a , head[b] , c};
		head[b] = cntEd;
	}
}

namespace SSSP{
#define PII pair < int , int >
#define st first
#define nd second
	Edge Ed[MAXN << 2];
	int head[MAXN] , dis[MAXN];
	int cntEd;
	priority_queue < PII > q;
	
	void work(){
		memset(dis , 0x7f , sizeof(dis));
		dis[0] = 0;
		q.push(PII(0 , 0));
		while(!q.empty()){
			PII t = q.top(); q.pop();
			if(dis[t.nd] != -t.st) continue;
			for(int i = head[t.nd] ; i ; i = Ed[i].upEd)
				if(dis[t.nd] + Ed[i].w < dis[Ed[i].end])
					q.push(PII(-(dis[Ed[i].end] = dis[t.nd] + Ed[i].w) , Ed[i].end));
		}
	}
}

namespace Tree{
    Edge Ed[MAXN << 1];
	struct matrix{
		int a[2][2];
		matrix(){memset(a , 0x3f , sizeof(a));}
		int* operator [](int x){return a[x];}
		matrix operator *(matrix b){
			matrix c;
			for(int i = 0 ; i < 2 ; ++i)
				for(int j = 0 ; j < 2 ; ++j)
					for(int k = 0 ; k < 2 ; ++k)
						c[j][k] = min(c[j][k] , a[j][i] + b[i][k]);
			return c;
		}
	}dis[MAXN][20] , tmp , initial , toX , toY;
	int head[MAXN] , dep[MAXN] , fa[MAXN][20] , val2[MAXN << 1] , cntEd;
	
	void dfs(int x , int p , matrix val){
		dis[x][0] = val;
		fa[x][0] = p;
		for(int i = 1 ; fa[x][i - 1] ; ++i){
			fa[x][i] = fa[fa[x][i - 1]][i - 1];
			dis[x][i] = dis[x][i - 1] * dis[fa[x][i - 1]][i - 1];
		}
		dep[x] = dep[p] + 1;
		for(int i = head[x] ; i ; i = Ed[i].upEd)
			if(Ed[i].end != p){
				tmp[1][0] = min(Ed[i].w + SSSP::dis[Ed[i].end] , val2[i] + SSSP::dis[x]);
				tmp[0][1] = min(val2[i] + SSSP::dis[Ed[i].end] , Ed[i].w + SSSP::dis[x]);
				tmp[0][0] = min(Ed[i].w , tmp[0][1] + SSSP::dis[x]);
				tmp[1][1] = min(val2[i] , tmp[1][0] + SSSP::dis[x]);
				dfs(Ed[i].end , x , tmp);
			}
	}
	
	void init(){
		memset(initial.a , 0 , sizeof(initial));
		dfs(1 , 0 , initial);
	}
	
	int jump(int x , int y , bool f1 , bool f2){
		if(dep[x] < dep[y]){
			x ^= y ^= x ^= y;
			swap(f1 , f2);
		}
		toX = initial; toY = initial;
		toX[0][1] = toX[1][0] = SSSP::dis[x];
		toY[0][1] = toY[1][0] = SSSP::dis[y];
		for(int i = 18 ; i >= 0 ; --i)
			if(dep[x] - (1 << i) >= dep[y]){
				toX = toX * dis[x][i];
				x = fa[x][i];
			}
		if(x == y) return toX[f1][f2];
		for(int i = 18 ; i >= 0 ; --i)
			if(fa[x][i] != fa[y][i]){
				toX = toX * dis[x][i];
				toY = toY * dis[y][i];
				x = fa[x][i]; y = fa[y][i];
			}
		toX = toX * dis[x][0]; toY = toY * dis[y][0];
		return min(toX[f1][0] + toY[f2][0] , toX[f1][1] + toY[f2][1]);
	}
	
	void work(int x , int y){
		bool f1 = !(x & 1) , f2 = !(y & 1);
		x = (x + 1) >> 1; y = (y + 1) >> 1;
		printf("%lld\n" , jump(x , y , f1 , f2));
	}
}

signed main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
#endif
	N = read();
	for(int i = 1 ; i <= N ; ++i)
		addEd(SSSP::Ed , SSSP::head , SSSP::cntEd , 0 , i , read());
	for(int i = 1 ; i < N ; ++i){
		int a = read() , b = read() , w1 = read() , w2 = read();
		addEd(SSSP::Ed , SSSP::head , SSSP::cntEd , a , b , w1 + w2 , 1);
		addEd(Tree::Ed , Tree::head , Tree::cntEd , a , b , w1 , 1);
		Tree::val2[Tree::cntEd] = Tree::val2[Tree::cntEd - 1] = w2;
	}
	SSSP::work(); Tree::init();
	for(int Q = read() ; Q ; --Q)
		Tree::work(read() , read());
	return 0;
}