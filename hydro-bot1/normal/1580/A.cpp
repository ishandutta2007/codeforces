// Hydro submission #6183c6ac4d64c9b7688ef010@1636087435973
#include<bits/stdc++.h>
using namespace std;
const int N=409;
char s[N][N];
int p[N][N];
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,n,m,i,j,k,l,ans,now,tot;
	cin>>T;
	while(T--){
		cin>>n>>m,ans=20;
		for(i=1;i<=n;++i)cin>>(s[i]+1);
		for(i=1;i<=n;++i)for(j=1;j<=m;++j)p[i][j]=p[i][j-1]+(s[i][j]=='1');
		for(i=1;i<=n;++i)for(j=1;j<=m;++j){
			tot=0;
			for(k=j+1;k<m;++k){
				tot+=(s[i][k]=='0');
				if(tot>=ans)break;
				if(k>=j+2){
					now=tot;
					for(l=i+1;l<n;++l){
						now+=p[l][k]-p[l][j]+(s[l][j]=='0')+(s[l][k+1]=='0');
					if(now>=ans)break;
					if(l>=i+3)ans=min(ans,now+k-j-p[l+1][k]+p[l+1][j]);
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}