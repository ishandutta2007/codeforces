#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007


int i,j,n,t;
ll res,p[66]={1},a[500500],l,r,tmp[66],sum[66],k;

int main(){
	//ios::sync_with_stdio(0);
	for(i=1;i<=61;i++){
		p[i]=p[i-1]*2%M;
	}
	
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		memset(sum,0,sizeof(sum));
		res=0;
		for(i=1;i<=n;i++){
			k=a[i];
			for(j=0;k;j++){
				sum[j]+=(k&1);
				k>>=1;
			}
		}
		//for(i=0;i<=30;i++){printf("%d ",sum[i]);}puts("");
		for(i=1;i<=n;i++){
			l=r=0;
			k=a[i];
			for(j=0;j<=60;j++){
				tmp[j]=(k&1);
				k>>=1;
			}
			for(j=0;j<=60;j++){
				if(tmp[j]){
					l=(l+p[j]*sum[j])%M;
					r=(r+p[j]*n)%M;
				}
				else{
					r=(r+p[j]*sum[j])%M;
				}
			}
			res=(res+l*r)%M;
		}
		printf("%lld\n",res);
	}
}