#include<bits/stdc++.h>
using namespace std;
#define N 105
#define pb push_back
#define ll long long
#define mod 998244353
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
int T,n,a[N],mn,yy,vst[N][N],x,y,i,j,ii,jj,m,b[N][N],c[N][N];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;++i){
			for(j=1;j<=m;++j){
				cin>>b[i][j];vst[i][j]=0;
			}
		}
		for(i=1;i<=m;++i){
			mn=2e9;
			for(ii=1;ii<=n;++ii){
				for(j=1;j<=m;++j){
					if(!vst[ii][j]&&b[ii][j]<mn){
						mn=b[ii][j],x=ii;y=j;
					}
				}
			}
			for(ii=1;ii<=n;++ii){
				if(ii==x)c[ii][i]=b[x][y],vst[x][y]=1;
				else{
					mn=0;
					for(jj=1;jj<=m;++jj){
						if(!vst[ii][jj]&&b[ii][jj]>mn){
							mn=b[ii][jj];
							yy=jj;
						}
					}
					c[ii][i]=b[ii][yy];
					vst[ii][yy]=1;
				}
			}
		}
		for(i=1;i<=n;cout<<"\n",++i)for(j=1;j<=m;++j)cout<<c[i][j]<<" ";
	}
}