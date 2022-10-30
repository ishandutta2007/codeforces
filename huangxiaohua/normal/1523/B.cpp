#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[5050];

int main(){
	srand(time(0));
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		printf("%d\n",n*3);
		for(i=1;i<n;i+=2){
			j=i+1;
			printf("2 %d %d\n",i,j);
			printf("1 %d %d\n",i,j);
			printf("2 %d %d\n",i,j);
			printf("2 %d %d\n",i,j);
			printf("1 %d %d\n",i,j);
			printf("2 %d %d\n",i,j);
			a[j]-=a[i];
			a[i]+=a[j];
			a[j]-=a[i];
			a[j]-=a[i];
			a[i]+=a[j];
			a[j]-=a[i];
		}
	}
}