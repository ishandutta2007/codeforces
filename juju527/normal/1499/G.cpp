#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=4e5+5,maxm=4e5+5,mod=998244353;
int res;
int pw[maxm],ed[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return x>=mod?x-mod:x;}
inline int sub(int x){return x<0?x+mod:x;}
int f[maxm],d[maxm];
int sum[maxm][2];
int find(int x){
	if(f[x]==x)return x;if(f[f[x]]==f[x])return f[x];
	int fa=f[x];
	f[x]=find(f[x]);d[x]^=d[fa];
	return f[x];
}
bool getco(int x){
	if(f[x]==x)return d[x];
	int rt=find(x);
	return d[x]^d[rt];
}
void rev(int x){
	x=find(x);res=sub(res-sum[x][d[x]]);
	d[x]^=1;res=add(res+sum[x][d[x]]);
	return ;
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return ;
	res=sub(res-sum[x][d[x]]);res=sub(res-sum[y][d[y]]);
	f[x]=y;sum[y][d[y]]=add(sum[y][d[y]]+sum[x][d[x]]);sum[y][d[y]^1]=add(sum[y][d[y]^1]+sum[x][d[x]^1]);
	d[x]^=d[y];
	res=add(res+sum[y][d[y]]);
	return ;
}
int tot;
void link(int x,int y){
	int id=++tot;sum[id][0]=pw[id];f[id]=id;res=add(res+pw[id]);
	if(!ed[x]&&!ed[y]){ed[x]=ed[y]=id;return ;}
	if(!ed[x])swap(x,y);
	if(!ed[y]){
		if(!getco(ed[x]))rev(id);
		merge(ed[x],id);ed[x]=0,ed[y]=id;
		return ;
	}
	if(getco(ed[x])!=getco(ed[y]))rev(ed[x]);
	if(!getco(ed[x]))rev(id);
	merge(ed[x],id),merge(id,ed[y]);ed[x]=ed[y]=0;
	return ;
}
int main(){
	int n1,n2,m;
	n1=read();n2=read();m=read();
	pw[0]=1;for(int i=1;i<=4e5;i++)pw[i]=add(pw[i-1]<<1);
	for(int i=1;i<=m;i++){
		int u,v;
		u=read();v=read();
		link(u,v+n1);
	}
	int Q;
	Q=read();
	while(Q--){
		int op,x,y;
		op=read();
		if(op==1){
			x=read();y=read()+n1;
			link(x,y);
			printf("%d\n",res);fflush(stdout);
		}
		else{
			int num=0;
			for(int i=1;i<=tot;i++)if(!getco(i))num++;
			printf("%d ",num);
			for(int i=1;i<=tot;i++)if(!getco(i))printf("%d ",i);
			puts("");fflush(stdout);
		}
	}
    return 0;
}