#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=500009;
int n,m,num;
int va[M],vb[M];
set<int>g[M],s;
vector<int>a,b;
int t[M<<1];
void push(int x,int y){
	for(t[x+=n-1]=y;x;x>>=1){
		if(t[x]==0||t[x^1]==0)t[x>>1]=t[x]+t[x^1];
		else t[x>>1]=g[t[x]].size()>g[t[x^1]].size()?t[x]:t[x^1];
	}
}
void change(){
	for(auto o:a){
		for(auto v:g[o]){
			g[v].erase(o);
			push(v,v);
		}
	}
	for(auto o:b){
		for(auto v:g[o]){
			g[v].erase(o);
			push(v,v);
		}
	}
	for(auto o:a)s.erase(o),push(o,0);
	for(auto o:b)s.erase(o),push(o,0);
	int tot=num;
	for(auto o:a)va[o]=++tot;
	for(auto o:b)va[o]=++tot;
	tot=num;
	for(auto o:b)vb[o]=++tot;
	for(auto o:a)vb[o]=++tot;
	num=tot;
	a.clear();
	b.clear();
}
void work(){
	scanf("%d%d",&n,&m);
	s.clear();
	num=0;
	for(int i=1;i<=n;++i)g[i].clear(),s.insert(i);
	for(int i=1;i<=m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].insert(v);
		g[v].insert(u);
	}
	for(int i=1;i<=n;++i)push(i,i);
	while(t[1]){
		int u=t[1];
		if(g[u].size()==s.size()-1){
			va[u]=vb[u]=++num;
			for(auto o:g[u]){
				g[o].erase(u);
			}
			s.erase(u);
			push(u,0);
		}
		else if(g[u].size()==s.size()-2){
			int k=s.size()-2;
			s.erase(u);
			a.eb(u);
			for(auto o:g[u]){
				s.erase(o);
			}
			int v=*s.begin();
			b.eb(v);
			s.insert(u);
			for(auto o:g[u]){
				s.insert(o);
				if(g[o].size()==k&&!g[o].count(v)){
					a.eb(o);
				}
			}
		}
		else if(g[u].size()==s.size()-3){
			int k=s.size()-3;
			s.erase(u);
			a.eb(u);
			for(auto o:g[u]){
				s.erase(o);
			}
			for(auto o:s){
				if(g[o].size()==k){
					if(b.size()==0)b.eb(o);
					else{
						if(!g[o].count(u)&&!g[o].count(b[0]))b.eb(o);
					}
				}
			}
			if(b.size()==0)b.eb(*s.begin());
			s.insert(u);
			for(auto o:g[u]){
				s.insert(o);
			}
		}
		else{
			s.erase(u);
			a.eb(u);
			for(auto o:g[u]){
				s.erase(o);
			}
			b.eb(*s.begin());
			s.insert(u);
			for(auto o:g[u]){
				s.insert(o);
			}
		}
		change();
	}
	for(int i=1;i<=n;++i)printf("%d%c",va[i]," \n"[i==n]);
	for(int i=1;i<=n;++i)printf("%d%c",vb[i]," \n"[i==n]);	
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
13 26
3 8
12 10
5 2
4 5
8 7
9 12
9 7
4 2
10 8
6 9
13 10
4 8
10 3
4 9
5 8
11 6
9 2
2 10
1 13
4 12
6 8
11 4
7 5
10 9
5 12
13 12

*/