#include<bits/stdc++.h>
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

const int MAXN = 5e5 + 7;
struct Edge{
	int s , t , w;
	bool operator <(const Edge a)const{return w < a.w;}
}Ed[MAXN << 3];
int ind[MAXN << 3] , side[MAXN << 3][2] , fa[MAXN];
int N , M;
vector < int > que;

int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}

bool cmp(int a , int b){return Ed[a].w < Ed[b].w;}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	N = read();
	M = read();
	for(int i = 1 ; i <= M ; ++i){
		Ed[i].s = read();
		Ed[i].t = read();
		Ed[i].w = read();
		ind[i] = i;
	}
	for(int i = 1 ; i <= N ; ++i) fa[i] = i;
	sort(ind + 1 , ind + M + 1 , cmp);
	for(int i = 1 , pi = 1 ; i <= M ; ){
		while(pi <= M && Ed[ind[pi]].w == Ed[ind[i]].w){
			side[ind[pi]][0] = find(Ed[ind[pi]].s);
			side[ind[pi]][1] = find(Ed[ind[pi]].t);
			++pi;
		}
		while(i < pi){fa[find(Ed[ind[i]].s)] = find(Ed[ind[i]].t); ++i;}
	}
	for(int i = 1 ; i <= N ; ++i) fa[i] = i;
	queue < int > q;
	for(int Q = read() ; Q ; --Q){
		int K = read();
		que.clear();
		for(int i = 0 ; i < K ; ++i){
			int a = read();
			que.push_back(a);
		}
		sort(que.begin() , que.end() , cmp);
		bool f = 1;
		for(int i = 0 , pi = 0 ; i < K && f ; i = pi){
			while(f && pi < K && Ed[que[pi]].w == Ed[que[i]].w){
				if(find(side[que[pi]][0]) == find(side[que[pi]][1]))
					f = 0;
				q.push(find(side[que[pi]][0]));
				fa[find(side[que[pi]][0])] = find(side[que[pi]][1]);
				++pi;
			}
			while(!q.empty()){
				fa[q.front()] = q.front();
				q.pop();
			}
		}
		puts(f ? "YES" : "NO");
	}
	return 0;
}