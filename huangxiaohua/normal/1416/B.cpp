#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,t,n,no;
ll a[10050],res1[10050],res2[10050],res3[10050],sum;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);sum=0;no=0;
		for(i=1;i<=n;i++){
			res1[i]=res2[i]=res3[i]=0;
			scanf("%lld",&a[i]);
			sum+=a[i];
		}
		if(sum%n){puts("-1");continue;}
		sum/=n;
		
		for(i=2;i<=n;i++){
			res1[i]=(i-a[i]%i)%i;
			a[1]-=res1[i];
			a[i]+=res1[i];
			res2[i]=a[i]/i;
		}
 
		
		printf("%d\n",n*3-3);
		for(i=2;i<=n;i++){
			printf("%d %d %lld\n",1,i,res1[i]);
			printf("%d %d %lld\n",i,1,res2[i]);
		}
		for(i=2;i<=n;i++){
			printf("%d %d %lld\n",1,i,sum);
		}
	}
}