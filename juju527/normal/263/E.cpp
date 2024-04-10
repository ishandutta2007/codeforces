#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int maxn=1005,maxm=1005;
int n,m,k;
ll a[maxn][maxm],b[maxn][maxm],c[maxn][maxm];
ll s1[maxn][maxm],s2[maxn][maxm],s3[maxn][maxm],s4[maxn][maxm];
//s1:,s2:,s3:,s4: 
int c1[maxn][maxm],c2[maxn][maxm],c3[maxn][maxm],c4[maxn][maxm];
//c1:,c2:,c3:,c4: 
ll f[maxn][maxm];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
void solve(ll p[maxn][maxm]){
	memset(s1,0,sizeof(s1));memset(s2,0,sizeof(s2));memset(s3,0,sizeof(s3));memset(s4,0,sizeof(s4));
	memset(c1,0,sizeof(c1));memset(c2,0,sizeof(c2));memset(c3,0,sizeof(c3));memset(c4,0,sizeof(c4));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			s1[i][j]=s1[i-1][j]+p[i][j]-(i>k?p[i-k][j]:0);
			s2[i][j]=s2[i][j-1]+p[i][j]-(j>k?p[i][j-k]:0);
			s3[i][j]=s3[i-1][j+1]+p[i][j]-(i>k&&j<=m-k?p[i-k][j+k]:0);
			s4[i][j]=s4[i-1][j-1]+p[i][j]-(i>k&&j>k?p[i-k][j-k]:0);
		}
	}
	c1[k][k]=0;for(int i=1;i<=k;i++)for(int j=k-i+1;j<=k;j++)c1[k][k]+=p[i][j];
	c2[k][k]=0;for(int i=1;i<=k;i++)for(int j=k;j<=k+i-1;j++)c2[k][k]+=p[i][j];
	c3[k][k]=0;for(int i=k;i<=2*k-1;i++)for(int j=i-k+1;j<=k;j++)c3[k][k]+=p[i][j];
	c4[k][k]=0;for(int i=k;i<=2*k-1;i++)for(int j=k;j<=3*k-i-1;j++)c4[k][k]+=p[i][j];
	for(int i=k;i<=n-k+1;i++){
		if(i>k){
			c1[i][k]=c1[i-1][k]+s2[i][k]-s3[i-1][1];
			c2[i][k]=c2[i-1][k]+s2[i][2*k-1]-s4[i-1][2*k-1];
			c3[i][k]=c3[i-1][k]+s4[i+k-1][k]-s2[i-1][k];
			c4[i][k]=c4[i-1][k]+s3[i+k-1][k]-s2[i-1][2*k-1];
//			cout<<i<<" "<<k<<" "<<c1[i][k]<<" "<<c2[i][k]<<" "<<c3[i][k]<<" "<<c4[i][k]<<endl;
		}
		for(int j=k+1;j<=m-k+1;j++){
			c1[i][j]=c1[i][j-1]+s1[i][j]-s3[i][j-k];
			c2[i][j]=c2[i][j-1]+s4[i][j+k-1]-s1[i][j-1];
			c3[i][j]=c3[i][j-1]+s1[i+k-1][j]-s4[i+k-1][j-1];
			c4[i][j]=c4[i][j-1]+s3[i+k-1][j]-s1[i+k-1][j-1];
//			cout<<i<<" "<<j<<" "<<c1[i][j]<<" "<<c2[i][j]<<" "<<c3[i][j]<<" "<<c4[i][j]<<endl;
		}
	}
	return ;
}
signed main(){	
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){a[i][j]=read();b[i][j]=1ll*i*a[i][j];c[i][j]=1ll*j*a[i][j];}
//	for(int i=k;i<=n-k+1;i++){
//		for(int j=k;j<=m-k+1;j++){
//			ll sum1=0,sum2=0,sum3=0,sum=0;
//			for(int x=1;x<=n;x++){
//				for(int y=1;y<=m;y++){
//					int d=max(0,k-abs(i-x)-abs(j-y));
//					if(d==0)continue;
//					sum+=a[x][y]*d;
//				}
//			}
//			printf("%d %d %lld\n",i,j,sum);
//		}
//	}
	solve(a);
	for(int i=k;i<=n-k+1;i++){
		for(int j=k;j<=m-k+1;j++){
			ll v1=-i-j,v2=-i+j,v3=i-j,v4=i+j;
			f[i][j]+=1ll*k*(c1[i][j]+c2[i][j]+c3[i][j]+c4[i][j]-s1[i][j]-s2[i][j+k-1]-s2[i][j]-s1[i+k-1][j]+a[i][j]);
			f[i][j]+=v1*c1[i][j]+v2*c2[i][j]+v3*c3[i][j]+v4*c4[i][j];
			f[i][j]-=v1*s1[i][j]+v2*s2[i][j+k-1]+v3*s2[i][j]+v4*s1[i+k-1][j];
			f[i][j]+=v1*a[i][j];
		}
	}
	solve(b);
	for(int i=k;i<=n-k+1;i++){
		for(int j=k;j<=m-k+1;j++){
			ll v1=1,v2=1,v3=-1,v4=-1;
			f[i][j]+=v1*c1[i][j]+v2*c2[i][j]+v3*c3[i][j]+v4*c4[i][j];
			f[i][j]-=v1*s1[i][j]+v2*s2[i][j+k-1]+v3*s2[i][j]+v4*s1[i+k-1][j];
			f[i][j]+=v1*b[i][j];
		}
	}
	solve(c);
	ll sum=-1,x,y;
	for(int i=k;i<=n-k+1;i++){
		for(int j=k;j<=m-k+1;j++){
			ll v1=1,v2=-1,v3=1,v4=-1;
			f[i][j]+=v1*c1[i][j]+v2*c2[i][j]+v3*c3[i][j]+v4*c4[i][j];
			f[i][j]-=v1*s1[i][j]+v2*s2[i][j+k-1]+v3*s2[i][j]+v4*s1[i+k-1][j];
			f[i][j]+=v1*c[i][j];
			if(f[i][j]>sum)x=i,y=j,sum=f[i][j];
		}
	}
	printf("%lld %lld\n",x,y);
	return 0;
}