#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb[100500];
ll res;
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==2){
			printf("1\n2 1\n1\n2 1\n");continue;
		}
		if(n==3){
			printf("5\n2 3 1\n2\n1 3\n2 3\n");continue;
		}
		res=1ll*(n-1)*(n-1);
		for(i=2;i<n;i++){
			if(n-i>i-1){
				sb[i]=i+1;res+=1ll*(n-i)*(n-i);
			}
			else{
				res+=1ll*(1-i)*(1-i);
				if(sb[i-1]==i){sb[i-1]=1;sb[i]=n;}
				else{sb[i]=i-1;}
			}
		}
		sb[1]=n-1;sb[n]=2;
		printf("%lld\n",res);
		for(i=1;i<=n;i++){
			printf("%d ",sb[i]);
		}
		printf("\n%d\n",n-1);
		for(i=n-1;i>=n/2+1;i--){
			printf("%d %d\n",i,1);
		}
		for(i=2;i<n/2+1;i++){
			printf("%d %d\n",i,n);
		}
		printf("%d %d\n",1,n);
	}
}