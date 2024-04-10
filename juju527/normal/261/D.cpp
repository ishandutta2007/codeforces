#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,maxnt=2e7+5;
int k,n,mxb,t;
int a[maxn];
bool vis[maxn];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int f[maxnt];
int lowbit[maxn],p[maxn];
inline void fmax(int &x,int y){
	if(x<y)x=y;
	return ;
}
void update(int x,int val){
	while(x<=mxb){
		fmax(p[x],val);
		x+=lowbit[x];
	}
	return ;
}
int query(int x){
	int ans=0;
	while(x){
		fmax(ans,p[x]);
		x-=lowbit[x];
	}
	return ans;
}
int main(){
	k=read();n=read();mxb=read();t=read();
	for(int i=1;i<=mxb;i++)lowbit[i]=(i&-i);
	while(k--){
		for(int i=1;i<=n;i++)a[i]=read();
		int s=0;
		for(int i=1;i<=n;i++){
			if(!vis[a[i]])s++;
			vis[a[i]]=1;
		}
		for(int i=1;i<=n;i++)vis[a[i]]=0;
		if(t>=mxb){
			printf("%d\n",s);
			continue;
		}
		for(int i=1;i<=mxb;i++)p[i]=0;
		for(int i=1;i<=n;i++)f[i]=0;
		int now=1,ans=0;
		for(int i=1;i<=n*t;i++){
			int v=query(a[now]-1)+1;
			if(v>f[now]){
				f[now]=v;
				update(a[now],v);
				fmax(ans,v);
			}
			now=now+1;
			if(now==n+1)now-=n;
			if(ans>=s)break;
		}
		printf("%d\n",ans);
	}
	return 0;
}