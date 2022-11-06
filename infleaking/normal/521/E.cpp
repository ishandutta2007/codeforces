#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
int w[N],ne[N],la[N],t=1,fa[N],vis[N],n,m,dep[N];
void link(int x,int y){
	w[++t]=y;
	ne[t]=la[x];
	la[x]=t;
}
int mrk[N];
void dfs(int x){
	vis[x]=1;
	for (int y=la[x];y;y=ne[y]){
		int z=w[y];
		if (!vis[z])fa[z]=x,dep[z]=dep[x]+1,dfs(z);
	}
}
void write(int p,int q,int x,int y){
	if (dep[x]>dep[y])swap(x,y);
	cout<<(dep[y]-dep[x]+1)-(dep[q]-dep[p]-1);
	for (int u=p;u!=x;u=fa[u])printf(" %d",u);
	printf(" %d",x);
	for (int u=y;u!=q;u=fa[u])printf(" %d",u);
	printf(" %d\n",q);
}
void print(int i,int j){
	memset(mrk,0,sizeof mrk);
	cout<<"YES"<<endl;
	for (int x=w[i*2],y=w[i*2+1];x!=y;x=fa[x]){
		if (dep[x]<dep[y])swap(x,y);
		mrk[x]++;
	}
	for (int x=w[j*2],y=w[j*2+1];x!=y;x=fa[x]){
		if (dep[x]<dep[y])swap(x,y);
		mrk[x]+=2;
	}
	int p=0,q=0;
	for (int i=1;i<=n;i++)
		if (mrk[i]==3){
			if (p==0||dep[p]>dep[i])p=i;
			if (q==0||dep[q]<dep[i])q=i;
		}
	p=fa[p];
	vector<int> h;
	cout<<dep[q]-dep[p]+1;
	for (int x=q;dep[x]>=dep[p];x=fa[x])h.push_back(x);
	for (;h.size();h.pop_back())printf(" %d",h.back());
	cout<<endl;
	write(p,q,w[i*2],w[i*2+1]);
	write(p,q,w[j*2],w[j*2+1]);
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y);
		link(y,x);
	}
	for (int i=1;i<=n;i++){
		if (!vis[i])
			dep[i]=1,dfs(i);
	}
	for (int i=1;i<=m;i++){
		int x=w[i*2],y=w[i*2+1];
		if (fa[x]==y||fa[y]==x)continue;
		if (dep[x]<dep[y])swap(x,y);
		for (;x!=y;x=fa[x]){
			if (mrk[x]){
				print(mrk[x],i);
				return 0;
			}
			mrk[x]=i;
		}
	}
	cout<<"NO"<<endl;
}