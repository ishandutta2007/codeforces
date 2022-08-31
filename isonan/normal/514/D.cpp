#include <cstdio>

int st[5][100001][21],loga[100001],n,m,k,ansL,ansR,ansV;
int max(int a,int b){return a>b?a:b;}
int get(int dim,int l,int r){
	if(l==r+1)return 0;
	int k=loga[r-l+1];
	return max(st[dim][l][k],st[dim][r-(1<<k)+1][k]);
}
int judge(int l,int r){
	int tot=0;
	for(int i=0;i<m;i++)tot+=get(i,l,r);
	return tot;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	loga[0]=-1;
	for(int i=1;i<=n;i++)loga[i]=loga[i>>1]+1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&st[j][i][0]);
	for(int dim=0;dim<m;dim++)
		for(int j=1;(1<<j)<=n;j++)
			for(int i=1;i+(1<<j)-1<=n;i++)
				st[dim][i][j]=max(st[dim][i][j-1],st[dim][i+(1<<(j-1))][j-1]);
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid,ans=-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(judge(mid,i)<=k)ans=mid,r=mid-1;
			else l=mid+1;
		}
		if(ans!=-1&&i-ans+1>ansV)ansL=ans,ansR=i,ansV=i-ans+1;
	}
	if(!ansV)for(int i=0;i<m;i++)printf("%d ",0);
	else for(int i=0;i<m;i++)printf("%d ",get(i,ansL,ansR));
}