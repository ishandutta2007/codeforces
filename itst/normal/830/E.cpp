#include<bits/stdc++.h>
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

const int MAXN = 1e5 + 10;
struct Edge{
	int end , upEd;
}Ed[MAXN << 1];
bool vis[MAXN] ;
int head[MAXN] , d[MAXN] , in[MAXN] , N , M , cntEd;
vector < int > v[3];

inline void addEd(int a , int b){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	head[a] = cntEd;
	++in[b];
}

bool dfs1(int x , int p){
	vis[x] = 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end]){
			if(dfs1(Ed[i].end , x))
				return 1;
		}
		else
			if(Ed[i].end != p)
				return 1;
	return 0;
}

void mark(int x){
	vis[x] = 0;
	if(!d[x])
		d[x] = 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(vis[Ed[i].end])
			mark(Ed[i].end);
}

bool dfs2(int x , int p){
	if(p && in[x] == 3){
		d[x] = 2;
		return 1;
	}
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p)
			if(dfs2(Ed[i].end , x)){
				d[x] = 2;
				return 1;
			}
	return 0;
}

void dfs3(int x , int p , vector < int >& v){
	v.push_back(x);
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p)
			dfs3(Ed[i].end , x , v);
}

int main(){
	for(int T = read() ; T ; --T){
		N = read();
		M = read();
		memset(head , 0 , sizeof(int) * (N + 1));
		memset(vis , 0 , sizeof(bool) * (N + 1));
		memset(d , 0 , sizeof(int) * (N + 1));
		memset(in , 0 , sizeof(int) * (N + 1));
		cntEd = 0;
		for(int i = 1 ; i <= M ; ++i){
			int a = read() , b = read();
			addEd(a , b);
			addEd(b , a);
		}
		bool f = 0;
		for(int i = 1 ; !f && i <= N ; ++i)
			if(!vis[i])
				if(f = dfs1(i , 0))
					mark(i);
		for(int i = 1 ; !f && i <= N ; ++i)
			if(in[i] >= 4){
				d[i] = 2;
				mark(i);
				f = 1;
			}
		for(int i = 1 ; !f && i <= N ; ++i)
			if(in[i] == 3)
				if(f = dfs2(i , 0)){
					memset(vis , 1 , sizeof(vis));
					mark(i);
				}
		for(int i = 1 ; !f && i <= N ; ++i)
			if(in[i] == 3){
				int cnt = 0;
				v[0].clear();
				v[1].clear();
				v[2].clear();
				for(int j = head[i] ; j ; j = Ed[j].upEd)
					dfs3(Ed[j].end , i , v[cnt++]);
				if(v[0].size() > v[1].size())
					swap(v[0] , v[1]);
				if(v[0].size() > v[2].size())
					swap(v[0] , v[2]);
				if(v[1].size() > v[2].size())
					swap(v[1] , v[2]);
				if(v[1].size() == 1 || v[0].size() == 1 && v[1].size() == 2 && v[2].size() < 5)
					continue;
				f = 1;
				if(v[2].size() >= 5){
					d[i] = 6;
					d[v[0][0]] = 3;
					d[v[1][0]] = 4;
					d[v[1][1]] = 2;
					for(int j = 0 ; j < 5 ; ++j)
						d[v[2][j]] = 5 - j;
				}
				else{
					d[i] = (v[0].size() + 1) * (v[1].size() + 1) * (v[2].size() + 1);
					for(int j = 0 ; j < 3 ; ++j)
						for(int k = 0 ; k < v[j].size() ; ++k)
							d[v[j][k]] = (d[i]) / (v[j].size() + 1) * (v[j].size() - k);
				}
			}
		if(f){
			puts("YES");
			for(int i = 1 ; i <= N ; ++i)
				printf("%d " , d[i]);
			putchar('\n');
			continue;
		}
		else
			puts("NO");
	}
	return 0;
}