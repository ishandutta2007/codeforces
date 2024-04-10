#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxr=1e9+5,maxp=4e7+5,maxn=3e6+5;
int l,r,p,n;
int a[maxn];
int f[2][maxn],d[maxn];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int len;
int pr[100];
bitset<100>bj;
void pre(int n){
	for(int i=2;i<=n;i++){
		if(!bj[i])pr[++len]=i;
		for(int j=1;j<=len&&i*pr[j]<=n;j++){
			bj[i*pr[j]]=1;
			if(i%pr[j]==0)break;
		}
	}
	return ;
}
bitset<maxr>vis;
void dfs(int x,int lst){
	vis[x]=1;
	for(int i=lst;i<=len;i++){
		ll y=1ll*x*pr[i];
		if(y>r)return ;
		if(vis[y])continue;
		dfs(y,i);
	}
	return ;
}
int main(){
	l=read();r=read();p=read();
	pre(p);
	dfs(1,1);
	n=vis.count();int x=vis._Find_first();
	for(int i=1;i<=n;i++,x=vis._Find_next(x))a[i]=x,d[i]=p+1;
	bool now=0,pre=1;
	for(int i=1;i<=n;i++)f[now][i]=f[pre][i]=p+1;
	f[pre][1]=0;
	for(int y=1;y<=p;y++){
		int u=1;
		for(int x=1;x<=n;x++){
			if(a[x]%y){
				f[now][x]=f[pre][x]+1;
				continue;
			}
			int z=a[x]/y;
			while(a[u]<z)u++;
			f[now][x]=min(f[pre][x],f[now][u])+1;
			d[x]=min(d[x],f[now][x]);
		}
		swap(now,pre);
	}
	int ans=0;
	for(int i=1;i<=n;i++)if(a[i]>=l&&d[i]<=p)ans++;
	printf("%d\n",ans);
	cerr<<clock()*1.0/CLOCKS_PER_SEC<<endl;
	return 0;
}