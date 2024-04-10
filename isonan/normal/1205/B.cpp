#include <cstdio>
#include <algorithm>

long long a[100001],b[100001],top;
int n,f[101][101],dis[100001],ans;
bool bit[101];
int con(int i,int j){return (b[i]&b[j])!=0;}
void dfs(int x,int d,int orig){
	if(dis[x]<=d)return;
	dis[x]=d;
	if(con(x,orig)&&d>=2)ans=std::min(ans,d+1);
	for(int i=1;i<=n;i++)
		if(con(x,i))dfs(i,d+1,orig);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%I64d",a+i);
		long long tem=a[i];
		for(int j=0;j<64;j++){
			bit[j]=tem&1;
			tem>>=1;
		}
		for(int j=0;~a[i]&&j<64;j++)
			for(int k=0;~a[i]&&k<64;k++)
				if(bit[j]&&bit[k]){
					if(f[j][k]==2){
						puts("3");
						return 0;
					}
					++f[j][k];
					b[++top]=a[i];
					a[i]=-1;
				}
	}
	ans=top+1;
	for(int i=1;i<=top;i++){
		for(int j=1;j<=top;j++)dis[j]=top+1;
		dfs(i,0,i);
	}
	if(ans==top+1)puts("-1");
	else printf("%d\n",ans);
}