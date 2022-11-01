#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

#define III tuple < int , int , int >
const int _ = 1503;
int N , M , K , P[_] , Q[_] , W[_]; mt19937 rnd(time(0));

namespace Tree{
	vector < III > now; void addE(int a , int b , int c){now.push_back(III(-c , a , b));}
	int fa[_]; vector < int > id[_];
	int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}
	
	void work(){
		for(int i = 1 ; i <= N ; ++i){fa[i] = i; id[i] = {i};}
		sort(now.begin() , now.end()); int sum = 0;
		for(auto t : now){
			sum -= get<0>(t); int x = find(get<1>(t)) , y = find(get<2>(t));
			fa[x] = y; id[y].insert(id[y].end() , id[x].begin() , id[x].end());
		}
		cout << sum << endl; int t = find(1);
		for(auto x : id[t]) cout << x << ' ';
	}
}

namespace Hu{
	//Flow Begin
	const int _ = 1e6 + 7 , __ = 1e7 + 7;
	struct Edge{int end , upEd , f;}Ed[__];
	int cur[_] , head[_] , cntEd , dep[_] , S , T;
	void addEd(int a , int b , int c){Ed[++cntEd] = (Edge){b , head[a] , c}; head[a] = cntEd;}
	void addE(int a , int b , int c){addEd(a , b , c); addEd(b , a , c);}
	
	queue < int > q;
	bool bfs(){
		while(!q.empty()) q.pop();
		q.push(S); memset(dep , 0 , sizeof(int) * (N + 1)); dep[S] = 1;
		while(!q.empty()){
			int t = q.front(); q.pop();
			for(int i = head[t] ; i ; i = Ed[i].upEd)
				if(Ed[i].f && !dep[Ed[i].end]){
					dep[Ed[i].end] = dep[t] + 1;
					if(Ed[i].end == T){memcpy(cur , head , sizeof(int) * (N + 1)); return 1;}
					q.push(Ed[i].end);
				}
		}
		return 0;
	}

	int dfs(int x , int mn){
		if(x == T) return mn;
		int sum = 0;
		for(int &i = cur[x] ; i ; i = Ed[i].upEd)
			if(Ed[i].f && dep[Ed[i].end] == dep[x] + 1){
				int t = dfs(Ed[i].end , min(mn - sum , Ed[i].f));
				Ed[i].f -= t; Ed[i ^ 1].f += t; if(mn == (sum += t)) break;
			}
		return sum;
	}

	bool inleft[_];
	int Dinic(int s , int t){
		S = s; T = t; int sum = 0;
		while(bfs())
			sum += dfs(s , 1e9);
		for(int i = 0 ; i <= N ; ++i) inleft[i] = dep[i];
		return sum;
	}
	void buildflow(){
		memset(head , 0 , sizeof(int) * (N + 1)); cntEd = 1;
		for(int i = 1 ; i <= M ; ++i) addE(P[i] , Q[i] , W[i]);
	}
	//Flow End
	
	void build(vector < int > now){
		if(now.size() == 1) return;
		int p = rnd() % now.size() , q = rnd() % now.size();
		while(p == q) p = rnd() % now.size() , q = rnd() % now.size();
		buildflow(); Tree::addE(now[p] , now[q] , Dinic(now[p] , now[q]));
		vector < int > L , R; for(auto t : now) (inleft[t] ? L : R).push_back(t);
		build(L); build(R);
	}
}

int main(){
	N = read(); M = read(); for(int i = 1 ; i <= M ; ++i){P[i] = read(); Q[i] = read(); W[i] = read();}
	vector < int > node; for(int i = 0 ; i <= N ; ++i) node.push_back(i);
	Hu::build(node); Tree::work();
	return 0;
}