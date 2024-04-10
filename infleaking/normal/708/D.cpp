#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int w[N],ne[N],la[N],len[N],cst[N],t=1;
void alink(int x,int y,int z,int c){
	w[++t]=y;
	ne[t]=la[x];
	la[x]=t;
	len[t]=z;
	cst[t]=c;
}
void link(int x,int y,int z,int c){
	alink(x,y,z,c);
	alink(y,x,0,-c);
}
int d[N],vis[N],S,T,dep[N],s[N],cur[N],n,m;
int ind[N],oud[N];
int spfa(){
	for (int i=1;i<=T;i++)vis[i]=0,s[i]=1e9;
	s[S]=0,vis[S]=1;d[1]=S;
	int l=0,r=1;
	while (l<r){
		int x=d[++l];
		for (int y=la[x];y;y=ne[y]){
			int z=w[y];
			if (s[z]>s[x]+cst[y]&&len[y]){
				s[z]=s[x]+cst[y];
				if (!vis[z]){
					vis[z]=1;
					d[++r]=z;
				}
			}
		}
		vis[x]=0;
	}
	l=0,r=1;vis[S]=1;
	while (l<r){
		int x=d[++l];
		cur[x]=la[x];
		for (int y=la[x];y;y=ne[y]){
			int z=w[y];
			if (!vis[z]&&s[z]==s[x]+cst[y]&&len[y]){
				vis[z]=1;
				d[++r]=z;
				dep[z]=dep[x]+1;
			}
		}
	}
	return vis[T];
}
int ans;
int flow(int x,int val){
	if (x==T)return val;
	int v1=val;
	for (int y=cur[x];y;cur[x]=y=ne[y]){
		int z=w[y];
		if (dep[z]!=dep[x]+1||s[z]!=s[x]+cst[y]||!len[y])continue;
		int use=flow(z,min(val,len[y]));
		val-=use;
		len[y]-=use;
		len[y^1]+=use;
		ans+=cst[y]*use;
		if (!val)break;
	}return v1-val;
}
int main(){
	cin>>n>>m;
	S=n+1,T=n+2;
	for (int i=1;i<=m;i++){
		int x,y,c,f;
		scanf("%d%d%d%d",&x,&y,&c,&f);
		ind[y]+=f;
		oud[x]+=f;
		if (c>=f){
			link(y,x,f,1);
			link(x,y,c-f,1);
			link(x,y,1<<30,2);
		}
		else {
			ans+=f-c;
			link(x,y,1<<30,2);
			link(y,x,f-c,0);
			link(y,x,c,1);
		}
	}
	for (int i=1;i<=n;i++)
		link(S,i,ind[i],0),link(i,T,oud[i],0);
	link(n,1,1<<30,0);
	while (spfa())flow(S,1<<30);
	cout<<ans<<endl;
}