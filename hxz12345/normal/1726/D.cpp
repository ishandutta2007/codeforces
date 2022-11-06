#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((ch!='-')&&(!isdigit(ch))) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
vector<int> edge[1001010];
int id,ext[1001010],cnt,f[1001010],fa[1001010],dep[1001010];
int n,m,i,r1,r2,col[1001010],a[1001010],b[1001010];
int find(int x){
	if (f[x]==x) return f[x];
	f[x]=find(f[x]);return f[x];
}
void sc(int x){
	for (int aa:edge[x]){
		if (aa==fa[x]) continue;
		fa[aa]=x;dep[aa]=dep[x]+1;
		sc(aa);
	}
}
void Main(){
	n=read();m=read();
	for (i=1;i<=n;i++) dep[i]=fa[i]=0;
	for (i=1;i<=m;i++) a[i]=read(),b[i]=read(),f[i]=i;
	for (i=1;i<=n;i++) edge[i].clear();
		for (i=1;i<=m;i++){
			r1=find(a[i]);r2=find(b[i]);
			if (r1!=r2) 
		edge[a[i]].push_back(b[i]),
		edge[b[i]].push_back(a[i]),f[r1]=r2,col[i]=1;
			else col[i]=0;
		}
	if (m==n+2){
		id=i;
		for (i=1;i<=n;i++) ext[i]=0;
		for (i=1;i<=m;i++)
		    if (col[i]==0) id=i,ext[a[i]]=ext[b[i]]=1;
		cnt=0;
		for (i=1;i<=n;i++) cnt+=(ext[i]>0);
		if (cnt==3){
			sc(1);
			if (dep[a[id]]<dep[b[id]]) swap(a[id],b[id]);
			for (i=1;i<=m;i++)
			    if ((a[i]==a[id])&&(b[i]==fa[a[id]])) 
			       swap(col[id],col[i]);
			       else if ((b[i]==a[id])&&(a[i]==fa[a[id]]))
			          swap(col[id],col[i]);
		}
	}
	for (i=1;i<=m;i++) cout<<col[i];
	puts("");
	return ;
}
int main(){
	int Testing=read();
	for (;Testing;Testing--) Main();
	return 0;
}