#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,k,t,sum;
bool a[205];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		a[0]=1;sum=0;
		for(i=1;i<=n;i++){
			scanf("%d",&k);sum+=k;
			for(j=201;j-k>=0;j--){
				if(a[j-k]){a[j]=1;}
			}
		}
		/*for(i=1;i<=200;i++){
			printf("%d ",a[i]);
		}puts("");*/
		if((sum%2==0)&&a[sum/2]){puts("YES");}
		else{puts("NO");}
	}
}