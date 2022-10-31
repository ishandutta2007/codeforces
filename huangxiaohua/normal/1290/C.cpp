#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res,a[1000500],fa[1000500],it,jj,kk,M=300000;
ll siz[1000500];
vector<int> v[1000500];
int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=1000000;i++){fa[i]=i;}
	for(i=1;i<=n;i++){
		scanf("%1d",&a[i]);
	}
	for(i=1;i<=m;i++){
		scanf("%d",&t);siz[i]=1;
		while(t--){scanf("%d",&k);v[k].push_back(i);}
	}
	for(i=1;i<=n;i++){
		if(!a[i]){
			if(v[i].size()==2){
				j=v[i][0];k=v[i][1];
				jj=find(j);kk=find(k);
				if(jj==find(k+M)){goto aaa;}
				res-=min(siz[jj],siz[find(j+M)]);
				res-=min(siz[kk],siz[find(k+M)]);
				
				siz[jj]+=siz[find(k+M)];
				siz[kk]+=siz[find(j+M)];
				res+=min(siz[jj],siz[kk]);
				
				fa[find(j+M)]=kk;
				fa[find(k+M)]=jj;
			}
			if(v[i].size()==1){
				j=v[i][0];
				jj=find(j);
				res-=min(siz[jj],siz[find(j+M)]);
				siz[find(j+M)]=11451419;
				res+=min(siz[jj],siz[find(j+M)]);
			}
		}
		else{
			if(v[i].size()==1){
				j=v[i][0];
				jj=find(j);
				res-=min(siz[jj],siz[find(j+M)]);
				siz[jj]=11451419;
				res+=siz[find(j+M)];
			}
			if(v[i].size()==2){
				j=v[i][0];k=v[i][1];
				jj=find(j);kk=find(k);
				if(jj==kk){goto aaa;}
				res-=min(siz[jj],siz[find(j+M)]);
				res-=min(siz[kk],siz[find(k+M)]);
				
				siz[jj]+=siz[kk];
				siz[find(j+M)]+=siz[find(k+M)];
				
				res+=min(siz[jj],siz[find(j+M)]);
				fa[find(kk)]=jj;
				fa[find(k+M)]=find(j+M);
			}
		}
		aaa:printf("%d\n",res);
	}
}