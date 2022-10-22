#include<bits/stdc++.h>
using namespace std;
const int M=1e6+9;
int n,q,num;
int pri[M],vis[M],f[M],d[M],a[M];
map<int,int>mp[M];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int main(){
	for(int i=2;i<M;++i){
		f[i]=i;
		if(!vis[i])pri[++num]=i,vis[i]=i;
		for(int j=1;j<=num&&1ll*pri[j]*i<M;++j){
			vis[i*pri[j]]=pri[j];
			if(i%pri[j]==0)break;
		}
	}
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		int x=a[i];
		while(x!=1){
			int y=vis[x];
			f[find(a[i])]=find(y);
			while(x%y==0)x/=y;
		}
	}
	for(int i=1;i<=n;++i){
		int x=a[i]+1,m=0;
		d[++m]=find(a[i]);
		while(x!=1){
			int y=vis[x];
			d[++m]=find(y);
			while(x%y==0)x/=y;
		}
		sort(d+1,d+m+1);
		m=unique(d+1,d+m+1)-d-1;
		for(int j=1;j<=m;++j){
			for(int k=j+1;k<=m;++k)mp[d[j]][d[k]]=mp[d[k]][d[j]]=1;
		}
	}
	for(int i=1,x,y;i<=q;++i){
		scanf("%d%d",&x,&y);
		if(find(a[x])==find(a[y]))puts("0");
		else if(a[x]%2!=a[y]%2)puts("1");
		else {
			x=find(a[x]);
			y=find(a[y]);
			if(mp[x].count(y))puts("1");
			else puts("2");
		}
	}
	return 0;
}