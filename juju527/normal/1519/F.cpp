#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxs=15625+5,inf=0x3f3f3f3f;
int n,m;
int a[10],b[10];
int c[10][10];
int f[maxs];
bool ban[maxs];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int st[10];
void change(int s){for(int i=m;i>=1;i--)st[i]=s%5,s/=5;return ;}
int get(int *st){int s=0;for(int i=1;i<=m;i++)s=s*5+st[i];return s;}
int tmp[10];
int lim,id,ss;
void dfs(int x,int inc,int co){
	if(x==m+1){
		if(inc<lim)return ;
		int tt=get(tmp);
		f[tt]=min(f[tt],f[ss]+co);
		return ;
	}
	for(int i=0;i<=st[x];i++){
		if(inc+st[x]-i>lim)continue;
		tmp[x]=i;
		dfs(x+1,inc+st[x]-i,co+(i<st[x]?c[id][x]:0));
	}
	return ;
}
int main(){
	n=read();m=read();
	int suma=0,sumb=0;
	for(int i=1;i<=n;i++)a[i]=read(),suma+=a[i];
	for(int i=1;i<=m;i++)b[i]=read(),sumb+=b[i];
	if(suma>sumb){puts("-1");return 0;}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)c[i][j]=read();
	for(int i=1;i<=m;i++)st[i]=b[i];f[get(st)]=0;
	int S=get(st);
	for(int i=0;i<S;i++)f[i]=inf;
	for(int s=1;s<=S;s++){
		change(s);
		for(int i=1;i<=m;i++)if(b[i]<st[i])ban[s]=1;
	}
	for(int i=1;i<=n;i++){
		for(int s=1;s<=S;s++){
			if(ban[s]||f[s]==inf)continue;
			change(s);
			lim=a[i],id=i,ss=s;dfs(1,0,0);
		}
	}
	int res=inf;
	for(int s=0;s<=S;s++){
		change(s);
		int num=0,x=s;
		for(int i=m;i>=1;i--)num+=(x%5),x/=5;
		if(num==sumb-suma)res=min(res,f[s]);
	}
	printf("%d\n",res);
	return 0;
}