#include <cstdio>
#include <bitset>

int n,m,q,mat[13][100001],que[3][100001],cnt;
std::bitset<4096>val[100020];
int main(){
	scanf("%d%d%d",&m,&n,&q);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&mat[i][j]);
	for(int i=0;i<(1<<n);i++)
		for(int j=1;j<=n;j++)
			if(i&(1<<(j-1)))val[j].set(i);
	cnt=n;
	for(int i=1,t,a,b;i<=q;i++){
		scanf("%d%d%d",&t,&a,&b);
		if (t==3){
			int l=0,r=1000000000,mid,ans;
			while(l<=r){
				mid=(l+r)>>1;
				int now=0;
				for(int i=1;i<=n;i++)if(mat[i][b]>=mid)now|=1<<(i-1);
				if(val[a][now]==1)ans=mid,l=mid+1;
				else r=mid-1;
			}
			printf("%d\n",ans);
		}
		else val[++cnt]=(t==1)?(val[a]|val[b]):(val[a]&val[b]);
	}
}