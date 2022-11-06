#include<bits/stdc++.h>
using namespace std;
const int MN=5005;
char pfin[MN][MN],sfin[MN][MN];
int lcs[MN][MN];
int main(){
	//printf("%d\n",(sizeof(pfin)+sizeof(sfin)+sizeof(lcs))>>20);
	int t;
	cin>>t;
	while(t--){
		int n,m;string s,t;
		cin>>n>>m>>s>>t;
		int i,j;
		for(i=0;i<=n;++i)sfin[i][m]=1;
		for(j=0;j< m;++j)sfin[n][j]=0;
		for(i=n-1;i>=0;--i)
		for(j=m-1;j>=0;--j){
			if(s[i]==t[j])sfin[i][j]=sfin[i+1][j+1];
			else sfin[i][j]=sfin[i+1][j];
		}
		if(!sfin[0][0]){
			puts("-1");continue;
		}

		for(i=0;i<=n;++i)pfin[i][0]=1;
		for(j=1;j<=m;++j)pfin[0][j]=0;
		for(i=1;i<=n;++i)for(j=1;j<=m;++j){
			if(s[i-1]==t[j-1])pfin[i][j]=pfin[i-1][j-1];
			else pfin[i][j]=pfin[i-1][j];
		}
		
		
		for(i=0;i<=n;++i)lcs[i][m]=0;
		for(j=0;j< m;++j)lcs[n][j]=0;
		for(i=n-1;i>=0;--i)
		for(j=m-1;j>=0;--j){
			if(s[i]==t[j])lcs[i][j]=lcs[i+1][j+1]+1;
			else lcs[i][j]=0;
		}
		
		int ans1=n-lcs[0][0],ans2=998244353;

		for(i=0;i<=n;++i)for(j=0;j<=m;++j)if(pfin[i][j]&&sfin[i][j]){
			//printf("%d %d\n",i,j);
			int val=i-j-lcs[i][j];
			//printf("val=%d\n",val);
			if(val<ans2)ans2=val;
		}

		printf("%d\n",min(ans1,1+n+ans2));
	}
	return 0;
}