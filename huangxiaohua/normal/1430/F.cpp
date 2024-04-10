#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll f[2050][2050][2],l[2050],r[2050],a[2050],res,ans=5e18,len;

ll g(ll x){x%=m;if(!x){x=m;}return x;}

int main(){
	memset(f,-2,sizeof(f));
	scanf("%d%d",&n,&m);
	f[0][i][0]=f[0][i][1]=m;r[0]=-1;
	for(i=1;i<=n;i++){scanf("%lld%lld%lld",&l[i],&r[i],&a[i]);}
	for(i=1;i<=n;i++){
		len=r[i]-l[i];
		res+=(a[i]-g(a[i]))/m;
		for(k=0;k<i;k++){
			if(len&&(len-1)*m+f[i-1][k][0]>=a[i]){
				
				if(g(a[i])<=f[i-1][k][0]){
					f[i][k][0]=max(f[i-1][k][0]-g(a[i]),f[i][k][0]);
				}
				else{
					f[i][k+1][0]=max(f[i-1][k][0]+m-g(a[i]),f[i][k+1][0]);
				}
			}
			if(len*m+f[i-1][k][0]>=a[i]){
				if(g(a[i])<=f[i-1][k][0]){
					f[i][k][1]=max(f[i-1][k][0]-g(a[i]),f[i][k][1]);
				}
				else{
					f[i][k+1][1]=max(f[i-1][k][0]+m-g(a[i]),f[i][k+1][1]);
				}
			}
		}
		if(r[i]!=l[i+1]){
			for(j=0;j<=i;j++){
				if(f[i][j][1]>=0){
					f[i][j+1][0]=m;
				}
			}
		}

		for(j=0;j<=i;j++){
			if(f[i][j][0]>=0){
				f[i][j+1][0]=m;
			}
			f[i][j][0]=max(f[i][j][0],f[i][j][1]);
		}
	}
	for(i=0;i<=n;i++){
		if(f[n][i][0]>=0){
			ans=min(ans,(res+i+1)*m-f[n][i][0]);
		}
	}
	if(ans==5e18){
		puts("-1");
	}
	else{
		cout<<ans;
	}
}//