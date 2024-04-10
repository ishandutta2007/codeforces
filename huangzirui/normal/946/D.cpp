#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
const int maxn=505,inf=0x3f3f3f3f;
int n,m,k,ans=inf;
int a[maxn][maxn],f[maxn][maxn],g[maxn][maxn];
vector<int>b[maxn];
string s;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<m;j++)
			if(s[j]=='1')
				a[i][j+1]=1,b[i].push_back(j+1);
	}
	memset(f,0x3f,sizeof(f)),memset(g,0x3f,sizeof(g)),f[0][0]=0;
	for(int i=1;i<=n;i++){
		int t=(int)b[i].size();
		for(int j=0;j<=t;j++)
			for(int p=0;j+p<=t;p++){
				if(j+p==t)
					g[i][j+p]=0;
				else g[i][j+p]=min(g[i][j+p],b[i][t-p-1]-b[i][j]+1);
			}
		for(int j=0;j<=k;j++){
			if(b[i].size()==0){
				f[i][j]=f[i-1][j];
				continue;
			}
			f[i][j]=inf;
			for(int p=0;p<=j&&p<=t;p++)
				if(f[i-1][j-p]!=inf){
					if(p==t)
						f[i][j]=min(f[i][j],f[i-1][j-p]);
					else f[i][j]=min(f[i][j],f[i-1][j-p]+g[i][p]);
				}
		}
	}
	for(int i=0;i<=k;i++)
		ans=min(ans,f[n][i]);
	printf("%d\n",ans);
	return 0;
}