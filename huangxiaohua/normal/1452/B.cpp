#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,a[100500];
ll sum,sum2,res;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);sum=sum2=res=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);sum+=a[i];
		}
		sort(a+1,a+n+1);
		sum2=(ll)a[n]*(n-1);
		if(sum2>=sum){
			printf("%lld\n",sum2-sum+((n-1)-sum2%(n-1))%(n-1));
		}
		
		else{
			printf("%lld\n",((n-1)-sum%(n-1))%(n-1));
		}
	}
}