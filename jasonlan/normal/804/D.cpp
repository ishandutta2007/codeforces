#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#define mp make_pair
using namespace std;
const int maxn=101000;
int n,m,q,rt;
int frt[maxn],dep[maxn],f[maxn],str[maxn];
vector <int> v[maxn],val[maxn],sum[maxn];
map <pair<int,int>,double> ma;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void dfs(int p,int fa){
	f[p]=max(f[p],dep[p]);
	if(dep[rt]<dep[p])rt=p;
	for(register int i=0;i<v[p].size();++i)
		if(v[p][i]!=fa){
			dep[v[p][i]]=dep[p]+1;
			frt[v[p][i]]=frt[p]; 
			dfs(v[p][i],p);
		}
}
void dpush(int p,int fa){
	val[frt[p]].push_back(f[p]);
	for(register int i=0;i<v[p].size();++i)
		if(v[p][i]!=fa)
			dpush(v[p][i],p);
}
void process(int p){
	frt[p]=rt=p;
	dfs(p,0);
	dep[rt]=0;
	dfs(rt,0);
	dep[rt]=0;
	dfs(rt,0);
	str[p]=dep[rt];
	dpush(p,0);
	sort(val[p].begin(),val[p].end());
	sum[p].push_back(0);
	for(register int i=0;i<val[p].size();++i)
		sum[p].push_back(sum[p][i]+val[p][i]);
}
void calc(int x,int y){
	if(x==y){
		puts("-1");return;
	}
	if(val[x].size()<val[y].size())swap(x,y);
	if(ma.count(mp(x,y))){
		printf("%.7lf\n",ma[mp(x,y)]);return;
	}
	double ans=0;
	int g=max(str[x],str[y]);
	for(register int i=0,xp;i<val[y].size();++i){
		xp=upper_bound(val[x].begin(),val[x].end(),g-val[y][i]-1)-val[x].begin();
		ans+=1.0*xp*g;
		ans+=1.0*(val[x].size()-xp)*(val[y][i]+1)+sum[x][val[x].size()]-sum[x][xp];
	}
	ans=ans/val[x].size()/val[y].size();
	printf("%.7lf\n",ans);
	ma[mp(x,y)]=ans;
}
int main(){
	n=read();m=read();q=read();
	for(register int i=1,a,b;i<=m;++i){
		a=read();b=read();
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(register int i=1;i<=n;++i)
		if(!frt[i])process(i);
	for(register int i=1,x,y;i<=q;++i){
		x=frt[read()];y=frt[read()];
		calc(x,y);
	}
	return 0;
}