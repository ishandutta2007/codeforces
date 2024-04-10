#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int i,j,k,m,t;
ll n,res,r2,c[300][300],a[300],pre;

int main(){
	c[0][0]=1;
	for(i=1;i<=30;i++){
		c[i][0]=1;
		for(j=1;j<=i;j++)c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		res=r2=1;m=0;pre=0;
		memset(a,0,sizeof(a));
		for(i=2;n;i++){
			m++;a[n%i]++;n/=i;
		}
		for(i=m;i>=1;i--){
			//printf("a%d %d\n",min(m,m+1-i)-pre,a[i]);
			res=res*c[min(m,m+1-i)-pre][a[i]];
			r2=r2*c[min(m-1,m-i)-pre][a[i]];
			pre+=a[i];
		}
		printf("%lld\n",res-r2-1);
	}
}