#include<bits/stdc++.h>
using namespace std;
const int M=2e5+9;
int n,m,v;
int a[M],b[M],ans[M],vis[M];
struct P{
	int x,y,o;
}p[M];
map<int,bool>mp;
void add(int i){for(;i<=n+m;i+=i&-i)b[i]++;}
int sum(int i,int rex=0){for(;i;i-=i&-i)rex+=b[i];return rex;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&p[i].x,&p[i].y);
		a[i]=p[i].y;
	}
	for(int i=1;i<=m;++i){
		scanf("%d%d",&p[i+n].x,&p[i+n].y);
		a[i+n]=p[i+n].y;
		p[i+n].o=i;
	}
	sort(a+1,a+n+m+1);
	sort(p+1,p+n+m+1,[&](const P&l,const P&r){return l.x==r.x?(l.y==r.y?l.o<r.o:l.y<r.y):l.x<r.x;});
	int t=unique(a+1,a+n+m+1)-a-1;
	for(int i=1;i<=n+m;++i){
		int x=p[i].x,y=lower_bound(a+1,a+t+1,p[i].y)-a,h=sum(y);
		if(p[i].o){
			if(p[i-1].x!=x||p[i-1].y!=p[i].y){
				ans[p[i].o]=mp.count(x)||vis[y]||h-v!=p[i].y-x;
			}
		}
		else {
			if(h-v<p[i].y-x){
				if(!vis[y])add(y),vis[y]=1;
			}
			else if(h-v>p[i].y-x)v+=!mp.count(x),mp[x]=1;
		}
	}
	for(int i=1;i<=m;++i)puts(ans[i]?"WIN":"LOSE");
	return 0;
}