#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>

using std::max;
using std::min;

long long a[2][300001];
std::map<long long,int>map[3];
int n,pre[2][300001][21],f[300001],mnpre[300001],mxadd[2][300001],mnpos[600001],nxt[2][300001];
int query(int bit,int l,int r){
//	printf("query %d %d %d ",bit,l,r);
	int ans=0;
	for(int i=20;~i;--i)
		if(pre[bit][r][i]>=l)r=pre[bit][r][i],ans+=1<<i;
//	printf("%d\n",ans);
	return ans;
}
int main(){
//	freopen("CF771E.in","r",stdin);
//	freopen("CF771E.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<2;i++)
		for(int j=1;j<=n;j++)
			scanf("%I64d",&a[i][j]),a[i][j]+=a[i][j-1];
	map[0][0]=map[1][0]=map[2][0]=1;
	memset(pre,-1,sizeof pre);
	memset(nxt,0x7f7f7f7f,sizeof nxt);
	memset(mxadd,0x7f7f7f7f,sizeof mxadd);
	memset(mnpos,-1,sizeof mnpos);
	for(int i=1;i<=n;i++){
		pre[0][i][0]=max(pre[0][i-1][0],map[0][a[0][i]]-1);
		pre[1][i][0]=max(pre[1][i-1][0],map[1][a[1][i]]-1);
		if(~pre[0][i][0])nxt[0][pre[0][i][0]]=min(nxt[0][pre[0][i][0]],i);
		if(~pre[1][i][0])nxt[1][pre[1][i][0]]=min(nxt[1][pre[1][i][0]],i);
		mnpre[i]=map[2][a[0][i]+a[1][i]]-1;
		map[0][a[0][i]]=map[1][a[1][i]]=map[2][a[0][i]+a[1][i]]=i+1;
	}
	for(int i=n-1;~i;i--)nxt[0][i]=min(nxt[0][i],nxt[0][i+1]),nxt[1][i]=min(nxt[1][i],nxt[1][i+1]);
//	for(int i=1;i<=n;i++)printf("%d %d\n",nxt[0][i],nxt[1][i]);
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n;i++){
			if(~pre[0][i][j-1])pre[0][i][j]=pre[0][pre[0][i][j-1]][j-1];
			if(~pre[1][i][j-1])pre[1][i][j]=pre[1][pre[1][i][j-1]][j-1];
		}
	mnpos[0]=0;
	mxadd[0][0]=nxt[0][0];
	mxadd[1][0]=nxt[1][0];
	for(int i=1;i<=n;i++){
		int tem=pre[0][i][0];
		f[i]=f[i-1];
		if(~tem){
			if(mxadd[1][tem]<=i)f[i]=max(f[i],f[tem]+2+query(1,mxadd[1][tem],i));
			else f[i]=max(f[i],f[tem]+1);
		}
		tem=pre[1][i][0];
		if(~tem){
			if(mxadd[0][tem]<=i)f[i]=max(f[i],f[tem]+2+query(0,mxadd[0][tem],i));
			else f[i]=max(f[i],f[tem]+1);
		}
		if(~min(pre[0][i][0],pre[1][i][0])){
			if(pre[0][i][0]<pre[1][i][0])
				if(mxadd[1][pre[0][i][0]]<=pre[1][i][0])f[i]=max(f[i],f[pre[0][i][0]]+3+query(1,mxadd[1][pre[0][i][0]],pre[1][i][0]));
				else f[i]=max(f[i],f[pre[0][i][0]]+2);
			else
				if(mxadd[0][pre[1][i][0]]<=pre[0][i][0])f[i]=max(f[i],f[pre[1][i][0]]+3+query(0,mxadd[0][pre[1][i][0]],pre[0][i][0]));
				else f[i]=max(f[i],f[pre[1][i][0]]+2);
		}
		if(~mnpre[i])f[i]=max(f[i],f[mnpre[i]]+1);
		if(!~mnpos[f[i]])mnpos[f[i]]=i;
		int l=i+1,r=n,mid,ans=n+1;
		while(l<=r){
			mid=(l+r)>>1;
			int tem=pre[0][mid][0],fin=0;
			if(!~tem){
				l=mid+1;
				continue;
			}
			if(tem>=i){
				ans=mid,r=mid-1;
				continue;
			}
			if(mxadd[1][tem]<=i)fin=f[tem]+2+query(1,mxadd[1][tem],i);
			else fin=f[tem]+1;
			if(fin>=f[i]+1)ans=mid,r=mid-1;
			else l=mid+1;
		}
		mxadd[0][i]=ans;
		l=i+1,r=n,mid,ans=n+1;
		while(l<=r){
			mid=(l+r)>>1;
			int tem=pre[1][mid][0],fin=0;
			if(!~tem){
				l=mid+1;
				continue;
			}
			if(tem>=i){
				ans=mid,r=mid-1;
				continue;
			}
			if(mxadd[0][tem]<=i)fin=f[tem]+2+query(0,mxadd[0][tem],i);
			else fin=f[tem]+1;
			if(fin>=f[i]+1)ans=mid,r=mid-1;
			else l=mid+1;
		}
		mxadd[1][i]=ans;
//		printf("%d %d %d\n",f[i],mxadd[0][i],mxadd[1][i]);
	}
//	for(int i=1;i<=n;i++)printf("%d ",mnpos[i]);putchar('\n');
	printf("%d",f[n]);
}