#include <cstdio>
#include <algorithm>
#define int long long

int n,f[101][101][2],ans;
void get(int l1,int l2,int s,int v){
	if(v<0)return;
	if(s<0)return;
	if(s==0){
		if(v==0)++ans;//,printf("%d %d %d %d %d\n",l1,l2,s,v,1);
		return;
	}
	f[0][0][0]=1;
	if(l1>l2)l1^=l2^=l1^=l2;
	if(l2<0){
		if(s==0)++ans;
		return;
	}
	if(v>=(1ll<<(l2+2)))return;
	for(int i=0;i<=l2;i++){
		for(int j=0;j<=s;j++)f[i+1][j][0]=f[i+1][j][1]=0;
		for(int j=0;j<=(i<=l1);j++)
			for(int k=0;k<2;k++){
				bool bb=(v&(1ll<<i));
				for(int l=0;l+j+k<=s;l++){
					if(j^k)
						if(bb)f[i+1][l+j+k][0]+=f[i][l][0];
						else  f[i+1][l+j+k][1]+=f[i][l][1];
					else if(j&&k)
						if(bb)f[i+1][l+j+k][1]+=f[i][l][1];
						else  f[i+1][l+j+k][1]+=f[i][l][0];
					else
						if(bb)f[i+1][l+j+k][0]+=f[i][l][1];
						else  f[i+1][l+j+k][0]+=f[i][l][0];
				}
			}
	}
//	printf("%d ",f[l2+1][2][1]);
//	printf("%d %d %d %d %d\n",l1,l2,s,v,f[std::max(l2,0ll)+1][s][(v&(1ll<<(l2+1)))?1:0]);
	ans+=f[std::max(l2,0ll)+1][s][(v&(1ll<<(l2+1)))?1:0];
}
signed main(){
	scanf("%lld",&n);
	for(int i=0;i<50;i++)
		for(int j=0;j<50;j++){
			int LCA=(n-(1ll<<(j))+1)/((1ll<<(i+1))+(1ll<<(j+1))-3),v=n-2*((1ll<<(i))+(1ll<<(j))-2)*(LCA-1)-LCA+2;
//			printf("%d %d %d %d\n",i,j,LCA,v);
			if(LCA>n||!LCA)break;
			for(int k=2;k<=i+j+2;k++){
				if((k+v)%2)continue;
				int tem=((k+v)>>1)-(1ll<<i)-(1ll<<j);
				if(j>0)tem-=(1ll<<(j-1));
				get(i-2,j-2,(j>0)?k-3:k-2,tem);
			}
		}
	printf("%lld",ans);
}