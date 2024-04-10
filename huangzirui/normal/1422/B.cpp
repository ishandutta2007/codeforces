#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=105;
int T,n,m,stp;
long long ans;
int a[maxn][maxn],vis[maxn][maxn];
vector<int>v;
inline int abs(int x){
	return x<0? -x:x;
}
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0,stp++;	
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				int x=n-i+1,y=m-j+1;
				if((i==x&&j==y)||vis[i][j]==stp)
					continue;
				if(i==x){
					vis[i][j]=vis[i][y]=stp;
					ans+=abs(a[i][j]-a[i][y]);
				}
				else if(j==y){
					vis[i][j]=vis[x][j]=stp;
					ans+=abs(a[i][j]-a[x][j]);
				}
				else{
					vis[i][j]=vis[i][y]=vis[x][j]=vis[x][y]=stp;
					v.clear(),v.push_back(a[i][j]),v.push_back(a[i][y]),v.push_back(a[x][j]),v.push_back(a[x][y]);
					sort(v.begin(),v.end());
					ans+=v[1]-v[0]+v[2]-v[1]+v[3]-v[1];
				}
			}
		printf("%lld\n",ans); 
	}
	return 0;
}